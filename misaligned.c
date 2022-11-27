#include <stdio.h>
#include <assert.h>

typedef struct
{
   char* majorColor;
   char* minorColor;
}colorCode;
colorCode colorCode_t;

colorCode_t -> majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
colorCode_t -> minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert((colorCode_t-> majorColor[0] =='White') && (colorCode_t-> minorColor[1] =='Orange');
    printf("All is well (maybe!)\n");
    return 0;
}
