 1 #include <stdio.h>
 …
 
 /* 잠금을 이용한 학생 데이터베이스 수정 프로그램 */
 int main(int argc, char *argv[])
 {
    int fd, id;
    struct student record;
    struct flock lock;

    if (argc < 2) {
       fprintf(stderr, “How to use : %s File \n", argv[0]);
       exit(1);
    }

   if ((fd = open(argv[1], O_RDWR)) == -1) {
      perror(argv[1]);
      exit(2);
   }

   printf("\nEnter StudentID you want to modify : ");
   while (scanf("%d", &id) == 1) {
      lock.l_type = F_WRLCK;
      lock.l_whence = SEEK_SET;
      lock.l_start = (id-START_ID)*sizeof(record);
      lock.l_len = sizeof(record);
      if (fcntl(fd,F_SETLKW, &lock) == -1) { /* 쓰기 잠금 */
         perror(argv[1]);
         exit(3);
      }

