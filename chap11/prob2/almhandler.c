#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void alarmHandler();
/* 알람 시그널을 처리한다. */
int main( )
{
   int n=1;
   signal(SIGALRM, alarmHandler);
   alarm(5);    /* 알람 시간 설정 */
   while (1) {
      sleep(1);
      printf("%d second \n", n++);
   }
   printf("실행되지 않음 \n");
}
void alarmHandler(int signo)
{
   printf("Wake up\n");
   exit(0);
}
