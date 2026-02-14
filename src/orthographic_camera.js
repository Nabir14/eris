import { Camera, CameraType } from "./camera.js";

export class OrthographicCamera extends Camera {
    constructor(width, height) {
        super(CameraType.ORTHOGRAPHIC)

        this.width = width
        this.height = height
    }
}