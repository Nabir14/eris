import { vec3 } from './glMatrix/index.js'
import { ObjectTemplate } from './templates/object_template.js'
import { Renderer } from './renderer.js'

export class Camera extends ObjectTemplate {
	constructor() {
		this.position = new vec3(0., 0., 0.)
		this.renderDistance = 1000.
		this.near = .1
		this.fov = 65.
	}

	_processDefault() {
		const projectionMatrix = mat4.create()
		const modelViewMatrix = mat4.create()
		const aspect = Renderer.context.canvas.clientWidth / Renderer.context.canvas.clientHeight

		mat4.perspective(projectionMatrix, this.fov, aspect, this.near, this.renderDistance, this.near)

		mat4.translate(
			modelViewMatrix, // destination matrix
			modelViewMatrix, // matrix to translate
			[-0.0, 0.0, -6.0],
		)
	}
}
