import { Renderer } from "../renderer.js"

export class MeshTemplate {
	constructor(vertices) {
		this.vertices = vertices
		
		this.vao = Renderer.context.createVertexArray()
		this.vbo = Renderer.context.createBuffer()
		
		Renderer.context.bindVertexArray(this.vao)

		Renderer.context.bindBuffer(Renderer.context.ARRAY_BUFFER, this.vbo)
		Renderer.context.bufferData(
			Renderer.context.ARRAY_BUFFER,
			this.vertices,
			Renderer.context.STATIC_DRAW
		)

		Renderer.context.enableVertexAttribArray(0)
		Renderer.context.vertexAttribPointer(0, 3, Renderer.context.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0)
	}
}
