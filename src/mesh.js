export class EmptyMesh {
	constructor() {
		this.vertices = []
	}
}

export class TriangleMesh extends EmptyMesh {
	constructor() {
		super()

		this.vertices = new Float32Array([
			-0.5, -0.5, 0.,
			 0.5, -0.5, 0.,
			 0.5,  0.5, 0.
		])
	}
}
