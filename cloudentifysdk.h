#ifndef _C_CLOUDENTIFY_SDK_H_
#define _C_CLOUDENTIFY_SDK_H_

//��������
#if defined(_WINDOWS) || defined(WINDOWS) || defined(WIN32) || defined(WIN64)
#define WINAPI __stdcall
#else
#define WINAPI
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus



/*
*��������:  init
*˵    ��:  ��֤��ʼ��
*��    ��:  
*           url         ��֤������url
*           app_id      Ӧ��ID
*           app_secret  Ӧ����Կ
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI init(char *url, char *app_id, char *app_secret);

/*
*��������:  uninit
*˵    ��:  ��֤����ʼ��
*��    ��:  
*��    ��:  ��
*/
void WINAPI uninit();


/*
*��������:  user_otp_auth
*˵    ��:  �����û�����֤OTP
*��    ��:  
*           user_name   �û���
*           otp         ��̬����
*           retry       ʣ�����Դ��� (OUT)
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI user_otp_auth(char *user_name, char *otp, int *retry);


/*
*��������:  is_user_exist
*˵    ��:  �ж��û��Ƿ����
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK���ڣ�����ʧ��
*/
int WINAPI is_user_exist(char *user_name);

/*
*��������:  add_user
*˵    ��:  ����û�
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI add_user(char *user_name);

/*
*��������:  add_user_phone
*˵    ��:  ����û����ֻ���
*��    ��:  
*           user_name       �û���
*           phone_sn        �ֻ���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI add_user_phone(char *user_name, char *phone_sn);

/*
*��������:  is_mobile_token_actived
*˵    ��:  ����Ƿ��Ѿ������ֻ�����
*��    ��:  
*           user_name       �û���
*           phone_sn        �ֻ��� (����Ϊ��)
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI is_mobile_token_actived(char *user_name, char *phone_sn);

/*
*��������:  active_mobile_token
*˵    ��:  �����ֻ�����
*��    ��:  
*           user_name       �û���
*           phone_sn        �ֻ��� (����Ϊ��)
*           ac_buf          ��ż�����Ļ��� (OUT)
*           ac_buf_len      ��ż�����Ļ��泤�ȣ�����1024
*           acv_buf         ��ż�����֤��Ļ��� (OUT) (�ǿ�ʱΪ���߼��������app)
*           acv_buf_len     ��ż�����֤��Ļ��泤�ȣ�����64
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI active_mobile_token(char *user_name, char *phone_sn, 
                               char *ac_buf, int ac_buf_len, 
                               char *acv_buf, int acv_buf_len);


/*
*��������:  push_auth
*˵    ��:  �����û���push��֤
*��    ��:  
*           user_name   �û���
*           retry       ʣ�����Դ���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI push_auth(char *user_name, int *retry);


/*
*��������:  get_qrcode
*˵    ��:  ��ȡӦ�ö�ά������
*��    ��:  
*           user_name       �û��� (����Ϊ��)
*           qr_buf          ��Ŷ�ά��Ļ��� (OUT)
*           qr_buf_len      ��Ŷ�ά��Ļ��泤�ȣ�����1024
*           reqid_buf       �������ID�Ļ���  (OUT) (����scan_auth�Ĳ���)
*           reqid_buf_len   �������ID�Ļ��泤�ȣ�����256
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_qrcode(char *user_name, char *qr_buf, int qr_buf_len, 
                      char *reqid_buf, int reqid_buf_len);

/*
*��������:  scan_auth
*˵    ��:  Ӧ��ɨ����֤
*��    ��:  
*           req_id          ����ID (ͨ������get_qrcode��ȡ)
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI scan_auth(char *req_id);


/*
*��������:  voice_auth
*˵    ��:  �û�����push��֤
*��    ��:  
*           user_name   �û���
*           retry       ʣ�����Դ���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI voice_auth(char *user_name, int *retry);


/*
*��������:  get_wechat_token_ac
*˵    ��:  ��ȡ΢�����Ƽ�����
*��    ��:  
*           user_name           �û���
*           wechat_ac_buf       ���΢�ż�����Ļ��� (OUT)
*           wechat_ac_buf_len   ���΢�ż�����Ļ��泤�ȣ�����1024
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_wechat_token_ac(char *user_name, char *wechat_ac_buf, int wechat_ac_buf_len);


/*
*��������:  get_face_regist_qrcode
*˵    ��:  ��ȡ����ע���ά��
*��    ��:  
*           user_name       �û���
*           phone_sn        �ֻ��� (����Ϊ��)
*           ac_qr_buf       �������ע���ά��Ļ��� (OUT)
*           ac_qr_buf_len   �������ע���ά��Ļ��泤�ȣ�����1024
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_face_regist_qrcode(char *user_name, char *phone_sn, 
                                  char *ac_qr_buf, int ac_qr_buf_len);

/*
*��������:  get_face_regist_result
*˵    ��:  ��ȡ����ע����
*��    ��:  
*           user_name       �û���
*           phone_sn        �ֻ��� (����Ϊ��)
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_face_regist_result(char *user_name, char *phone_sn);

/*
*��������:  face_auth
*˵    ��:  �û�����push��֤
*��    ��:  
*           user_name   �û���
*           retry       ʣ�����Դ���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI face_auth(char *user_name, int *retry);


/*
*��������:  check_user
*˵    ��:  ����û� �����û�������ʱ���������û���֤����
*��    ��:  
*           user_name       �û���
*           user_policy     �û���֤���� (OUT) ��
*                                   0��ҪOTP��֤��
*                                   1����OTP��֤��ֱ��ʧ�ܣ�
*                                   2����OTP��֤��ֱ�ӳɹ���
*           newuser_policy  ���û���֤���� (OUT) ��
*                                   0���û���Ҫע�᣻
*                                   1���û�ֱ��ʧ�ܣ�
*                                   2���û�ֱ�ӳɹ���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI check_user(char *user_name, int *user_policy, int *newuser_policy);

/*
*��������:  get_err_msg
*˵    ��:  ��ȡ������Ϣ windowsƽ̨��������Ϊansi���룬��windowsƽֻ̨����Ӣ��
*��    ��:  
*           code            ������
*           err_buf         ��Ŵ��������Ļ��� (OUT)
*           err_buf_len     ��Ŵ��������Ļ��泤�ȣ�����128
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_err_msg(int code, char *err_buf, int err_buf_len);

/*
*��������:  set_apptype
*˵    ��:  ����Ӧ������
*��    ��:  
*           app_type    Ӧ������
*��    ��:  ��
*/
void WINAPI set_apptype(int app_type);


