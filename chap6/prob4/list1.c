#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/* 디렉터리 내의 파일 이름들을 리스트한다. */
int main(int argc, char **argv)
{
DIR *dp;
char *dir;
struct dirent *d;
struct stat st;
char path[BUFSIZ+1];

if (argc == 1)
  dir = "."; // 현재 디렉터리를 대상으로
else dir = argv[1];

if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
  perror(dir);

while ((d = readdir(dp)) != NULL) // 각 디렉터리 엔트리에 대해
  printf("%s %lu \n", d->d_name, d->d_ino); // 파일 이름, i-노드 번호 출력

closedir(dp);
exit(0);
}
