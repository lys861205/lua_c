#ifndef _C_CLOUDENTIFY_SDK_H_
#define _C_CLOUDENTIFY_SDK_H_

//函数调用
#if defined(_WINDOWS) || defined(WINDOWS) || defined(WIN32) || defined(WIN64)
#define WINAPI __stdcall
#else
#define WINAPI
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus



/*
*函数名称:  init
*说    明:  认证初始化
*参    数:  
*           url         认证服务器url
*           app_id      应用ID
*           app_secret  应用密钥
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI init(char *url, char *app_id, char *app_secret);

/*
*函数名称:  uninit
*说    明:  认证反初始化
*参    数:  
*返    回:  无
*/
void WINAPI uninit();


/*
*函数名称:  user_otp_auth
*说    明:  根据用户名认证OTP
*参    数:  
*           user_name   用户名
*           otp         动态口令
*           retry       剩余重试次数 (OUT)
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI user_otp_auth(char *user_name, char *otp, int *retry);


/*
*函数名称:  is_user_exist
*说    明:  判断用户是否存在
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK存在，其他失败
*/
int WINAPI is_user_exist(char *user_name);

/*
*函数名称:  add_user
*说    明:  添加用户
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI add_user(char *user_name);

/*
*函数名称:  add_user_phone
*说    明:  添加用户的手机号
*参    数:  
*           user_name       用户名
*           phone_sn        手机号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI add_user_phone(char *user_name, char *phone_sn);

/*
*函数名称:  is_mobile_token_actived
*说    明:  检查是否已经激活手机令牌
*参    数:  
*           user_name       用户名
*           phone_sn        手机号 (可以为空)
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI is_mobile_token_actived(char *user_name, char *phone_sn);

/*
*函数名称:  active_mobile_token
*说    明:  激活手机令牌
*参    数:  
*           user_name       用户名
*           phone_sn        手机号 (可以为空)
*           ac_buf          存放激活码的缓存 (OUT)
*           ac_buf_len      存放激活码的缓存长度，至少1024
*           acv_buf         存放激活验证码的缓存 (OUT) (非空时为离线激活，请输入app)
*           acv_buf_len     存放激活验证码的缓存长度，至少64
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI active_mobile_token(char *user_name, char *phone_sn, 
                               char *ac_buf, int ac_buf_len, 
                               char *acv_buf, int acv_buf_len);


/*
*函数名称:  push_auth
*说    明:  根据用户名push认证
*参    数:  
*           user_name   用户名
*           retry       剩余重试次数
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI push_auth(char *user_name, int *retry);


/*
*函数名称:  get_qrcode
*说    明:  获取应用二维码数据
*参    数:  
*           user_name       用户名 (可以为空)
*           qr_buf          存放二维码的缓存 (OUT)
*           qr_buf_len      存放二维码的缓存长度，至少1024
*           reqid_buf       存放请求ID的缓存  (OUT) (函数scan_auth的参数)
*           reqid_buf_len   存放请求ID的缓存长度，至少256
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_qrcode(char *user_name, char *qr_buf, int qr_buf_len, 
                      char *reqid_buf, int reqid_buf_len);

/*
*函数名称:  scan_auth
*说    明:  应用扫码认证
*参    数:  
*           req_id          请求ID (通过函数get_qrcode获取)
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI scan_auth(char *req_id);


/*
*函数名称:  voice_auth
*说    明:  用户语音push认证
*参    数:  
*           user_name   用户名
*           retry       剩余重试次数
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI voice_auth(char *user_name, int *retry);


/*
*函数名称:  get_wechat_token_ac
*说    明:  获取微信令牌激活码
*参    数:  
*           user_name           用户名
*           wechat_ac_buf       存放微信激活码的缓存 (OUT)
*           wechat_ac_buf_len   存放微信激活码的缓存长度，至少1024
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_wechat_token_ac(char *user_name, char *wechat_ac_buf, int wechat_ac_buf_len);


/*
*函数名称:  get_face_regist_qrcode
*说    明:  获取人脸注册二维码
*参    数:  
*           user_name       用户名
*           phone_sn        手机号 (可以为空)
*           ac_qr_buf       存放人脸注册二维码的缓存 (OUT)
*           ac_qr_buf_len   存放人脸注册二维码的缓存长度，至少1024
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_face_regist_qrcode(char *user_name, char *phone_sn, 
                                  char *ac_qr_buf, int ac_qr_buf_len);

/*
*函数名称:  get_face_regist_result
*说    明:  获取人脸注册结果
*参    数:  
*           user_name       用户名
*           phone_sn        手机号 (可以为空)
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_face_regist_result(char *user_name, char *phone_sn);

/*
*函数名称:  face_auth
*说    明:  用户人脸push认证
*参    数:  
*           user_name   用户名
*           retry       剩余重试次数
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI face_auth(char *user_name, int *retry);


/*
*函数名称:  check_user
*说    明:  检查用户 返回用户不存在时，请检查新用户认证策略
*参    数:  
*           user_name       用户名
*           user_policy     用户认证策略 (OUT) ：
*                                   0需要OTP认证；
*                                   1不需OTP认证，直接失败；
*                                   2不需OTP认证，直接成功；
*           newuser_policy  新用户认证策略 (OUT) ：
*                                   0新用户需要注册；
*                                   1新用户直接失败；
*                                   2新用户直接成功；
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI check_user(char *user_name, int *user_policy, int *newuser_policy);

/*
*函数名称:  get_err_msg
*说    明:  获取错误信息 windows平台返回描述为ansi编码，非windows平台只返回英文
*参    数:  
*           code            错误码
*           err_buf         存放错误描述的缓存 (OUT)
*           err_buf_len     存放错误描述的缓存长度，至少128
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_err_msg(int code, char *err_buf, int err_buf_len);

/*
*函数名称:  set_apptype
*说    明:  设置应用类型
*参    数:  
*           app_type    应用类型
*返    回:  无
*/
void WINAPI set_apptype(int app_type);


