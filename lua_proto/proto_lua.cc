#include <lua.hpp>
#include "lua.pb.h"

#ifdef WIN32
#ifdef EXPORT
#define LUAMOD_API __declspec(dllexport)
#else
#define LUAMOD_API __declspec(dllimport)
#endif
#else
#define LUAMOD_API __attribute__ ((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
static
int createByBytes(lua_State* L)
{
  /*
  printf("stack size: %d\n", lua_gettop(L));
  size_t size = 0;
  const char* buf = lua_tolstring(L, -1, &size);
  proto_lua* pp = (proto_lua*)lua_newuserdata(L, 100*sizeof(proto_lua));
  if ( NULL == pp ){
    return 0;
  }
  (*pp).ParseFromArray(buf, size);
  // proto_lua* pp = new proto_lua();
  // pp->ParseFromArray(buf, size);
  // lua_pushlightuserdata(L, pp);
  // 
  luaL_getmetatable(L, "mt");
  lua_setmetatable(L, -2);
  */
  size_t size = 0;
  const char* buf = lua_tolstring(L, -1, &size);
  proto_lua* pp = new proto_lua();
  if ( NULL == pp ){
    return 0;
  }
  pp->ParseFromArray(buf, size);
  lua_pushlightuserdata(L, pp);
  luaL_getmetatable(L, "mt");
  lua_setmetatable(L, -2);
  return 1;
}
static 
int releaseBytes(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, -1);
  if ( NULL == pp ){
    return 0;
  }
  delete pp;
  pp = NULL;
  return 0;
}

static
int createByObject(lua_State* L)
{
  printf("stack size: %d\n", lua_gettop(L));
  proto_lua* pp = (proto_lua*)lua_touserdata(L, -1);
  if ( NULL == pp ){
    return 0;
  }
  lua_pushlightuserdata(L, pp);
  luaL_getmetatable(L, "mt");
  lua_setmetatable(L, -2);
  return 1;
}

static 
int getName(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, -1); 
  if ( NULL == pp ){
    return 0;
  }
  lua_pushstring(L, pp->name().c_str());
  return 1;
}

static 
int getSex(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, -1); 
  if ( NULL == pp ){
    return 0;
  }
  lua_pushstring(L, pp->sex().c_str());
  return 1;
}

static 
int getAge(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, -1); 
  if ( NULL == pp ){
    return 0;
  }
  lua_pushinteger(L, pp->age());
  return 1;
}

static 
int setName(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, 1); 
  if ( NULL == pp ){
    return 0;
  }
  size_t s;
  const char* name = lua_tolstring(L, 2, &s);
  printf("name: %s\n", name);
  pp->set_name(name, s);
  return 0;
}

static 
int setSex(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, 1); 
  if ( NULL == pp ){
    return 0;
  }
  size_t s;
  const char* sex = lua_tolstring(L, 2, &s);
  printf("sex: %s\n", sex);
  pp->set_sex(sex, s);
  return 0;
}

static 
int setAge(lua_State* L)
{
  proto_lua* pp = (proto_lua*)lua_touserdata(L, 1); 
  if ( NULL == pp ){
    return 0;
  }
  lua_Integer age = lua_tointeger(L, 2);
  printf("age: %d\n", age);
  pp->set_age(age);
  return 0;
}
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
LUAMOD_API
int luaopen_proto_lua(lua_State *L) {
  luaL_Reg l[] = { 
    { "get_name", getName },
    { "get_sex", getSex },
    { "get_age", getAge },
    { "set_name", setName },
    { "set_sex", setSex },
    { "set_age", setAge },
    { NULL, NULL },
  };  
  luaL_Reg l2[] = {
    { "createFromBytes", createByBytes },
    { "createFromObject", createByObject },
    { "releaseBytes", releaseBytes },
    { NULL, NULL },
  };
  luaL_newmetatable(L, "mt");  //创建元表mt
  lua_newtable(L); //创建表M
  luaL_register(L, NULL, l); //为M表设置函数
  lua_setfield(L, -2, "__index"); //设置元表mt的__index;  mt ={__index=M}
  lua_pop(L, 1);

  luaL_register(L, "protolua", l2);

  //luaL_newlib(L,l);
  return 1;
}

#ifdef __cplusplus
}
#endif
