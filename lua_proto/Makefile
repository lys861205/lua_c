CC :=g++
CFLAGS  := -I. -g
LDFLAGS := -llua -Bstatic -L/usr/local/lib/ -lprotobuf -lstdc++ -lpthread -Wl,-E
SHARED  := -fPIC --shared

COMPILE := `which protoc`

all:proto/lua.so main lua.pb.cc bench_c_test bench_lua_test

lua.pb.cc:lua.proto
	$(COMPILE) --cpp_out=. $^

proto/lua.so:proto_lua.cc lua.pb.cc
	$(CC)  $(CFLAGS) $(LDFLAGS) $(SHARED) $^ -o $@

main:cc_main.cc lua.pb.cc
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

bench_c_test:bench_c_test.c
	$(CC) $(CFLAGS) $^ -o $@
	@echo "####### bench c #############"
	@./bench_c_test
	@touch "bench_c_test.c"

bench_lua_test:
	@echo "####### bench lua #############"
	@lua bench_lua_test.lua

	
clean:
	rm -f lua.pb.* proto/lua.so main bench_c_test


