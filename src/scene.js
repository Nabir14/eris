import { Renderer } from './renderer.js'
import { Color } from './types/color.js'

export class Scene {
	constructor() {
		this.clearColor = new Color(0, 0, 0, 1)
		this.activeCamera = null
		this.objects = []
		this.totalVertexCount = 0
	}

	setClearColor(color) {
		this.clearColor = color
	}

	setActiveCamera(camera) {
		this.activeCamera = camera
	}

	addObjects(objects_array) {
		this.objects.push(...objects_array)
	}
	
	_processDefault() {
		for (const object of this.objects) {
			if (typeof object.onLoad === 'function') { object.onLoad() }
			
			const material = object.material
			const mesh = object.mesh

			if (material && mesh) {
				this.totalVertexCount += mesh.vertices.length / 3
			}
		}
	}

	onLoad() {}
	onUpdate(deltaTime) {}
	onDraw(deltaTime) {}
}
