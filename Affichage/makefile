main: test_affichage.o main.o
	gcc -o ../obj/main main.o test_affichage.o -lSDL2 -lSDL2_ttf -lm
	rm -rf *.o
	../obj/main
	

affichage.o: test_affichage.c
	gcc -c -Wall -g test_affichage.c -lm

main.o: main.c 
	gcc -c -Wall -g main.c -lm
