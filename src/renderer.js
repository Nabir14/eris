import { Eris } from './eris.js'
import { ErisConsole } from './utils/eris_console.js'
import { glMatrix, mat4 } from './glMatrix/index.js'

export class Renderer {
	static {
		this.context = Eris.canvas.getContext('webgl2')
		this.deltaTime = 0.
		
		if (!this.context) {
			ErisConsole.error("Unable To Get WebGL2 Context -> (Renderer)")
		}
	}

	static render(scene) {
		Renderer.context.viewport(0, 0, Renderer.context.canvas.width, Renderer.context.canvas.height)
		
		if (typeof scene.onLoad === 'function') { scene.onLoad() }

		scene._processDefault()
		
		let previousFrameTime = 0
		
		const renderLoop = (currentFrameTime) => {
			this.deltaTime = currentFrameTime - previousFrameTime
			previousFrameTime = currentFrameTime

			if (typeof scene.onUpdate === 'function') { scene.onUpdate(this.deltaTime) }

			Renderer.context.clearColor(
				scene.clearColor.r,
				scene.clearColor.g,
				scene.clearColor.b,
				scene.clearColor.a
			)
			
			Renderer.context.clear(Renderer.context.COLOR_BUFFER_BIT)
			
			if (typeof scene.onDraw === 'function') { scene.onDraw(this.deltaTime) }

			for (const object of scene.objects) {
				const mesh = object.mesh
				const material = object.material

				if (typeof object.onUpdate === 'function') { object.onUpdate(this.deltaTime) }

				if (mesh && material) {
					if (typeof object.onDraw === 'function') { object.onDraw(this.deltaTime) }

					Renderer.context.useProgram(material.shaderProgram)

					let transform = mat4.create()
					mat4.translate(transform, transform, object.position)
					mat4.rotateX(transform, transform, glMatrix.toRadian(object.rotation[0]))
					mat4.rotateY(transform, transform, glMatrix.toRadian(object.rotation[1]))
					mat4.rotateZ(transform, transform, glMatrix.toRadian(object.rotation[2]))
					mat4.scale(transform, transform, object.scale)

					Renderer.context.uniformMatrix4fv(
						Renderer.context.getUniformLocation(material.shaderProgram, "uTransform"),
						false,
						transform
					)

					Renderer.context.bindVertexArray(mesh.vao)
					Renderer.context.drawArrays(Renderer.context.TRIANGLES, 0, mesh.vertices.length / 3)
				}
			}
	
			requestAnimationFrame(renderLoop)
		}
		
		requestAnimationFrame(renderLoop)
	}
}
