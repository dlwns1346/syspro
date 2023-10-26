#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
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
              if(read(fd, &buf, 1) == 0)
              	break;
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
    }

    for(i = line-1; i >= 0; i--) {
       printf("%s\n", savedText[i]);
    }

    close(fd);
    exit(0);
}
