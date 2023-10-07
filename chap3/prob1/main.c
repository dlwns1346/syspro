#include <stdio.h>
#include "copy.h“

char line[MAXLINE]; // 입력 줄
char longest[MAXLINE]; // 가장 긴 줄
/* 입력 줄 가운데 가장 긴 줄을 프린트한다. */

main(){
  int len;
  int max;
  max = 0;

  while(gets(line) != NULL) {
    len = strlen(line);

    if(len > max) {
       max = len;
       copy(line, longest);
      }
    }

  if(max > 0) // 입력 줄이 있었다면
    printf("%s \n", longest);

  return 0;
}
