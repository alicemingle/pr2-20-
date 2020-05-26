all: wow
	
clean:
			rm -rf wow *.o
main.o: main.c
			gcc -c main.c
pr2.o: pr2.c
		        gcc -c pr2.c
wow: main.o pr2.o
			gcc -o wow main.o pr2.o
