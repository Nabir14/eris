import { ObjectTemplate } from './templates/object_template.js'
import { vec3 } from './glMatrix/index.js'

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
	}

	_processDefault() {
		let dir = vec3.create()
		let cameraUpDir = vec3.create()
		let rightDir = vec3.create()

		vec3.normalize(dir, this.position - this.target)
		vec3.normalize(rightDir, vec3.cross(rightDir, vec3.fromValues(0., 1., 0.), dir))
		vec3.cross(cameraUpDir, dir, rightDir)
	}
}
