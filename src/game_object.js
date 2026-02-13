import { vec3 } from './glMatrix/index.js'
import { EmptyObject } from './empty_object.js'

export class GameObject extends EmptyObject {
	constructor(mesh, material) {
		super()

		this.position = vec3.create(0., 0., 0.)
		this.rotation = vec3.create(0., 0., 0.)
		this.transform = vec3.create(0., 0., 0.)
		this.mesh = mesh
		this.material = material
	}

	onLoad() {}
	onUpdate(deltaTime) {}
	onDraw(deltaTime) {}
}
