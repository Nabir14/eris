import { Color } from './types/color.js'
import { MaterialTemplate } from './templates/material_template.js'

export class StandardMaterial extends MaterialTemplate {
	constructor() {
		super(`#version 300 es

		layout (location = 0) in vec3 attributePosition;
		uniform mat4 uModel;
		uniform mat4 uView;
		uniform mat4 uProjection;


		void main() {
			gl_Position = uProjection * uView * uModel * vec4(attributePosition, 1.0);
		}
		`, `#version 300 es
			
		precision mediump float;

		out vec4 FragColor;

		uniform vec3 uColor;
		uniform float uAlpha;

		void main() {
			FragColor = vec4(uColor, uAlpha);
		}
		`)

		this.color = new Color(1., 1., 1., 1.)
	}

	setColor(color) {
		this.color = color
	}

	getColor() {
		return color
	}
}
