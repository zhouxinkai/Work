s:=pkg-config --libs --cflags gtk+-2.0
all:main.c
	gcc main.c  -lm `$s` -o main
arm:main.c
	arm-linux-gcc main.c -lm `$s` -o calcu
clean:
	rm -f main  calcu

