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
   exit(EXIT_FAILURE);
}
/* If we got a good PID, then we can exit the parent process. */
if (pid >0) {
   exit(EXIT_SUCCESS);
}

/* Change the file mode mask */
umask(0);

/* Open logs here*/
openlog("daemon.test", LOG_CONS|LOG_NDELAY|LOG_PID, LOG_LOCAL4);

/* Create a new SID for the child process */
sid = setsid();
if (sid < 0) {
   syslog(LOG_ERR, "%s", "SID not created. Exiting process.");
   exit(EXIT_FAILURE);
}

/* Change the current working directory */
if (chdir("/") < 0) {
   syslog(LOG_ERR, "%s", "/ directory does not exist. Exiting process.");
   exit(EXIT_FAILURE);
}

/* Close out standard file descriptors */
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);

/* Daemon Loop */
while (1) {
   /* Perform task */
   syslog(LOG_INFO, "%s", "Daemon is running and writing logs.");
   sleep(30);
}
exit(EXIT_SUCCESS);
}
