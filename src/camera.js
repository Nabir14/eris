import { ObjectTemplate } from './templates/object_template.js'

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
	}
}
