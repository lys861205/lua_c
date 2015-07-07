
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
--local method = arg[1];      --测试函数名称
--local params = arg[2];      --测试函数参数列表
local ONECOUNTPARAM=1;

retResult = {["code"]=0,["description"]="",["qrCode"]="", ["retry"]=0,["activeCode"]=""};

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
		retResult["code"] = ret;
		retResult["description"] = msg;
		return retResult;
	else 
		local addUser = sdkEntry.add_user;
		ret, msg = addUser(result[1]);
		retResult["code"] = ret;
		retResult["description"] = msg;
		lua_uninit();
		return retResult;
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
		retResult["code"] = 20000;
		retResult["description"] = "param is lesser";
	else 
		local ret, msg = lua_init();
		if ret ~= 0 then
			retResult["code"] = ret;
			retResult["description"] = msg;
		else 
			local retry;
			local pushAuth = sdkEntry.push_auth;
			ret,msg,retry = pushAuth(result[1]);
			retResult["code"] = ret;
			retResult["description"] = msg;
			lua_uninit();
		end
	end
	return retResult;
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
				  ["addUser"]=lua_add_user,
				  ["userOTPAuth"]  = lua_user_otp_auth,
				  ["isUserExist"] = lua_is_user_exist,
				  ["addUserPhone"] = lua_add_user_phone,
				  ["isMobileTokenActived"] = lua_is_mobile_token_actived,
				  ["activeMobileToken"] = lua_active_mobile_token,
				  ["pushAuth"] = lua_push_auth,
				  ["getQrcode"] = lua_get_qrcode,
				  ["scanAuth"] = lua_scan_auth,
				  ["voiceAuth"] = lua_voice_auth,
				  ["getWechatTokenAC"] = lua_get_wechat_token_ac,
				  ["getFaceRegistQrcode"] = lua_get_face_regist_qrcode,
				  ["getFaceRegistResult"] = lua_get_face_regist_result,
				  ["faceAuth"] = lua_face_auth,
				  ["checkUser"] = lua_check_user,
				  ["userOTPAuthByMobile"] = lua_user_otp_auth_by_mobile,
				  ["sendSmsOtp"] = lua_send_smsotp,
				  ["getSmsOtp"] = lua_get_smsotp,
				  ["tokenOTPAuth"] = lua_token_otp_auth,
				  ["bindToken"] = lua_bind_token,
				  ["unBindToken"] = lua_unbind_token,
				  ["enableToken"] = lua_enable_token,
				  ["disableToken"] = lua_disable_token,
				  ["enableUser"] = lua_enable_user,
				  ["disableUser"] = lua_disable_user,
				  ["lockToken"] = lua_lock_token,
				  ["unLockToken"] = lua_unlock_token,
				  ["lockUser"] = lua_lock_user,
				  ["unLockUser"] = lua_unlock_user,
				  ["userOTPSync"] = lua_user_otp_sync,
				  ["tokenOTPSync"] = lua_token_otp_sync,
				  ["syncLdapUsers"] = lua_sync_ldap_users,
				  ["faceEngineRegist"] = lua_face_engine_regist,
				  ["faceEngineAuth"] = lua_face_engine_auth,
				  ["getProcessResult"] = lua_get_process_result};

function switch(c, p)
	if funTable[c] then
		return funTable[c](p);
	end
end

--main function
--return switch(method, params);


