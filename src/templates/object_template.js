import { vec3 } from '../glMatrix/index.js'
import { ScriptTemplate } from './script_template.js'

export class ObjectTemplate extends ScriptTemplate {
	constructor() {
		super()

		this.position = vec3.fromValues(0.0, 0.0, 0.0)
		this.rotation = vec3.fromValues(0.0, 0.0, 0.0)
		this.scale = vec3.fromValues(1.0, 1.0, 1.0)
	}
}
