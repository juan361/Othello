main: test_affichage.o main.o
	gcc -o main main.o test_affichage.o -lSDL2 -lm
	./main
	rm -rf *.o

affichage.o: test_affichage.c
	gcc -c -Wall -g test_affichage.c -lm

main.o: main.c 
	gcc -c -Wall -g main.c -lm
