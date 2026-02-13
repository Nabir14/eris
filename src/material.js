import { Renderer } from './renderer.js'
import { ErisConsole } from './utils/eris_console.js'

export class EmptyMaterial {
	constructor(vertexShaderSource, fragmentShaderSource) {
		this.shaderProgram = Renderer.context.createProgram()
		
		let vertexShader = Renderer.context.createShader(Renderer.context.VERTEX_SHADER)
		let fragmentShader = Renderer.context.createShader(Renderer.context.FRAGMENT_SHADER)

		Renderer.context.shaderSource(vertexShader, vertexShaderSource)
		Renderer.context.shaderSource(fragmentShader, fragmentShaderSource)
		
		Renderer.context.compileShader(vertexShader)
		Renderer.context.compileShader(fragmentShader)

		if(!Renderer.context.getShaderParameter(vertexShader, Renderer.context.COMPILE_STATUS)) {
			ErisConsole.warn(Renderer.context.getShaderInfoLog(vertexShader))
		}

		if(!Renderer.context.getShaderParameter(fragmentShader, Renderer.context.COMPILE_STATUS)) {
			ErisConsole.warn(Renderer.context.getShaderInfoLog(fragmentShader))
		}
		
		Renderer.context.attachShader(this.shaderProgram, vertexShader)
		Renderer.context.attachShader(this.shaderProgram, fragmentShader)
		Renderer.context.linkProgram(this.shaderProgram)

		if (!Renderer.context.getProgramParameter(this.shaderProgram, Renderer.context.LINK_STATUS)) {
			ErisConsole.warn(Renderer.context.getProgramInfoLog(this.shaderProgram))
		}
	}
}

export class StandardMaterial extends EmptyMaterial {
	constructor() {
		super(`#version 300 es

		layout (location = 0) in vec3 attributePosition;

		void main() {
			gl_Position = vec4(attributePosition, 1.0);
		}
		`, `#version 300 es
			
		precision mediump float;
		
		out vec4 FragColor;

		void main() {
			FragColor = vec4(1.0, 1.0, 1.0, 1.0);
		}
		`)	
	}
}
