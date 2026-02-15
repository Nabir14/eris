// Systems
import { Eris } from "./eris.js"
import { Renderer } from "./renderer.js"
import { Event } from "./event.js"

// Templates
import { ScriptTemplate } from "./templates/script_template.js"
import { ObjectTemplate } from "./templates/object_template.js"
import { MeshTemplate } from "./templates/mesh_template.js"
import { MaterialTemplate } from "./templates/material_template.js"

// Top-level Container
import { Scene } from "./scene.js"

// Components
import { TriangleMesh, PlaneMesh } from "./mesh.js"
import { StandardMaterial } from "./material.js"
import { Color } from "./types/color.js"

// Entities
import { GameObject } from "./game_object.js"
import { Camera } from "./camera.js"
import { OrthographicCamera } from "./orthographic_camera.js"
import { PerspectiveCamera } from "./perspective_camera.js"

// Others
import { ErisConsole } from "./utils/eris_console.js"

export { 
    Eris,
    Renderer,
    Event,
    ScriptTemplate,
    ObjectTemplate,
    MeshTemplate,
    MaterialTemplate,
    Scene,
    TriangleMesh,
    PlaneMesh,
    Color, 
    StandardMaterial,
    GameObject, 
    Camera,
    OrthographicCamera,
    PerspectiveCamera,
    ErisConsole
}