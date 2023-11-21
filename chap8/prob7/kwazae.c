#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[]) {
    int opt;
    
    while ((opt = getopt(argc, argv, "e:ugip")) != -1) {
        switch (opt) {
            case 'e':
		if (optarg[0] != '\0') {
		    char *env_val = getenv(optarg);
		    if (env_val != NULL) {
                        printf("%s=%s\n", optarg, env_val);
                    } else {
                        printf("%s is not set.\n", optarg);
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
