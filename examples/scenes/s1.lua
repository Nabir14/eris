function Load()
    shouldCheckEvent = true
    value_s = "hey"
    value_n = 3215
    value_draw = "draw"
    print("loaded")
    return shouldCheckEvent, value_s, value_n, value_draw
end

function Update(globals)
    print(globals[2])
    print(globals[3])
    print("update")
end

function Draw(globals)
    print(globals[4])
end