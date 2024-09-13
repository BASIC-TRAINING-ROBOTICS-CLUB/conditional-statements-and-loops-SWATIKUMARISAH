
#include <stdio.h>

int main() {
    float a, b, c;
    printf("Enter the length of three sides: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == b && b == c)
        printf("The triangle is equilateral\n");
    else
        printf("The triangle is not equilateral\n");
    return 0;
}

