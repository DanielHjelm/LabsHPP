#include <stdio.h>
#include <math.h>

#define SLOW 0
#define FAST 0
#define FASTEST 1

int main(int argc, char **argv)
{
   int i;
   float x;
   #if FASTEST
   for (i=0; i<50000000; i++)
   {
     x = sqrtf(i);
     /*
       Alternatives:
       x = sqrt(i);
       x = sqrtf(i);
     */
   }
   #endif

   #if FAST
   for (i=0; i<50000000; i++)
   {
     x = sqrt(i);
     /*
       Alternatives:
       x = sqrt(i);
       x = sqrtf(i);
     */
   }
   #endif

   #if SLOW
   for (i=0; i<50000000; i++)
   {
     x = pow(i, 0.5);
     /*
       Alternatives:
       x = sqrt(i);
       x = sqrtf(i);
     */
   }
   #endif
   printf("%f\n", x);
   return 0;
}
