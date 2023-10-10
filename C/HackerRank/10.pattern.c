#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int size = n * 2 - 1;
    int minDist = 0, value = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculate the minimum distance from the current cell to the border
            minDist = i < j ? i : j;
            minDist = minDist < size-1 - i  ? minDist : size-1 - i ;
            minDist = minDist < size-1 - j  ? minDist : size-1 - j ;
            
            // Calculate the value to print
            value = n - minDist;

            printf("%d ", value);
        }
        printf("\n");
    }
    return 0;
}