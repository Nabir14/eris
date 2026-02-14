import { MeshTemplate } from "./templates/mesh_template";

export class TriangleMesh extends MeshTemplate {
	constructor() {
		super(new Float32Array([
			-0.5, -0.5, 0.,
			 0.5, -0.5, 0.,
			 0.0,  0.5, 0.
		]))
	}
}
