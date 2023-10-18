#include <stdio.h>  

int main()
{
  printf(“Hello, "); sleep(1);
  printf(“I am Linux!"); sleep(1);
  printf(" \n"); sleep(1);

  setbuf(stdout, NULL);
  printf(“Everyone, "); sleep(1);
  printf(“Nice to meet you"); sleep(1);
  printf(" ^^"); sleep(1);
  printf(" \n"); sleep(1);
}

$ setbuf
Hello, I am Linux! 

Everyone, Nice to meet you ^^ 