/*
*函数名称:  user_otp_auth_by_mobile
*说    明:  根据用户名、手机号认证OTP
*参    数:  
*           user_name       用户名
*           otp             动态口令
*           phone_sn        手机号
*           retry           剩余重试次数 (OUT)
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI user_otp_auth_by_mobile(char *user_name, char *otp, char *phone_sn, int *retry);


/*
*函数名称:  send_smsotp
*说    明:  根据用户名、手机号发送短信口令
*参    数:  
*           user_name   用户名
*           phone_sn    手机号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI send_smsotp(char *user_name, char *phone_sn);

/*
*函数名称:  get_smsotp
*说    明:  获取短信口令
*参    数:  
*           user_name       用户名
*           smsotp_buf      存放短信口令的缓存 (OUT)
*           smsotp_buf_len  存放短信口令的缓存长度，至少16
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_smsotp(char *user_name, char *smsotp_buf, int smsotp_buf_len);



/*
*函数名称:  token_otp_auth
*说    明:  根据令牌号认证OTP
*参    数:  
*           token_sn    令牌序列号
*           otp         动态口令
*           retry       剩余重试次数 (OUT)
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI token_otp_auth(char *token_sn, char *otp, int *retry);


/*
*函数名称:  bind_token
*说    明:  绑定令牌
*参    数:  
*           user_name   用户名
*           token_sn    令牌序列号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI bind_token(char *user_name, char *token_sn);

/*
*函数名称:  unbind_token
*说    明:  解绑令牌
*参    数:  
*           user_name   用户名
*           token_sn    令牌序列号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI unbind_token(char *user_name, char *token_sn);

/*
*函数名称:  enable_token
*说    明:  启用令牌
*参    数:  
*           token_sn    令牌序列号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI enable_token(char *token_sn);

/*
*函数名称:  disable_token
*说    明:  停用令牌
*参    数:  
*           token_sn    令牌序列号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI disable_token(char *token_sn);

/*
*函数名称:  enable_user
*说    明:  启用用户
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI enable_user(char *user_name);

/*
*函数名称:  disable_user
*说    明:  停用用户
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI disable_user(char *user_name);

/*
*函数名称:  lock_token
*说    明:  锁定令牌
*参    数:  
*           token_sn    令牌序列号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI lock_token(char *token_sn);

/*
*函数名称:  unlock_token
*说    明:  解锁令牌
*参    数:  
*           token_sn    令牌序列号
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI unlock_token(char *token_sn);

/*
*函数名称:  lock_user
*说    明:  锁定用户
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI lock_user(char *user_name);

/*
*函数名称:  unlock_user
*说    明:  解锁用户
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI unlock_user(char *user_name);

/*
*函数名称:  user_otp_sync
*说    明:  根据用户名同步令牌
*参    数:  
*           user_name   用户名
*           otp         当前口令
*           next_otp    下一个口令
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI user_otp_sync(char *user_name, char *otp, char *next_otp);

/*
*函数名称:  token_otp_sync
*说    明:  根据令牌号同步令牌
*参    数:  
*           token_sn    令牌序列号
*           otp         当前口令
*           next_otp    下一个口令
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI token_otp_sync(char *token_sn, char *otp, char *next_otp);


/*
*函数名称:  sync_ldap_users
*说    明:  同步用户
*参    数:  
*           sync_id     数据来源ID 0:数据库
*           users       用户列表 格式: [["user_name","user_real_name","email","phone"],[...]]
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI sync_ldap_users(char *sync_id, char *users);

/*
*函数名称:  face_engine_regist
*说    明:  人脸引擎注册
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI face_engine_regist(char *user_name);


/*
*函数名称:  face_engine_auth
*说    明:  人脸引擎认证
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI face_engine_auth(char *user_name);

/*
*函数名称:  get_process_result
*说    明:  获取人脸引擎操作结果
*参    数:  
*           user_name   用户名
*返    回:  OTP_OK成功，其他失败
*/
int WINAPI get_process_result(char *user_name);




#ifdef __cplusplus
}
#endif // __cplusplus


#endif // _C_CLOUDENTIFY_SDK_H_
