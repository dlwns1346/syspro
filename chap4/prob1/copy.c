#include <stdio.h>
/* 파일 복사 프로그램 */
int main(int argc, char *argv[])
{
   char c;
   FILE *fp1, *fp2;
   if (argc !=3) {
      fprintf(stderr,  “How to use: %s File1 File2\n", argv[0]);
      return 1;
   }
