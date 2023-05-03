main: affichage.o menu.o jeu.o
	gcc -o Othello menu.o affichage.o jeu.o -lSDL2 -lSDL2_ttf -lSDL2_image -lm
	rm -rf *.o
	./Othello

affichage.o: Affichage/affichage.c
	gcc -c -Wall -g Affichage/affichage.c -lm

menu.o: menu.c 
	gcc -c -Wall -g menu.c -lm

jeu.o: Jeu/jeu.c
	gcc -c -Wall -g Jeu/jeu.c -lm


	

