import { Eris } from './eris.js'
import { ErisConsole } from './utils/eris_console.js'

export class Renderer {
	static start() {
		this.context = Eris.canvas.getContext('webgl')
		this.deltaTime = 0.
		
		if (!this.context) {
			ErisConsole.error("Unable To Get WebGL Context -> (Renderer)")
		}
	}

	static render(scene) {
		let previousFrameTime = 0
		
		const renderLoop = (currentFrameTime) => {
			this.deltaTime = currentFrameTime - previousFrameTime
			previousFrameTime = currentFrameTime

			scene._processDefault()
			scene.onDraw(this.deltaTime)

			requestAnimationFrame(renderLoop)
		}
		
		requestAnimationFrame(renderLoop)
	}
}
