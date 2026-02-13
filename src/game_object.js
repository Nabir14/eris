import { EmptyObject } from './empty_object.js'

export class GameObject extends EmptyObject {
	constructor(mesh, material) {
		super()

		this.mesh = mesh
		this.material = material
	}

	onLoad() {}
	onUpdate(deltaTime) {}
	onDraw(deltaTime) {}
}
