#include <stdio.h>

#define MAXLINE 80
/* 텍스트 파일 내용을 표준출력에 출력 */
int main(int argc, char *argv[])
{
   FILE *fp;
   int c;
   int i;
   int line = 0;
   char buffer[MAXLINE];
   if (argc < 2) 
      fp = stdin; 			// 명령줄 인수가 없으면 표준입력 사용 
   else  {
      for (i = 1; i < argc; i++) {
         fp = fopen(argv[i],"r");	// 읽기 전용으로 파일 열기
         if (strcmp(argv[i], "-n") == 0) {
            while (fgets(buffer, MAXLINE, fp) != NULL) {
			      line++;
			      printf("%3d %s", line, buffer);
		      }
         } else {
            c = getc(fp); 			// 파일로부터 문자 읽기
		      while (c != EOF) { 		// 파일끝이 아니면
			      putc(c, stdout); 		// 읽은 문자를 표준출력에 출력
			      c = getc(fp); 		// 파일로부터 문자 읽기 
		      }
         }
         fclose(fp);
      }
   }
   return 0;
}
