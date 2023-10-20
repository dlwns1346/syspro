#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024

/* 파일 크기를 계산 한다 */
int main(int argc, char *argv[]) 
{
   char buffer[BUFSIZE];
   int fd;
   ssize_t nread;
   long total = 0;
