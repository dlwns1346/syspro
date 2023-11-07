 1 #include <sys/types.h>
 2 #include <sys/stat.h>
 …
 6 #include <time.h>
 7 #include <grp.h>
 8 #include <pwd.h>
 9 #include <string.h> 
10
11 char type(mode_t);
12 char *perm(mode_t);
13 void printStat(char*, char*, struct stat*);
14
15 /* 디렉터리 내용을 자세히 리스트한다. */
16 int main(int argc, char **argv)
17 {
18     DIR *dp;
19     char *dir;
20     struct stat st;
21     struct dirent *d;
22     char path[BUFSIZ+1];
24     if (argc == 1)
25         dir = ".";
26     else dir = argv[1];
27
28     if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
29         perror(dir);
30
31     while ((d = readdir(dp)) != NULL) { // 디렉터리의 각 파일에 대해
32         sprintf(path, "%s/%s", dir, d->d_name); // 파일경로명 만들기
33         if (lstat(path, &st) < 0) // 파일 상태 정보 가져오기
34             perror(path);
35         else 
36             printStat(path, d->d_name, &st); // 상태 정보 출력
37     }
38
39     closedir(dp);
40     exit(0);
41 }
43 /* 파일 상태 정보를 출력 */
44 void printStat(char *pathname, char *file, struct stat *st) 
45 {
46     printf("%5d ", st->st_blocks);
47     printf("%c%s ", type(st->st_mode), perm(st->st_mode));
48     printf("%3d ", st->st_nlink);
49     printf("%s %s ", getpwuid(st->st_uid)->pw_name,
                 getgrgid(st->st_gid)->gr_name);
50     printf("%9d ", st->st_size);
51     printf("%.12s ", ctime(&st->st_mtime)+4);
52     printf("%s\n", file);
53 }
55 /* 파일 타입을 반환 */
56 char type(mode_t mode) 
57 {
58     if (S_ISREG(mode))
59         return('-');
60     if (S_ISDIR(mode))
61         return('d');
62     if (S_ISCHR(mode))
63         return('c');
64     if (S_ISBLK(mode))
65         return('b');
66     if (S_ISLNK(mode))
67         return('l');
68     if (S_ISFIFO(mode))
69         return('p');
70     if (S_ISSOCK(mode))
71        return('s');
72 }
74 /* 파일 접근권한을 반환 */
75 char* perm(mode_t mode) 
76 {
77     static char perms[10];
78     strcpy(perms, "---------");
79 
80     for (int i=0; i < 3; i++) {
81         if (mode & (S_IRUSR >> i*3))
82             perms[i*3] = 'r';
83         if (mode & (S_IWUSR >> i*3))
84            perms[i*3+1] = 'w';
85         if (mode & (S_IXUSR >> i*3))
86            perms[i*3+2] = 'x';
87     }
88     return(perms);
89 }
