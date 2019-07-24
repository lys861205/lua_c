
local pb = require("proto.lua")
if pb == nil then
  print("require protolua failed.\n")
end
print("start...")
pb.create(nil)

function decodeObject(data)
  -- print(pb.get_name(data))
  -- print(pb.get_sex(data))
  -- print(pb.get_age(data))
  -- pb.set_name(data, "xxxxx")
  -- pb.set_sex(data, "renyao")
  -- pb.set_age(data, 100)
  return data
end

function decodeBytes(data)
  local user = pb.create(data)
  print(type(user))
  print(user:get_name())
  print(user:get_sex())
  print(user:get_age())
end


