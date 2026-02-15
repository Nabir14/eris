export class Event {
    static {
        this.keyEvents = {}
        
        window.addEventListener("keydown", (event) => {
            Event.keyEvents[event.key] = true
        })
        window.addEventListener("keyup", (event) => {
            Event.keyEvents[event.key] = false
        })

    }
    static addCallback(callback){
        window.addEventListener("keydown", callback)
    }

    static isKeyPressed(key) {
        if (key in Event.keyEvents) {
            return Event.keyEvents[key]
        } else {
            return false
        }
    }
}