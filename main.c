#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define WIDTH 65
#define HEIGHT 25

char array[HEIGHT][WIDTH + 1];

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

int main(void) {
    init();
    show();
    return 0;
}
