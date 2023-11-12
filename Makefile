default: clean build

build:
	gcc -o main main.c

clean:
	rm -f main
