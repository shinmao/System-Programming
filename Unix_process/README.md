# Unix system
* process  
* process error handling  
* process signal handling  
* IPC (inter-process-communication)  
* System V IPC v.s. POSIX IPC

## ioctl-winsiz.c
This program is used to receive the signal `SIGWINCH` when window size changes  
![]()  

## system V IPC v.s. POSIX IPC
Two are all I/O protocol of UNIX  
1. UNIX one is portable and newer  
2. POSIX works as library function on file descriptor, system V one works on kernal such as filename. This means every operation of System V requires a context switch. This cause to lower overhead of POSIX than System V.  



