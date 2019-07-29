#include <lua.hpp> 
#include <string.h> 
#include "lua.pb.h"

static 
int lua_call(lua_State* L)
{
  printf("call: %s\n", lua_tostring(L, -1));
  lua_pushstring(L, "call return");
  return 1;
}

int main(int argc ,char** argv)
{
    lua_State *L = luaL_newstate();

    luaL_openlibs(L);

    lua_pushcfunction(L, lua_call);
    lua_pushstring(L, "hello lua_call");
    lua_pcall(L, 1, 1, 0);
    printf("#####%s\n", lua_tostring(L, -1));


    int ret = 0 ;
    //加载lua脚本文件
    if (luaL_loadfile(L,"proto.lua"))
    {
        printf("call error: %s\n", lua_tostring(L, -1));
        return -1;
    }
    lua_resume( L, 0 );
    lua_getglobal(L, "call_c_function");
    lua_pushcfunction(L, lua_call);
    lua_pcall(L, 1, 0, 0);



    lua_getglobal(L,"decodeObject");
    proto_lua proto;
    proto.set_name("liu");
    proto.set_sex("nan");
    proto.set_age(12);
    lua_pushlightuserdata(L, &proto);
    if (lua_pcall(L, 1, 1, 0))
    {
        printf("call error: %s\n", lua_tostring(L, -1));
        return -1;
    }
    printf("origin proto: %s\n", proto.Utf8DebugString().c_str());
    proto_lua* pp = (proto_lua*)lua_touserdata(L, -1);
    printf("change proto: %s\n", pp->Utf8DebugString().c_str());
    lua_pop(L, 1);

    lua_getglobal(L,"decodeBytes");
    proto_lua proto2;
    proto2.set_name("xiao");
    proto2.set_sex("nv");
    proto2.set_age(10);
    std::string user;
    proto2.SerializeToString(&user);
    lua_pushlstring(L, user.c_str(), user.size());
    if (lua_pcall(L, 1, 0, 0))
    {
        printf("call error: %s\n", lua_tostring(L, -1));
        return -1;
    }
    printf("************* test coroutine *******************\n");
    lua_State* L1 = lua_newthread(L);
    printf("main stack size: %d\n", lua_gettop(L));
    lua_getglobal(L1, "coroutine_test");
    lua_pushthread(L1);

    printf("L1 stack size: %d\n", lua_gettop(L1));
    lua_resume(L1, 1);
    //lua_resume(L1, 1);

    /*
    lua_getglobal(L,"ParseProtobuf");
    proto_lua proto3;
    proto3.set_name("xiao");
    proto3.set_sex("nv");
    proto3.set_age(10);
    lua_pushlightuserdata(L, &proto3);
    if (lua_pcall(L, 1, 0, 0))
    {
        printf("call error: %s\n", lua_tostring(L, -1));
        return -1;
    }
    */
    lua_close(L);
  return 0;
}
