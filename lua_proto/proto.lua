
local pb = require("proto.lua")
if pb == nil then
  print("require protolua failed.\n")
end

print(type(pb))

for k, v in pairs(pb) do
  print(k)
end

local mt = {__index=pb}


function decodeObject(data)
  local user = pb.createFromObject(data)
  print(user:get_name(data))
  print(user:get_sex(data))
  print(user:get_age(data))
  user:set_name("xxxxx")
  user:set_sex("renyao")
  user:set_age(100)
  return data
end

function decodeBytes(data)
  local user = pb.createFromBytes(data)
  print(user:get_name())
  print(user:get_sex())
  print(user:get_age())
  pb.releaseBytes(user)
end

