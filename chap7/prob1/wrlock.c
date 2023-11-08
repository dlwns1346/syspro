 1 #include <stdio.h>
 …
 7
 8 /* 잠금을 이용한 학생 데이터베이스 수정 프로그램 */
 9 int main(int argc, char *argv[])
10 {
11    int fd, id;
12    struct student record;
13    struct flock lock;
14
15    if (argc < 2) {
16       fprintf(stderr, “How to use : %s File \n", argv[0]);
17       exit(1);
18    }
19
20   if ((fd = open(argv[1], O_RDWR)) == -1) {
21      perror(argv[1]);
22      exit(2);
23   }
24
25   printf("\nEnter StudentID you want to modify : ");
26   while (scanf("%d", &id) == 1) {
27      lock.l_type = F_WRLCK;
28      lock.l_whence = SEEK_SET;
29      lock.l_start = (id-START_ID)*sizeof(record);
30      lock.l_len = sizeof(record);
31      if (fcntl(fd,F_SETLKW, &lock) == -1) { /* 쓰기 잠금 */
32         perror(argv[1]);
33         exit(3);
34      }
35
36      lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
37      if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
38         printf(“Name:%s\t StuID:%d\t Score:%d\n",
39                   record.name, record.id, record.score);
40         printf(“Enter new score: ");
41         scanf("%d", &record.score);
42         lseek(fd, (long) -sizeof(record), SEEK_CUR);
43         write(fd, (char *) &record, sizeof(record));
44         lock.l_type = F_UNLCK;
45         fcntl(fd, F_SETLK, &lock);    /* 잠금 해제 */
46      }
47      else printf(“No record %d \n", id); 
48      printf("\nEnter StudentID you want to modify : ");
49    }
50    close(fd);
51    exit(0);
52 }

