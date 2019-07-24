CC :=g++
CFLAGS  := -I. -g
LDFLAGS := -llua -Bstatic -L/usr/local/lib/ -lprotobuf -lstdc++ -lpthread -Wl,-E
SHARED  := -fPIC --shared

COMPILE := `which protoc`

all:proto/lua.so main lua.pb.cc

lua.pb.cc:lua.proto
	$(COMPILE) --cpp_out=. $^

proto/lua.so:proto_lua.cc lua.pb.cc
	$(CC)  $(CFLAGS) $(LDFLAGS) $(SHARED) $^ -o $@

main:cc_main.cc lua.pb.cc
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -f lua.pb.* proto/lua.so main


