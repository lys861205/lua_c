local sdkEntry = require("luacallsdk");
if sdkEntry == nil then
	print("dll not regist to lua");
	return 10000, "dll not regist to lua";
end
--获取命令行参数
local url    = "https://api-dfserv.cloudentify.com";
local appId  = "F850B1B62B645DBD3084";
local appkey = "51979CD7C902B94B854BDBC88B8CD43BE05ABB6E";

local deli = ";";           --参数列表分隔符
local method = arg[1];      --测试函数名称
local params = arg[2];      --测试函数参数列表
local ONECOUNTPARAM=1;



function string.split(str, delimiter)
	local result = {} 
	if str==nil or str=='' or delimiter==nil then
		return result
	end
    for match in (str..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match)
    end
    return result
end
---
function lua_init()
	local init = sdkEntry.init;
	local ret, msg = init(url, appId, appkey);
	return ret, msg;
end 
---
function lua_uninit()
	local uninit = sdkEntry.uninit;
	uninit();
end
---
function lua_user_otp_auth(strParams)
end
---
function lua_is_user_exist(strParams)
end
---
function lua_add_user(strParams)
	local result = string.split(strParams, deli);
	--print(#result);  --表大小  table.getn(result);
	if #result < ONECOUNTPARAM then
		print("param is lesser");
		return 20000, "param is lesser";
	end 
	local ret, msg = lua_init();
	if ret ~= 0 then
		print(ret .. " " .. msg);
		return ret, msg;
	else 
		local addUser = sdkEntry.add_user;
		ret, msg = addUser(result[1]);
		print(ret .. " " .. msg);
		lua_uninit();
		return ret, msg;
	end
end
---
function lua_add_user_phone(strParams)
end
---
function lua_is_mobile_token_actived(strParams)
end


function lua_active_mobile_token(strParams)
end

function lua_add_user_phone(strParams)
end

function lua_push_auth(strParams)
	local result = string.split(strParams, deli);
	--print(#result);  --表大小  table.getn(result);
	if #result < ONECOUNTPARAM then
		print("param is lesser");
		return 20000, "param is lesser";
	end 
	local ret, msg = lua_init();
	if ret ~= 0 then
		print(ret .. " " .. msg);
		return ret, msg;
	else 
		local retry;
		local pushAuth = sdkEntry.push_auth;
		ret,msg,retry = pushAuth(result[1]);
		print(ret .. " " .. msg .. " " .. retry);
		lua_uninit();
		return ret, msg;
	end
end

function lua_get_qrcode(strParams)
end

function lua_scan_auth(strParams)
end

function lua_voice_auth(strParams)
end

function lua_get_wechat_token_ac(strParams)
end

function lua_get_face_regist_qrcode(strParams)
end

function lua_get_face_regist_result(strParams)
end

function lua_face_auth(strParams)
end

function lua_check_user(strParams)
end

function lua_user_otp_auth_by_mobile(strParams)
end

function lua_send_smsotp(strParams)
end

function lua_get_smsotp(strParams)
end

function lua_token_otp_auth(strParams)
end

function lua_bind_token(strParams)
end

function lua_unbind_token(strParams)
end

function lua_enable_token(strParams)
end

function lua_disable_token(strParams)
end

function lua_enable_user(strParams)
end

function lua_disable_user(strParams)
end

function lua_lock_token(strParams)
end

function lua_unlock_token(strParams)
end

function lua_lock_user(strParams)
end

function lua_unlock_user(strParams)
end

function lua_user_otp_sync(strParams)
end

function lua_token_otp_sync(strParams)
end

function lua_sync_ldap_users(strParams)
end

function lua_face_engine_regist(strParams)
end

function lua_face_engine_auth(strParams)
end

function lua_get_process_result(strParams)
end

--api名称--函数的映射表
local funTable = {["init"]=lua_init, 
				  ["uninit"]=lua_uninit, 
				  ["add_user"]=lua_add_user,
				  ["user_otp_auth"]  = lua_user_otp_auth,
				  ["is_user_exist"] = lua_is_user_exist,
				  ["add_user_phone"] = lua_add_user_phone,
				  ["is_mobile_token_actived"] = lua_is_mobile_token_actived,
				  ["active_mobile_token"] = lua_active_mobile_token,
				  ["push_auth"] = lua_push_auth,
				  ["get_qrcode"] = lua_get_qrcode,
				  ["scan_auth"] = lua_scan_auth,
				  ["voice_auth"] = lua_voice_auth,
				  ["get_wechat_token_ac"] = lua_get_wechat_token_ac,
				  ["get_face_regist_qrcode"] = lua_get_face_regist_qrcode,
				  ["get_face_regist_result"] = lua_get_face_regist_result,
				  ["face_auth"] = lua_face_auth,
				  ["check_user"] = lua_check_user,
				  ["user_otp_auth_by_mobile"] = lua_user_otp_auth_by_mobile,
				  ["send_smsotp"] = lua_send_smsotp,
				  ["get_smsotp"] = lua_get_smsotp,
				  ["token_otp_auth"] = lua_token_otp_auth,
				  ["bind_token"] = lua_bind_token,
				  ["unbind_token"] = lua_unbind_token,
				  ["enable_token"] = lua_enable_token,
				  ["disable_token"] = lua_disable_token,
				  ["enable_user"] = lua_enable_user,
				  ["disable_user"] = lua_disable_user,
				  ["lock_token"] = lua_lock_token,
				  ["unlock_token"] = lua_unlock_token,
				  ["lock_user"] = lua_lock_user,
				  ["unlock_user"] = lua_unlock_user,
				  ["user_otp_sync"] = lua_user_otp_sync,
				  ["token_otp_sync"] = lua_token_otp_sync,
				  ["sync_ldap_users"] = lua_sync_ldap_users,
				  ["face_engine_regist"] = lua_face_engine_regist,
				  ["face_engine_auth"] = lua_face_engine_auth,
				  ["get_process_result"] = lua_get_process_result};

function switch(c, p)
	if funTable[c] then
		funTable[c](p);
	end
end

--main function
switch(method, params);


