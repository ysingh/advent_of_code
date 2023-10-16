#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // READ THE INPUT - im not doing any error checking here.
    FILE* input = fopen("./input", "rb");
    fseek(input, 0L, SEEK_END);
    long file_size = ftell(input);
    rewind(input);
    unsigned char* buf = malloc(file_size);
    fread(buf, file_size, 1, input);

    int floor = 0;
    int y;
    int firstEnteredBasement = 0;
    for (int i = 0; i < file_size; ++i) {
        floor -= (buf[i] << 1) - 81;
        floor == -1 && firstEnteredBasement == 0 ? firstEnteredBasement = i + 1 : "";
    }

    printf("Floor: %i First Entered Basememt: %i\n", floor, firstEnteredBasement);

    return 0;
}