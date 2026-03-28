local ts=game:GetService("TeleportService") local p=game.Players.LocalPlayer
local g=Instance.new("ScreenGui",p.PlayerGui) local f=Instance.new("Frame",g)
f.Size=UDim2.new(1,0,1,0) f.BackgroundColor3=Color3.new(0,0,0)
local t=Instance.new("TextLabel",f) t.Size=UDim2.new(1,0,1,0) t.BackgroundTransparency=1
t.Text="Loading..." t.TextColor3=Color3.new(1,1,1) t.TextScaled=true
ts:TeleportToPrivateServer(game.PlaceId,"d7a9a0c51141954a891b1184c7038e09",{p})
