import { Renderer } from './renderer.js'
import { Color } from './types/color.js'

export class Scene {
	constructor() {
		this.gl = Renderer.context
		this.clearColor = new Color(0, 0, 0, 1)
	}

	setClearColor(color) {
		this.clearColor = color
	}

	_processDefault() {
		this.gl.clearColor(
			this.clearColor.r,
			this.clearColor.g,
			this.clearColor.b,
			this.clearColor.a
		)
		this.gl.clear(this.gl.COLOR_BUFFER_BIT)
	}

	onDraw() {}
}
