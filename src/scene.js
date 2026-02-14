import { ScriptTemplate } from './templates/script_template.js'
import { Color } from './types/color.js'

export class Scene extends ScriptTemplate {
	constructor() {
		this.clearColor = new Color(0, 0, 0, 1)
		this.activeCamera = null
		this.objects = []
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
		}
	}

	onLoad() {}
	onUpdate(deltaTime) {}
	onDraw(deltaTime) {}
}
