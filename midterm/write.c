#include <stdio.h>
#define MAXLINE 80

/* 텍스트 파일에 줄 번호 붙여 프린트한다.*/
int main(int argc. char*argv[]
{
  FILE*fp;
  int line = 0
  char buffer[MAXLINE];

if(argc !=2)[
  fprinft(stderr, "How to use : line FileNAme\n");
  exit(I);
}

if ( (fp = fopen(argv[I],"r")) == NULL)
{
    fprintf(stderr,"Error Open File\n");
    exit(2);
}

while (fgets(buffer,MAXLINE,fp)!=NULL{// 한줄 읽기
 line++;
 printf("%3d%s",line,buffer);
}
exit(0);
}
