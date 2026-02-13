import { vec3 } from './glMatrix/index.js'

export class EmptyObject {
	constructor() {
		this.position = vec3.fromValues(0.0, 0.0, 0.0)
		this.rotation = vec3.fromValues(0.0, 0.0, 0.0)
		this.scale = vec3.fromValues(1.0, 1.0, 1.0)
	}
	_processDefault() {}
	onLoad() {}
	onUpdate(deltaTime) {}
	onDraw(deltaTime) {}
}
