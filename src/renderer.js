import { Eris } from './eris.js'
import { ErisConsole } from './utils/eris_console.js'

export class Renderer {
	static {
		this.context = Eris.canvas.getContext('webgl2')
		this.deltaTime = 0.
		
		if (!this.context) {
			ErisConsole.error("Unable To Get WebGL2 Context -> (Renderer)")
		}
	}

	static render(scene) {
		Renderer.context.viewport(0, 0, Renderer.context.canvas.width, Renderer.context.canvas.height)
		
		if (typeof scene.onLoad === 'function') { scene.onLoad() }

		scene._processDefault()
		
		let previousFrameTime = 0
		
		const renderLoop = (currentFrameTime) => {
			this.deltaTime = currentFrameTime - previousFrameTime
			previousFrameTime = currentFrameTime

			if (typeof scene.onUpdate === 'function') { scene.onUpdate(this.deltaTime) }

			Renderer.context.clearColor(
				scene.clearColor.r,
				scene.clearColor.g,
				scene.clearColor.b,
				scene.clearColor.a
			)
			
			Renderer.context.clear(Renderer.context.COLOR_BUFFER_BIT)
			
			if (typeof scene.onDraw === 'function') { scene.onDraw(this.deltaTime) }

			for (const object of scene.objects) {
				const mesh = object.mesh
				const material = object.material

				if (typeof object.onUpdate === 'function') { object.onUpdate(this.deltaTime) }

				if (mesh && material) {
					if (typeof object.onDraw === 'function') { object.onDraw(this.deltaTime) }
					
					Renderer.context.useProgram(material.shaderProgram)
					Renderer.context.bindVertexArray(mesh.vao)
					Renderer.context.drawArrays(Renderer.context.TRIANGLES, 0, scene.totalVertexCount)
				}
			}
	
			requestAnimationFrame(renderLoop)
		}
		
		requestAnimationFrame(renderLoop)
	}
}
