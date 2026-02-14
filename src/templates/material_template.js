import { Renderer } from './renderer.js'
import { ErisConsole } from './utils/eris_console.js'

export class MaterialTemplate {
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

	getParameter(parameter) {
		return Renderer.context.getUniform(this.shaderProgram, parameter)
	}
}