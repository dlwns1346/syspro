#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>	

void p1(), p2();
jmp_buf env;
	
int main() 
{
    if (setjmp(env) != 0) {
         printf("오류로 인한 복귀 및 처리\n");
         exit(0);
    } 
   else printf("처음 통과\n");
	
   p1(); 
} 
void p1()
{ 
    p2();
}
	
void p2() 
{
    int error;
	
    error = 1;
    if (error) {
        printf("오류 \n");
        longjmp(env, 1);
    }
}
