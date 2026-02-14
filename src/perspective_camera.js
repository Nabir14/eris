import { Camera, CameraType } from "./camera.js";

export class PerspectiveCamera extends Camera {
    constructor(fov) {
        super(CameraType.PERSPECTIVE)
        
        this.fov = fov
    }
}