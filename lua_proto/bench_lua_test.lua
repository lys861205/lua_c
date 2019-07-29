
local start = os.clock()

for i=0, 1000000 do
  --print(i)
  io.write('\r' .. i)
end
print()

print("espace " .. os.clock()-start)
