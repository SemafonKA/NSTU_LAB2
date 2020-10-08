#include <stdio.h>
#include <math.h>

int main() {
   double s = 1, s2 = 0;
   unsigned int n = 2, i;
   unsigned short k;
   int a = 0, b = 1;
   double epsilon, h = 0;

   scanf_s("%lf", &epsilon);

   do {
      h = (b - a) / (double)n;
      k = 1; i = 0;
      s2 = s; s = 0;

      do {
         if (k == 4) {
            k = 1; i--;
         }
         if (k == 2) {
            s += (1 / (1 + i * h + a)) * 4;
         }
         else {
            s += (1 / (1 + i * h + a));
         }
         i++; k++;
      } while (i <= n);
      n *= 2;
      s *= h / 3;

   } while (fabs(s - s2) > epsilon);

   printf("%lf\n", s);
   printf("%u ", n / 2);
   return 0;
}