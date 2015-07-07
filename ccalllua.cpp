#include <lua.hpp>
#include <string.h>
#pragma comment(lib, "lua5.1.lib")
#pragma comment(lib, "lua51.lib")

int main(int argc ,char* argv)
{
	//lua_State *L = luaL_newstate();

	//luaL_openlibs(L);

	//int ret = 0 ;  
	//ret = luaL_loadfile(L,"func.lua") ;      //����lua�ű��ļ�  
	//if ( ret != 0 )   
	//{  
	//	printf("����lua�ű��ļ���������\n");  
	//}  
	//ret = lua_pcall(L, 0, 2, NULL);
	//printf("%d\n", lua_tointeger(L, 1));
	//printf("%d\n", lua_tointeger(L, 2));
	//printf("%d\n", lua_gettop(L));
	//lua_pop(L, -1);  //��ն�ջ
	//printf("%d\n", lua_gettop(L));
	//lua_close(L);
	//return 0;




	//sdk

	const char *strFun = "pushAuth";
	const char *strParam = "liu;hello";

	lua_State *L = luaL_newstate();

	luaL_openlibs(L);

	int ret = 0 ;
	//����lua�ű��ļ�
	if (luaL_loadfile(L,"func.lua"))
	{
		printf("call error: %s\n", lua_tostring(L, -1));
		return -1;
	}
	lua_resume( L, 0 ); 
	lua_getglobal(L,"switch"); // �ҵ�switch���������  
	lua_pushstring(L, strFun);
	lua_pushstring(L, strParam);
	if (lua_pcall(L, 2, 1, NULL))
	{
		printf("call error: %s\n", lua_tostring(L, -1));
		return -1;
	}
	lua_getglobal(L, "retResult"); //���lua�ű������Ǳ����Բ�Ҫ���

	lua_getfield(L, -1, "description");  // �ȼ��� lua_pushstring(L, "description"); lua_gettable(L, -2);

	printf("%s\n", lua_tostring(L, -1));

	lua_pop(L, 1);   //�������value

	lua_getfield(L, -1, "code");

	printf("%d\n", lua_tointeger(L, -1));

	lua_pop(L, 1);
	lua_getfield(L, -1, "qrCode");
	const char *qrcode = lua_tostring(L, -1);
	if (strlen(qrcode) == 0)
	{
		printf("qrcode is empty!\n");
	}
	else 
	{
		printf("%s\n", qrcode);
	}

	

	/*lua_pop(L, 2);

	lua_pushstring(L, "description");
	lua_gettable(L, -2);
	printf("%s\n", lua_tostring(L, -1));
	//printf("%d\n", lua_tonumber(L, 1));
	//printf("%s\n", lua_tostring(L, 2));
	*/
	lua_close(L);
	return 0;

}