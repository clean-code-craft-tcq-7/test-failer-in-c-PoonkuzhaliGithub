#include <stdio.h>
#include <assert.h>
#include <misaligned.h>

int printColorMap() {

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColorNames[i], minorColorNames[j]);
        }
    }
    return i * j;
}
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColorValue = 
        (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColorValue =
        (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.minorColorValue == expectedMinor);
    assert(colorPair.majorColorValue == expectedMajor);
}

int main() {
    printColorMap();
    testNumberToPair(1,WHITE,BLUE);
    testNumberToPair(17,YELLOW,ORANGE);
    testNumberToPair(25,VIOLET,SLATE);
    
    printf("All is well (maybe!)\n");
    return 0;
}
