import { Renderer } from './renderer.js'
import { Color } from './types/color.js'

export class Scene {
	constructor() {
		this.clearColor = new Color(0, 0, 0, 1)
		this.activeCamera = null
		this.objects = []
		this.triangleCount = 0
	}

	setClearColor(color) {
		this.clearColor = color
	}

	setActiveCamera(camera) {
		this.activeCamera = camera
	}

	addObjects(objects_array) {
		this.objects.push(objects_array)
	}
	
	_processDefault() {
		for (const index in this.objects) {
			const object = this.objects[index]
			const material = object.material
			const mesh = object.mesh

			if (material && mesh) {
				this.triangleCount += mesh.vertices.length
			}
		}
	}

	onLoad() {}
	onUpdate(deltaTime) {}
	onDraw(deltaTime) {}
}
