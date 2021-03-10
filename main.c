#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define WIDTH 65
#define HEIGHT 25

char array[WIDTH][HEIGHT];

void init() {
    for(int i = 0; i < WIDTH; i++) {
        array[0][i] = '#';
    }
}

void show() {
    printf("%s", array[0]);
}

int main(void) {
    init();
    show();
    return 0;
}
