
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
print('==================test const table==================')
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
-- print(table.maxn(ct))
-- print(table.maxn(mt))
-- print(table.maxn(_M))
-- print(#ct)
-- print(#mt)
-- print(#_M)
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

print('==================test weak table==================')
-- weak table: wt is weak table
local wt = setmetatable({}, {__mode="v"})
local obj1 = {id=1 , name="hero1"}
local obj2 = {id=2 , name="hero2"}
wt[obj1.id] = obj1
wt[obj2.id] = obj2
obj1 = nil
obj2 = nil
collectgarbage()
for k, v in ipairs(wt) do
  print(v)
end

local kwt = setmetatable({}, {__mode="k"})
local v1 = {id=3 , name="hero3"}
local v2 = {id=4 , name="hero4"}
kwt[v1] = 3
kwt[v2] = 4
v1 = nil
v2 = nil
collectgarbage()
for k, v in ipairs(kwt) do
  print(v)
end



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


print('==================== test escape function =================')

function lua_escape(attr)
  local escape_tb = {
  ['&'] = '&amp;',
  ['"'] = '&quot;',
  ['<'] = '&lt;',
  ['>'] = '&gt;',
  }
  attr = string.gsub(attr, '[&"<>]', escape_tb)
  return attr
end

print(lua_escape([[<html>"hello"&"world"</html>]]))
print(lua_escape('&'))
print(lua_escape('"'))
print(lua_escape('<'))
print(lua_escape('>'))
for k, v in pairs(arg) do
  print("k " .. k .. " v " .. v)
end


t = {["day"]=02, ["year"]=2019, ["month"]=8, ["hour"]=15, ["min"]=7, ["sec"]=10}
now = os.time(t)
print(now)
print(math.pi)








