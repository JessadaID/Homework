
#include <stdio.h>

double f( double x ) ;
double RootOfFunction( double xl, double xr, double epsilon ) ;

int main() {
 double root ;
 root = RootOfFunction( -1, 10, 0.1 ) ;
 printf( "Root = %.1f", root ) ;
 return 0 ;
}//end function

double f( double x ) {
 return 2 * x - 5 ;
}//end function

????????? RootOfFunction ????????????????
C
#include <stdio.h>

double f(double x);
double RootOfFunction(double xl, double xr, double epsilon) {


  double xm;
  while (xr - xl > epsilon) {
    xm = (xl + xr) / 2;
    if (f(xm) == 0) {
      return xm;
    } else if (f(xm) * f(xl) < 0) {
      xr = xm;
    } else {
      xl = xm;
    }
  }

  return (xl + xr) / 2;
}

double f(double x) {
  
  return 2 * x - 5;
}

int main() {
  double root;
  root = RootOfFunction(-1, 10, 0.1);

  printf("Root = %.1f", root);

  return 0;
}
