#ifndef __test_lua_call_sdk
#define __test_lua_call_sdk
#include <lua.hpp>
#define CALL_STACK
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int CALL_STACK  lua_init(lua_State* L);
int CALL_STACK lua_uninit(lua_State* L);
int CALL_STACK  lua_user_otp_auth(lua_State* L);
int CALL_STACK   lua_is_user_exist(lua_State* L);
int CALL_STACK   lua_add_user(lua_State* L);
int CALL_STACK   lua_add_user_phone(lua_State* L);
int CALL_STACK   lua_is_mobile_token_actived(lua_State* L);
int CALL_STACK   lua_active_mobile_token(lua_State* L);
int CALL_STACK   lua_push_auth(lua_State* L);
int CALL_STACK   lua_get_qrcode(lua_State* L);
int CALL_STACK   lua_scan_auth(lua_State* L);
int CALL_STACK   lua_voice_auth(lua_State* L);
int CALL_STACK   lua_get_wechat_token_ac(lua_State* L);
int CALL_STACK   lua_get_face_regist_qrcode(lua_State* L);
int CALL_STACK   lua_get_face_regist_result(lua_State* L);
int CALL_STACK   lua_face_auth(lua_State* L);
int CALL_STACK   lua_check_user(lua_State* L);
int CALL_STACK   lua_get_err_msg(lua_State* L);
int CALL_STACK   lua_user_otp_auth_by_mobile(lua_State* L);
int CALL_STACK   lua_send_smsotp(lua_State* L);
int CALL_STACK   lua_get_smsotp(lua_State* L);
int CALL_STACK   lua_token_otp_auth(lua_State* L);
int CALL_STACK   lua_bind_token(lua_State* L);
int CALL_STACK   lua_unbind_token(lua_State* L);
int CALL_STACK   lua_enable_token(lua_State* L);
int CALL_STACK   lua_disable_token(lua_State* L);
int CALL_STACK   lua_enable_user(lua_State* L);
int CALL_STACK   lua_disable_user(lua_State* L);
int CALL_STACK   lua_lock_token(lua_State* L);
int CALL_STACK   lua_unlock_token(lua_State* L);
int CALL_STACK   lua_lock_user(lua_State* L);
int CALL_STACK   lua_unlock_user(lua_State* L);
int CALL_STACK   lua_user_otp_sync(lua_State* L);
int CALL_STACK   lua_token_otp_sync(lua_State* L);
int CALL_STACK   lua_sync_ldap_users(lua_State* L);
int CALL_STACK  lua_face_engine_regist(lua_State* L);
int CALL_STACK  lua_face_engine_auth(lua_State* L);
int CALL_STACK  lua_get_process_result(lua_State* L);




//export entry
__declspec(dllexport)
int CALL_STACK  luaopen_luacallsdk(lua_State* L);

#ifdef __cplusplus
}

static luaL_Reg mylibs[] = { 
	{"init", lua_init},
	{"uninit", lua_uninit},
	{"user_otp_auth", lua_user_otp_auth},
	{"is_user_exist", lua_is_user_exist},
	{"add_user", lua_add_user},
	{"add_user_phone", lua_add_user_phone},
	{"push_auth", lua_push_auth},
	{"is_mobile_token_actived", lua_is_mobile_token_actived},
	{NULL, NULL} 
}; 



#endif // __cplusplus

#endif //
