#include <stdio.h>
/* 알람 시그널을 보여주는 프로그램 */
int main( )
{
   int n=1;
   alarm(5);
   printf("Loop start \n");
   while (1) {
      sleep(1);
      printf("%d second \n", n++);
   }
   printf("Alarm clock \n");
}

