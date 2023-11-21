#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {
    int opt;
    int i = 1;
    while ((opt = getopt(argc, argv, "eugip")) != -1) {
        switch (opt) {
            case 'e':
		if (i + 1 < argc && argv[i + 1][0] != '-') {
		    char *env_val = getenv(argv[i + 1]);
		    if (env_val != NULL) {
                        printf("%s=%s\n", argv[i + 1], env_val);
                    } else {
                        printf("%s is not set.\n", argv[i + 1]);
                    }
		} else {
		    char **env;
	            for (env = envp; *env != 0; env++) {
	                printf("%s\n", *env);
	            }
		}
                break;
            case 'u':
                printf("Real User ID: %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
                printf("Effective User ID: %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
                break;
            case 'g':
                printf("Real Group ID: %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
                printf("Effective Group ID: %d(%s)\n", getegid(), getgrgid(getegid())->gr_name);
                break;
            case 'i':
                printf("Process ID: [%d]\n", getpid());
                break;
            case 'p':
                printf("Parent Process ID: [%d]\n", getppid());
                break;
            default:
                exit(1);
        }
    }
    exit(0);
}
