#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int fd;
    char savedText[10][100];
    char buf;
    int line = 0;
    int i, j;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        printf("File Open Error\n");
        exit(1);
    } else {
        for(i = 0; i < 10; i++) {
	   for(j = 0; j < 100; j++) {
              if(read(fd, &buf, 1) == 0) {
                 break;
	      }
              if(buf != '\n') {
	         savedText[i][j] = buf;
              } else {
		 line++;
                 break;
              }
	   }
           if (buf == '\n') {
              savedText[i][j] = '\0';
           }
	}
        printf("File read success\n");
        printf("Total Line : %d\n", line);
        printf("You can choose 1 ~ %d Line\n", line);
        printf("Pls 'Enter' the line to select : ");
    }

    char input[10];
    fgets(input, sizeof(input), stdin);

    if(input == NULL) {
       exit(1);
    } else { 
        if(strstr(input, "*") != NULL) { // strstr - 특정 문자열 검색
            for(i = 0; i < line; i++) {
               printf("%s\n", savedText[i]);
            }
        } else if(strstr(input, "-") != NULL) {
            for(i = atoi(strtok(input, "-"))-1; i < atoi(strchr(input, '-')+1); i++) { // strtok - 문자열을 잘라주는 함수,  strchr - 특정 문자 찾기
               printf("%s\n", savedText[i]);
            }
        } else if(strstr(input, ",") != NULL) {
            printf("%s\n", savedText[atoi(strtok(input, ",")-1)]);
            printf("%s\n", savedText[atoi(strchr(input, ',')+1)-1]);
        } else {
            printf("%s\n", savedText[atoi(input)-1]); // atoi - 문자열을 정수로 변환
        }
    }

    close(fd);
    exit(0);
}
