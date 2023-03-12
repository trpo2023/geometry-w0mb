all: geometry run 

clean: 
	rm -rf geometry *.exe

geometry: main.c
	gcc -Wall -Werror -o geometry main.c
run:
	./geometry