/*
*��������:  user_otp_auth_by_mobile
*˵    ��:  �����û������ֻ�����֤OTP
*��    ��:  
*           user_name       �û���
*           otp             ��̬����
*           phone_sn        �ֻ���
*           retry           ʣ�����Դ��� (OUT)
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI user_otp_auth_by_mobile(char *user_name, char *otp, char *phone_sn, int *retry);


/*
*��������:  send_smsotp
*˵    ��:  �����û������ֻ��ŷ��Ͷ��ſ���
*��    ��:  
*           user_name   �û���
*           phone_sn    �ֻ���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI send_smsotp(char *user_name, char *phone_sn);

/*
*��������:  get_smsotp
*˵    ��:  ��ȡ���ſ���
*��    ��:  
*           user_name       �û���
*           smsotp_buf      ��Ŷ��ſ���Ļ��� (OUT)
*           smsotp_buf_len  ��Ŷ��ſ���Ļ��泤�ȣ�����16
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_smsotp(char *user_name, char *smsotp_buf, int smsotp_buf_len);



/*
*��������:  token_otp_auth
*˵    ��:  �������ƺ���֤OTP
*��    ��:  
*           token_sn    �������к�
*           otp         ��̬����
*           retry       ʣ�����Դ��� (OUT)
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI token_otp_auth(char *token_sn, char *otp, int *retry);


/*
*��������:  bind_token
*˵    ��:  ������
*��    ��:  
*           user_name   �û���
*           token_sn    �������к�
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI bind_token(char *user_name, char *token_sn);

/*
*��������:  unbind_token
*˵    ��:  �������
*��    ��:  
*           user_name   �û���
*           token_sn    �������к�
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI unbind_token(char *user_name, char *token_sn);

/*
*��������:  enable_token
*˵    ��:  ��������
*��    ��:  
*           token_sn    �������к�
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI enable_token(char *token_sn);

/*
*��������:  disable_token
*˵    ��:  ͣ������
*��    ��:  
*           token_sn    �������к�
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI disable_token(char *token_sn);

/*
*��������:  enable_user
*˵    ��:  �����û�
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI enable_user(char *user_name);

/*
*��������:  disable_user
*˵    ��:  ͣ���û�
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI disable_user(char *user_name);

/*
*��������:  lock_token
*˵    ��:  ��������
*��    ��:  
*           token_sn    �������к�
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI lock_token(char *token_sn);

/*
*��������:  unlock_token
*˵    ��:  ��������
*��    ��:  
*           token_sn    �������к�
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI unlock_token(char *token_sn);

/*
*��������:  lock_user
*˵    ��:  �����û�
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI lock_user(char *user_name);

/*
*��������:  unlock_user
*˵    ��:  �����û�
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI unlock_user(char *user_name);

/*
*��������:  user_otp_sync
*˵    ��:  �����û���ͬ������
*��    ��:  
*           user_name   �û���
*           otp         ��ǰ����
*           next_otp    ��һ������
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI user_otp_sync(char *user_name, char *otp, char *next_otp);

/*
*��������:  token_otp_sync
*˵    ��:  �������ƺ�ͬ������
*��    ��:  
*           token_sn    �������к�
*           otp         ��ǰ����
*           next_otp    ��һ������
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI token_otp_sync(char *token_sn, char *otp, char *next_otp);


/*
*��������:  sync_ldap_users
*˵    ��:  ͬ���û�
*��    ��:  
*           sync_id     ������ԴID 0:���ݿ�
*           users       �û��б� ��ʽ: [["user_name","user_real_name","email","phone"],[...]]
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI sync_ldap_users(char *sync_id, char *users);

/*
*��������:  face_engine_regist
*˵    ��:  ��������ע��
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI face_engine_regist(char *user_name);


/*
*��������:  face_engine_auth
*˵    ��:  ����������֤
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI face_engine_auth(char *user_name);

/*
*��������:  get_process_result
*˵    ��:  ��ȡ��������������
*��    ��:  
*           user_name   �û���
*��    ��:  OTP_OK�ɹ�������ʧ��
*/
int WINAPI get_process_result(char *user_name);




#ifdef __cplusplus
}
#endif // __cplusplus


#endif // _C_CLOUDENTIFY_SDK_H_
