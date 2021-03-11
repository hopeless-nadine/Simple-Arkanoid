#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define WIDTH 65
#define HEIGHT 25

typedef struct {
    int x, y;
    int w;
} TRacket;

TRacket racket;
char array[HEIGHT][WIDTH + 1];

void initRacket() {
    racket.w = 7;
    racket.x = (WIDTH - racket.w)/2;
    racket.y = HEIGHT - 1;
}

void putRacket() {
    for(int i = racket.x; i < racket.x + racket.w; i++) {
        array[racket.y][i] = '@';
    }
}




void init() {
    for(int i = 0; i < WIDTH; i++) {
        array[0][i] = '#';
    }
    array[0][WIDTH] = '\0';
    strncpy(array[1], array[0], WIDTH + 1);
    for(int i = 1; i < WIDTH - 1; i++) {
        array[1][i] = ' ';
    }
    for(int i = 2; i < HEIGHT; i++) {
        strncpy(array[i], array[1], WIDTH + 1);
    }


}

void show() {
	for(int i = 0; i < HEIGHT; i++) {
    	printf("%s\n", array[i]);
    }
}

void moveRacket(int x) {
    racket.x = x;
    if(racket.x < 1) {
        racket.x = 1;
        return;
    }
    if(racket.x >= WIDTH - racket.w) {
        racket.x = WIDTH - 1 - racket.w;
        return;
    }
}


int main(void) {
    initRacket();
    init();
    putRacket();
    show();
    return 0;
}
