#include "testluacallsdk.h"
#include "cloudentifysdk.h"

#pragma comment(lib, "lua5.1.lib")
#pragma comment(lib, "lua51.lib")
#pragma comment(lib, "cloudentifysdk.lib")


int lua_init(lua_State* L)
{
	set_apptype(4);
	const char* url   = luaL_checkstring(L, 1);
	const char* appId = luaL_checkstring(L, 2);
	const char* appK  = luaL_checkstring(L, 3);
	int ret = init((char*)url, (char*)appId,(char*)appK);
	char buff[128] = {0};
	get_err_msg(ret, buff, 128);
	lua_pushnumber(L, ret);
	lua_pushstring(L, buff);
	return 2;
}
int lua_uninit(lua_State* L)
{
	uninit();
	return 0;
}
int  lua_user_otp_auth(lua_State* L){ return 2;}
int  lua_is_user_exist(lua_State* L){ return 2;}
int  lua_add_user(lua_State* L)
{
	const char* user   = luaL_checkstring(L, 1);
	int ret = add_user((char*)user);
	char buff[128] = {0};
	get_err_msg(ret, buff, 128);
	lua_pushnumber(L, ret);
	lua_pushstring(L, buff);
	return 2;
}
int  lua_add_user_phone(lua_State* L){ return 2;}
int  lua_is_mobile_token_actived(lua_State* L){ return 2;}
int  lua_active_mobile_token(lua_State* L){ return 2;}
int  lua_push_auth(lua_State* L)
{ 
	int retry = 0;
	const char* user   = luaL_checkstring(L, 1);//获取参数
	int ret = push_auth((char*)user, &retry);
	char buff[128] = {0};
	get_err_msg(ret, buff, 128);
	lua_pushnumber(L, ret);      //结果压栈
	lua_pushstring(L, buff);     //结果压栈
	lua_pushnumber(L, retry);    //结果压栈
	return 3; //返回结果个数
}
int  lua_get_qrcode(lua_State* L){ return 2;}
int  lua_scan_auth(lua_State* L){ return 2;}
int  lua_voice_auth(lua_State* L){ return 2;}
int  lua_get_wechat_token_ac(lua_State* L){ return 2;}
int  lua_get_face_regist_qrcode(lua_State* L){ return 2;}
int  lua_get_face_regist_result(lua_State* L){ return 2;}
int  lua_face_auth(lua_State* L){ return 2;}
int  lua_check_user(lua_State* L){ return 2;}
int  lua_get_err_msg(lua_State* L){ return 2;}
int  lua_user_otp_auth_by_mobile(lua_State* L){ return 2;}
int  lua_send_smsotp(lua_State* L){ return 2;}
int  lua_get_smsotp(lua_State* L){ return 2;}
int  lua_token_otp_auth(lua_State* L){ return 2;}
int  lua_bind_token(lua_State* L){ return 2;}
int  lua_unbind_token(lua_State* L){ return 2;}
int  lua_enable_token(lua_State* L){ return 2;}
int  lua_disable_token(lua_State* L){ return 2;}
int  lua_enable_user(lua_State* L){ return 2;}
int  lua_disable_user(lua_State* L){ return 2;}
int  lua_lock_token(lua_State* L){ return 2;}
int  lua_unlock_token(lua_State* L){ return 2;}
int  lua_lock_user(lua_State* L){ return 2;}
int  lua_unlock_user(lua_State* L){ return 2;}
int  lua_user_otp_sync(lua_State* L){ return 2;}
int  lua_token_otp_sync(lua_State* L){ return 2;}
int  lua_sync_ldap_users(lua_State* L){ return 2;}
int  lua_face_engine_regist(lua_State* L){ return 2;}
int  lua_face_engine_auth(lua_State* L){ return 2;}
int  lua_get_process_result(lua_State* L){ return 2;}




//export entry
__declspec(dllexport)
int luaopen_luacallsdk(lua_State* L)
{ 
	const char* libName = "mylib";
	luaL_register(L, libName, mylibs);
	return 1;
}



