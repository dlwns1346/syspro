#include <stdio.h>
#include "student.h"
int main(int argc, char *argv[])
{
   struct student rec;
   int id;
   char c;
   FILE *fp;
		
   if (argc != 2) {
      fprintf(stderr, “How to use: %s FileName\n", argv[0]);
      exit(1);
   }

   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, “Erroe Open File\n");
      exit(2);
   }

do {
   printf(“Enter studentID to be modified: ");
   if (scanf("%d", &id) == 1) {
      fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);
      if ((fread(&rec, sizeof(rec), 1, fp) > 0)&&(rec.id != 0)) {
         printf(“StudentID: %8d Name: %4s Score: %4d\n", rec.id, rec.name, rec.score);
         printf(“Enter new score: ");
         scanf("%d", &rec.score);
         fseek(fp, -sizeof(rec), SEEK_CUR);
         fwrite(&rec, sizeof(rec), 1, fp);
      } else printf(“Record %d none\n", id);
   } else printf(“Input Error\n");

   printf(“Continue? (Y/N)");
   scanf(" %c",&c);
} while (c == 'Y');
fclose(fp);
exit(0);
}
