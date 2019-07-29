
local pb = require("proto.lua")
if pb == nil then
  print("require protolua failed.\n")
end

-- print(type(pb))
--
-- for k, v in pairs(pb) do
--   print(k)
-- end
--
local newindex_func = function() error("this is const table, don`t insert element") end

local _M = {k="hello"}
--local mt = {__index=_M, __newindex=function() error("Forbid insert element to table") end}
local mt = { __index = _M,
             __newindex = newindex_func,
             __gc = nil
           }

function _M.test(self,a)
  self.k = a;
  print("function")
end

-- 这是只读表
local ct = setmetatable({}, mt)
print(table.maxn(ct))
print(table.maxn(mt))
print(table.maxn(_M))
print(#ct)
print(#mt)
print(#_M)
for k, v in pairs(mt) do
  print(type(k) .. " " .. type(v))
  if type(v) == 'function' then
    print(k)
  else
    print(k)
  end
end
print(ct.k)
--ct:test("lua")
print(ct.key)


function call_c_function(f)
  print(f("call from lua to c"))
end

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

function coroutine_test(x)
  print(type(x))
  print("co is running")
  local a, b = coroutine.yield(10, x)
  print("co is runner")
end

