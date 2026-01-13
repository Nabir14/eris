draw_value = "draw"

function Load()
    print("loaded")
end

function Update()
    if Eris_CheckWindowEvent("CLOSE") then
        Eris_QuitGame()
    else
        print("update")
    end
end

function Draw()
    print(draw_value)
end