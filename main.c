#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "curses.h"

void finish();

typedef struct {
    int x, y;
    int w;
} TRacket;

TRacket racket;
char **field;

void init() {
    initscr();
    savetty();
    nonl();
    cbreak();
    noecho();
    timeout(0);
    leaveok(stdscr, TRUE);
    curs_set(0);
}

void initRacket() {
    racket.w = 7;
    racket.x = (COLS - racket.w)/2;
    racket.y = LINES - 2;
}

void putRacket() {
    for(int i = racket.x; i < racket.x + racket.w; i++) {
        field[racket.y][i] = '@';
    }
}


void initField() {
    field = (char**) malloc(LINES * sizeof(char*));
    if(!field) {
        finish();
    }

    for(int i = 0; i < COLS; i++) {
        field[i] = (char*) malloc(COLS * sizeof(char));
        if(!field[i]) {
            finish();
        }
    }
    for(int i = 0; i < COLS; i++) {
        field[0][i] = '#';
    }
    strncpy(field[1], field[0], COLS);
    for(int i = 1; i < COLS - 1; i++) {
        field[1][i] = ' ';
    }
    for(int i = 2; i < LINES; i++) {
        strncpy(field[i], field[1], COLS);
    }
}


void finish() {
	printf("\n");
    curs_set(1);
    clear();
    refresh();
    resetty();
    endwin();
    exit(0);

}
void show() {
	for(int i = 0; i < LINES; i++) {
		for(int j = 0; j < COLS; j++) {
    		printf("%c", field[i][j]);
    	}
    }
}

int main(void) {
    init();
    initField();
    initRacket();
    putRacket();
    show();
    napms(10000);
    finish();
    return 0;
}
