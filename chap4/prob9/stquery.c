#include <stdio.h>
#include "student.h"
int main(int argc, char *argv[])
{
   struct student rec;
   char c;
   int id;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, “How to use: %s FileName\n", argv[0]);
      exit(1);
   }

   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, “Error Open File\n");
      exit(2);
   }

   do {
      printf(“Enter studentID to search: ");
      if (scanf("%d", &id) == 1) {
         fseek(fp, (id - START_ID) *sizeof(rec),  SEEK_SET);
         if ((fread(&rec,  sizeof(rec),  1,  fp) > 0)   &&  (rec.id != 0))
            printf(“StudentID: %8d Name: %4s Score: %4d\n",  rec.id,  rec.name,  rec.score);
          else printf(“Record %d None\n", id);
      }
      else printf(“Input Error");

      printf(“Continue? (Y/N)");
      scanf(" %c", &c);
   } while (c == 'Y');

   fclose(fp);
   exit(0);
}
