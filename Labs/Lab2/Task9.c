#include <stdio.h>

void swap_nums(int *first, int *second) {
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
    
}

void swap_pointers(char first, char second) {
    char temp;
    temp = first;
    first = second;
    second = temp;

}

int main()
{
int a,b;
char *s1,*s2;
a = 3; b=4;
swap_nums(&a,&b);
printf("a=%d, b=%d\n", a, b);
s1 = "second"; s2 = "first";
swap_pointers(&s1,&s2);
printf("s1=%s, s2=%s\n", s1, s2);
return 0;
}



