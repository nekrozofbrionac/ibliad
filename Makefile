default: clean build

MAN_PAGES = /usr/local/share/man/
CC = gcc

build:
	$(CC) -o ibliad main.c

clean:
	rm -f ibliad 

install: build 
	mkdir -p /bin
	cp -f ibliad /bin
	chmod 755 /bin/ibliad
	mkdir -p $(MAN_PAGES)/man1
	cp -f ibliad.1 $(MAN_PAGES)/man1
	@echo "You might want to read the README as well."

uninstall:
	rm -f /bin/ibliad
	rm -f $(MAN_PAGES)/man1/ibliad.1
