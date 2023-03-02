all: geometry run 

clean: 
	rm -rf geometry *.exe

geometry: geometry.c
	gcc -Wall -Werror -o geometry geometry.c
run:
	./geometry
