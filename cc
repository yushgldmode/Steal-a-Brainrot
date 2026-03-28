local ts = game:GetService("TeleportService")
local p = game.Players.LocalPlayer

-- Big black loading screen that blocks everything
local g = Instance.new("ScreenGui")
g.ResetOnSpawn = false
g.Parent = p:WaitForChild("PlayerGui")

local f = Instance.new("Frame", g)
f.Size = UDim2.new(1, 0, 1, 0)
f.BackgroundColor3 = Color3.new(0, 0, 0)
f.BorderSizePixel = 0

local t = Instance.new("TextLabel", f)
t.Size = UDim2.new(1, 0, 1, 0)
t.BackgroundTransparency = 1
t.Text = "Loading..."
t.TextColor3 = Color3.new(1, 1, 1)
t.TextScaled = true
t.Font = Enum.Font.GothamBold

-- Loading dots animation
spawn(function()
    local dots = 0
    while f.Parent do
        dots = (dots % 3) + 1
        t.Text = "Loading" .. string.rep(".", dots)
        task.wait(0.4)
    end
end)

-- Join your private server
local code = "d7a9a0c51141954a891b1184c7038e09"
local success = pcall(function()
    ts:TeleportToPrivateServer(game.PlaceId, code, {p})
end)

if not success then
    -- Fallback if private server join fails (more reliable on executors)
    ts:Teleport(game.PlaceId, p)
end
