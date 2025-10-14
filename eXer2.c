#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main (){
	pid_t pid_0, pid_1, pid_2, pid_3;
	int status;

	pid_1 = fork();
	if(pid_1 < 0) goto X;
    if(pid_1 != 0) pid_2 = fork();
    if((pid_1 != 0) && (pid_2 < 0)) goto X;
    if((pid_1 != 0) && (pid_2 != 0)) pid_3 = fork();
    if((pid_1 != 0) && (pid_2 != 0) && (pid_3 < 0)) goto X;
	
	if(pid_1==0 || pid_2==0 || pid_3==0){  
		//and the name of the executable file in the "Y"-field, e.g., replace "X" with "/home/xyz/Desktop/Lab1/count.out" and "Y" with "./count.out" 
		execl("C:\Users\hp\Desktop\cppp\count.out",".\count.out", NULL);
		printf("Process[%d]: Failed to execute execl()\n",getpid());
	} else {

		printf("Parent process waiting for its children to terminate ...\n");
		pid_0 = wait(&status);
		printf("Parent[%d]: child %d has terminated (status=%d)\n",getpid(),pid_0,WIFEXITED(status));
		pid_0 = wait(&status);
        printf("Parent[%d]: child %d has terminated (status=%d)\n",getpid(),pid_0, WIFEXITED(status));
		pid_0 = wait(&status);
        printf("Parent[%d]: child %d has terminated (status=%d)\n",getpid(),pid_0, WIFEXITED(status));
		//parent process sleeps for 1 second to give time to its child processes to display their outputs.
		sleep(1);
		printf("Parent process terminated.\n");
	}

X: return 0;
}