export class Eris {
	static {
		this.version = "1.0.0"
		this.author = "Nabir14"
		this.canvasWidth = window.innerWidth
		this.canvasHeight = window.innerHeight

		this.canvas = document.createElement('canvas')

		document.body.appendChild(this.canvas)
		
		this.canvas.width = this.canvasWidth
		this.canvas.height = this.canvasHeight
	}
	
	static resizeCanvas(width, height) {
		this.canvas.width = width
		this.canvas.height = height
	}
}
