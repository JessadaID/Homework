#include <stdio.h>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) ;

int main() {
 int n = 5, wx = 11 ;
 int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
 int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
 int *x, vx ;
 x = new int[ n ] ;
 vx = KnapsackBT( w, v, n, wx, 0, x ) ;
 printf( "Value = %d ", vx ) ;
 for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
 return 0 ;
}//end function

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {

  if (i == n) {
    int totalValue = 0;
    for (int j = 0; j < n; j++) {
      totalValue += v[j] * x[j];
    }
    return totalValue;
  }

  int bound1 = KnapsackBT(w, v, n, wx, i + 1, x);

  if (wx >= w[i]) {
    x[i] = 1;
    int bound2 = KnapsackBT(w, v, n, wx - w[i], i + 1, x);
    x[i] = 0;
  } else {
    int bound2 = -1;
  }


  return fmax(bound1, bound2);
}
