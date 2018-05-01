# Final homework
Our final project is to implement the `system()` function, which can execute user's command. And the most important point is its **signal handler**.

## Code Auditing
Therefore, it is time for me to read the code of `system` in C library.  
I also make some mistake while I am doing final project.  
```c
#include <signal.h>
#include <stdio.h>

system(char *s){
	int status, pid, w, tty;
	int (*istat)(), (*qstat)();
	extern char *program;

	fflush(stdout);
	tty = open("/dev/tty",O_RDWR);     
	if(tty == -1){
		fprintf(stderr, "%s: can't open /dev/tty\n", program);
		return -1;
	}
	if((pid = fork()) == 0){
		// child process

		close(0);dup(tty);          
		close(1);dup(tty);
		close(2);dup(tty);
		close(tty);            // redirect stdin, stdout, stderr to terminal
		execlp("sh","sh","-c",s,(char *)0);           // exec user command
		exit(127);
	}
	close(tty);          // also don't forget to close terminal here

	// store previous signal handler into istat and qstat
	istat = signal(SIGINT,SIG_IGN);       // ignore SIGINT in parent process
	qstat = signal(SIGQUIT,SIG_IGN);      // ignore SIGQUIT in parent process
	
	// parent process suck self and wait child process to exit
	// parameter status of wait() is used to store exit message
	// wait() return process id of child
	while((w = wait(&status))!=pid && w!=-1){
		;
	}
	if(w == -1)
		status = -1;
	signal(SIGINT,istat);      // set back to default handler
	signal(SIGQUIT,qstat);
	return status;
}
```
* `extern`: it means var included in other source file, and don't need program to allocate memory for it.  
* The whole process: open terminal -> if in child process then try `execlp()` -> if in parent process then set ignore some signal to avoid some error.  
* We don't need to write signal handler in child process again because it just needs default.

## Reference
The Unix Programming Environment by Brian W.Kernighan and Rob Pike
