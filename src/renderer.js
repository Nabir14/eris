import { Eris } from './eris.js'
import { ErisConsole } from './utils/eris_console.js'

export class Renderer {
	static start() {
		this.context = Eris.canvas.getContext('webgl2')
		this.deltaTime = 0.
		
		if (!this.context) {
			ErisConsole.error("Unable To Get WebGL2 Context -> (Renderer)")
		}
	}

	static render(scene) {
		Renderer.context.viewport(0, 0, Renderer.context.canvas.width, Renderer.context.canvas.height)
		
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

			for (const index in scene.objects) {
				const object = scene.objects[index]
				const mesh = object.mesh
				const material = object.material
			
				if (typeof object.onUpdate === 'function') { object.onUpdate(this.deltaTime) }

				if (mesh && material) {
					if (typeof object.onDraw === 'function') { object.onDraw(this.deltaTime) }
					
					Renderer.context.useProgram(material.shaderProgram)
					
					const vao = Renderer.context.createVertexArray()
					Renderer.context.bindVertexArray(vao)
				
					const buffer = Renderer.context.createBuffer()
					Renderer.context.bindBuffer(Renderer.context.ARRAY_BUFFER, buffer)
					
					Renderer.context.bufferData(
						Renderer.context.ARRAY_BUFFER,
						mesh.vertices,
						Renderer.context.STATIC_DRAW
					)
	
					Renderer.context.enableVertexAttribArray(0)
				
					Renderer.context.vertexAttribPointer(0, 3, Renderer.context.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0)
					
					Renderer.context.drawArrays(Renderer.context.TRIANGLES, 0, mesh.vertices.length / 3)
				}
			}
	
			requestAnimationFrame(renderLoop)
		}
		
		requestAnimationFrame(renderLoop)
	}
}
