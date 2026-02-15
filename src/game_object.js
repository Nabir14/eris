import { ObjectTemplate } from './templates/object_template.js'
import { CameraType } from './camera.js'
import { ErisConsole } from './utils/eris_console.js'
import { glMatrix, mat4, vec3 } from './glMatrix/index.js'
import { Renderer } from './renderer.js'

export class GameObject extends ObjectTemplate {
	constructor(scene, mesh, material) {
		super(scene)

		this.mesh = mesh
		this.material = material
	}

	_processDefault() {
		Renderer.context.useProgram(this.material.shaderProgram)

		let model = mat4.create()
		let view = mat4.create()
		let projection = mat4.create()
		
		mat4.translate(model, model, this.position)
		mat4.rotateX(model, model, glMatrix.toRadian(this.rotation[0]))
		mat4.rotateY(model, model, glMatrix.toRadian(this.rotation[1]))
		mat4.rotateZ(model, model, glMatrix.toRadian(this.rotation[2]))
		mat4.scale(model, model, this.scale)

		const camera = this.parentScene.getActiveCamera()
		
		let lookDir = vec3.create()
		vec3.add(lookDir, camera.position, camera.forwardDirection)

		mat4.lookAt(view, camera.position, lookDir, camera.upDirection)
		
		switch(camera.type) {
			case CameraType.ORTHOGRAPHIC:
				mat4.ortho(projection, 0, camera.width, 0, camera.height,  camera.near, camera.renderDistance)
				break
			case CameraType.PERSPECTIVE:
				mat4.perspective(projection, glMatrix.toRadian(camera.fov), Renderer.context.canvas.width / Renderer.context.canvas.height, camera.near, camera.renderDistance)
				break
			default:
				ErisConsole.error("Unkown Camera Type -> (GameObject)")
		}

		Renderer.context.uniformMatrix4fv(
			Renderer.context.getUniformLocation(this.material.shaderProgram, "uModel"),
			false,
			model
		)

		Renderer.context.uniformMatrix4fv(
			Renderer.context.getUniformLocation(this.material.shaderProgram, "uView"),
			false,
			view
		)

		Renderer.context.uniformMatrix4fv(
			Renderer.context.getUniformLocation(this.material.shaderProgram, "uProjection"),
			false,
			projection
		)
		
		if (this.material.color) {
			Renderer.context.uniform3fv(
				Renderer.context.getUniformLocation(this.material.shaderProgram, "uColor"),
				new Float32Array([
					this.material.color.r,
					this.material.color.g,
					this.material.color.b,
				])
			)

			Renderer.context.uniform1f(
				Renderer.context.getUniformLocation(this.material.shaderProgram, "uAlpha"),
				this.material.color.a
			)
		}
	}
}
