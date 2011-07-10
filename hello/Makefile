all: g c

c: hello.c
	9c -I $(PLAN9)/include hello.c
	9l -o hello -I $(PLAN9)/include -static hello.c

g: hello.go
	8g hello.go
	8l -o hellogo hello.8

clean:
	rm hello.o hello hello.8 hellogo
