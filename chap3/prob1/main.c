#include <stdio.h>
#include <string.h>
#include "copy.h"
char line[5][MAXLINE]; // 입력 줄
char longest[5][MAXLINE]; // 가장 긴 줄
void copy(char from[], char to[]);


/*입력 줄 가운데 가장 긴 줄 프린트 */
int main()
{
   int len, max = 0;

   int i = 0;

   while (i < 5) {
      fgets(line[i],MAXLINE,stdin);
      len = strlen(line[i]);
      if (len > max) {
         max = len;
         copy(line[i], longest[max]);
      } else {
         copy(line[i], longest[len]);
      }
      i++;
   }

   while (max > 0) {// 입력 줄이 있었다면
      printf("%s", longest[max]);
      max--;
   }

   return 0;
}
