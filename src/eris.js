export class Eris {
	static {
		this.version = "1.0.0"
		this.author = "Nabir14"

		this.canvas = document.createElement('canvas')

		document.body.appendChild(this.canvas)

		Eris.resizeCanvas(window.innerWidth, window.innerHeight)
		
		window.addEventListener('resize', () => {
			Eris.resizeCanvas(window.innerWidth, window.innerHeight)
		});
	}
	
	static resizeCanvas(width, height) {
		this.canvas.width = width
		this.canvas.height = height
	}
}
