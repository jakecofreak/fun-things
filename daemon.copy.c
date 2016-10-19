#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(void) {

pid_t pid, sid;

/* Fork off the parent process */
pid = fork();
if (pid < 0) {
   FILE *fp = fopen("failure.txt", "ab+");
   int fclose(FILE *fp);
   exit(EXIT_FAILURE);
}
/* If we got a good PID, then we can exit the parent process. */
else {
   FILE *fp = fopen("success.txt", "ab+");
   int fclose(FILE *fp);
   exit(EXIT_SUCCESS);
}

/* Change the file mode mask */
FILE *fp = fopen("childrunning.txt", "ab+");
int fclose(FILE *fp);
umask(0);
FILE *fp2 = fopen("umask_success.txt", "ab+");
int fclose(FILE *fp);

exit(EXIT_SUCCESS);

}
