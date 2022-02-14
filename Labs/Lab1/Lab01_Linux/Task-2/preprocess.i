# 1 "preprocess.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 366 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "preprocess.c" 2
# 1 "./preprocess.h" 1






int add(int, int);

void function_we_dont_use();
# 2 "preprocess.c" 2




int main()
{
   int two = 2;
   int sum = add(two, 9);
}

int add(int a, int b)
{
   return a + b;
}
