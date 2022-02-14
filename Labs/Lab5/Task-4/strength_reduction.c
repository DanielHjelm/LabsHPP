#include <stdio.h>
#include <stdlib.h>

#define FAST 0
#define FASTEST 1

int main(int argc, char **argv)
{
   int i;
   int a = 1, b = 2, c = 3, d = 1;
   float x = 0.1, y = 0.5, z = 0.33;
   printf("%d %d %d %d, %f %f %f\n", a, b, c, d, x, y, z);

#if FASTEST
   c = 2;
   b = 30;
   a = 30/16;
   d = 30/a;
   y = 0.66;
   x = 0.66/1.33;
   z = x / 1.33;
   for (i=0; i<50000000; i++)
   {
   }
#endif

#if FAST
   for (i=0; i<50000000; i++)   //blir nått fel
   {
      c = d<<1;
      b = (c<<4) - c;
      a = b>>4;
      d = (b<<4)/30;

      z = 0.33;
      y = 2*z;        //not int
      x = y * 0.7518797;
      z = x * 0.7518797;
   }
#else
   for (i=0; i<50000000; i++)
   {
      c = d*2;
      b = c*15;
      a = b/16;
      d = b/a;

      z = 0.33;
      y = 2*z;
      x = y / 1.33;
      z = x / 1.33;
   }
#endif

   printf("%d %d %d %d, %f %f %f\n", a, b, c, d, x, y, z);
   return 0;
}
