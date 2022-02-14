#include <stdio.h>

int main() {
    int i;
    int counter = 0;
    for (i=100; i >= 0; --i) {
        if (counter == 4) {
            printf("%d ", i);
            counter = 0;
        }
        counter ++;
        
    }
  return 0;

}