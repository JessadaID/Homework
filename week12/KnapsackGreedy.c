#include <stdlib.h>
#include <stdio.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx ) ;

int main() {
 int n = 5, wx = 11 ;
 int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
 int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
 int *x = KnapsackGreedy( w, v, n, wx ) ;
 for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
 return 0 ;
}//end function

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
 
  int *x = (int *)malloc(sizeof(int) * n);
  int totalWeight = 0;
  int i, j;

  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if ((double)v[i] / w[i] < (double)v[j] / w[j]) {
        int tempW = w[i];
        int tempV = v[i];
        w[i] = w[j];
        v[i] = v[j];
        w[j] = tempW;
        v[j] = tempV;
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (totalWeight + w[i] <= wx) {
      x[i] = 1;
      totalWeight += w[i];
    } else {
      x[i] = 0;
    }
  }

  return x;
}
