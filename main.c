#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>

/* PROTOTIPOS */
void imprimirMapa();




int main() {
    char iniciar;
    char pausar;

    textcolor(RED);
    printf("\t ~~MAZE RUNNER~~\n\n");
    textcolor(GREEN);
    printf("Presione [O] para iniciar el programa\n");
    printf("Presione [P] para pausar el programa\n\n");

    while(1){
        iniciar=getch();
        if(iniciar=='O' || iniciar=='o'){
            printf("Su juego se inicio correctamente\n\n");
            imprimirMapa();
        }
    }
	return 0;
}


void imprimirMapa(){
    FILE *maze;
    char c;

    maze=fopen("maze.txt","r");

    if(maze!=NULL){
        textcolor(WHITE);
        while(1){
            c=fgetc(maze);
            if(c=='0'){
                textbackground(WHITE);
                c=' ';
            }else{
                textbackground(BLACK);
            }if(c=='I' || c=='T'){
                textbackground(LIGHTBLUE);
                textcolor(BLACK);
            }
            if(feof(maze))
                break;
            printf("%c",c);
        }
    }
    else
        printf("\nHubo un error al cargar su laberinto.");
    printf("\n");
    textcolor(BLACK);
}



