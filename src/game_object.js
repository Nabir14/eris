import { ObjectTemplate } from './templates/object_template.js'

export class GameObject extends ObjectTemplate {
	constructor(mesh, material) {
		super()

		this.mesh = mesh
		this.material = material
	}
}
