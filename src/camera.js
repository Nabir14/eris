import { ObjectTemplate } from './templates/object_template.js'
import { vec3, glMatrix } from './glMatrix/index.js'

export const CameraType = Object.freeze({
	ORTHOGRAPHIC: 0,
	PERSPECTIVE: 1
})

export class Camera extends ObjectTemplate {
	constructor(cameraType) {
		super()

		this.type = cameraType
		this.renderDistance = 1000.
		this.near = .1
		this.target = vec3.fromValues(0., 0., 0.)
		this.forwardDirection = vec3.fromValues(0., 0., -1.)
		this.upDirection = vec3.fromValues(0., 1., 0.)
	}

	_processDefault() {
		/*
		let cameraLookDir = vec3.create()
		let rightDir = vec3.create()

		vec3.normalize(cameraLookDir, vec3.subtract(cameraLookDir, this.position, this.target))
		vec3.normalize(rightDir, vec3.cross(rightDir, vec3.fromValues(0., 1., 0.), cameraLookDir))
		vec3.cross(this.upDirection, cameraLookDir, rightDir)
		*/
		
		this.forwardDirection[2] = -Math.cos(glMatrix.toRadian(this.rotation[1])) * Math.cos(glMatrix.toRadian(this.rotation[0]))
		this.forwardDirection[1] = Math.sin(glMatrix.toRadian(this.rotation[0]))
		this.forwardDirection[0] = Math.sin(glMatrix.toRadian(this.rotation[1])) * Math.cos(glMatrix.toRadian(this.rotation[0]))

		vec3.normalize(this.forwardDirection, this.forwardDirection)
	}
}
