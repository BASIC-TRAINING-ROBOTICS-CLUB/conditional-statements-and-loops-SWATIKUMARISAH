
#include <stdio.h>

int main() {
    int om[] = {10, 20, 30, 40, 50}; 
    for (int i = 0; i < sizeof(om) / sizeof(om[0]); i++) 
    {
    printf("om[%d] = %d\n", i, om[i]);
    }

    return 0;
}
