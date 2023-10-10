#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int result = 0, temp = 0;
  for(int i=0; i<3; i++)
  {
    for(int j=1; j<n; j++)
    {
      for(int x=j+1; x<=n; x++)
      {
        if(i == 0)
        {
          temp = j & x;
          if(temp > result && temp < k)
            result = temp;
        }
        else if(i == 1)
        {
          temp = j | x;
          if(temp > result && temp < k)
            result = temp;
        }
        else
        {
          temp = j ^ x;
          if(temp > result && temp < k)
            result = temp;
        }
      }
    }
    printf("%d\n", result);
    result = 0;
  }
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
