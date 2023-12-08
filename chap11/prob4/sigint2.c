#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo); 

int main( void)
{
     newact.sa_handler = sigint_handler; // 시그널 처리기 지정
     sigfillset(&newact.sa_mask); // 모든 시그널을 차단하도록 마스크 
 
    // SIGINT의 처리 액션을 새로 지정, oldact에 기존 처리 액션을 저장
    sigaction(SIGINT, &newact, &oldact);
    while(1 ) {
        printf( "Ctrl-C를 눌러 보세요 !\n");
        sleep(1);
     }
 }

 /* SIGINT 처리 함수 */
 void sigint_handler(int signo)
 {
     printf( "%d 번 시그널 처리!\n", signo);
     printf( "또 누르면 종료됩니다.\n");
     sigaction(SIGINT, &oldact, NULL); // 기존 처리 액션으로 변경
 }
