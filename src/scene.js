import { ScriptTemplate } from './templates/script_template.js'
import { Color } from './types/color.js'
import { Event } from './event.js'

export class Scene extends ScriptTemplate {
	constructor() {
		super()
		
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

	getActiveCamera() {
		return this.activeCamera
	}

	addObjects(objects_array) {
		this.objects.push(...objects_array)
	}
	
	_processDefault() {
		this.onLoad()
		Event.addCallback((event) => this.onEvent(event))

		for (const object of this.objects) {
			if (typeof object.onLoad === 'function') { object.onLoad() }
			if (typeof object.onEvent === 'function') { Event.addCallback((event) => object.onEvent(event)) }
		}
	}
}
