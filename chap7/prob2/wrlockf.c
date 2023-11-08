#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
   	
   /* 잠금 함수를 이용한 학생 데이터베이스 수정 프로그램 */
   int main(int argc, char *argv[])
 {
     int fd, id;
     struct student record;
	
     if (argc < 2) {
	 fprintf(stderr, “How to use : %s file\n", argv[0]);
	 exit(1);
     }
     if ((fd = open(argv[1], O_RDWR)) == -1) {
	 perror(argv[1]);
	 exit(2);
     }
	
     printf("\nEnter StudentID you want to modify : ");
     while (scanf("%d", &id) == 1) {
	 lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
	 if (lockf(fd, F_LOCK, sizeof(record)) == -1) { // 쓰기 잠금 
	     perror(argv[1]);
	     exit(3);
	 }
	
	 if ((read(fd, (char *) &record, sizeof(record)) > 0) &&  (record.id != 0)) { 
	    printf(“Name:%s\t StuID:%d\t Score:%d\n",  
                    record.name, record.id, record.score);
	    printf(“Enter new score : ");
	    scanf("%d", &record.score);
	    lseek(fd, (long) -sizeof(record), SEEK_CUR);
	    write(fd, (char *) &record, sizeof(record));

	    lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
	    lockf(fd, F_ULOCK, sizeof(record)); // 잠금 해제 
           }
           else printf(“No record %d \n", id);
	 printf("\nEnter StudentID you want to modify : ");5     }
	
     close(fd);
     exit(0);
 }
