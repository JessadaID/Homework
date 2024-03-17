#include <stdlib.h>
#include <stdio.h>

int *KnapsackDP( int *w, int *v, int n, int wx ) ;

int main() {
 int n = 5 , wx = 11 ;
 int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
 int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
 int *x ;
 x = KnapsackDP( w, v, n, wx ) ;
 for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
 return 0 ;
}//end function

int *KnapsackDP(int *w, int *v, int n, int wx) {
  // ????????????
  int **K = (int **)malloc(sizeof(int *) * (n + 1));
  for (int i = 0; i < n + 1; i++) {
    K[i] = (int *)malloc(sizeof(int) * (wx + 1));
  }
  int *x = (int *)malloc(sizeof(int) * n);

  // ???????????
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= wx; j++) {
      if (i == 0 || j == 0) {
        K[i][j] = 0;
      }
    }
  }

  // ???????? K[i][j]
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= wx; j++) {
      if (w[i - 1] <= j) {
        K[i][j] =
            fmax(K[i - 1][j], v[i - 1] + K[i - 1][j - w[i - 1]]);
      } else {
        K[i][j] = K[i - 1][j];
      }
    }
  }

  // ?????????????
  int i = n, j = wx;
  while (i > 0 && j > 0) {
    if (K[i][j] != K[i - 1][j]) {
      x[i - 1] = 1;
      j -= w[i - 1];
    }
    i--;
  }

  // ??????
  for (int i = 0; i < n + 1; i++) {
    free(K[i]);
  }
  free(K);
  return x;
}
