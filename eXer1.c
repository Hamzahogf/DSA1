#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
 
int A(int y) 
{ 
        int total = 0;
        for(int i=0; i<=floor(y/2);i++) total = total + i;
        return total;
}
int B(int y) 
{ 
        int total = 0;
        for(int i=(floor(y/2)+1);i<=y;i++) total = total + i;
        return total;
}


void main (int argc, char *argv[]) {
    int Total = 0; 
    pid_t pid;
    int status;

	//argc contain the number of parameters, argv contains the parameters,, argv[0]: the file name
    if(argc==1 || argc>2) { 
        printf("The program needs one parameter to be executed (e.g., ./a.out 13)\n"); 
        exit(0);
    }
	int x = atoi(argv[1]);
    if (x<=0) { 
        printf("Unvalid parameter: The parameter should be greater than 0, exiting ... \n");
        exit(0);
    }
        
    pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork() system call failed");
		return;
	}

    if (pid != 0) {       
        wait(&status); // & not $
        if (!WIFEXITED(status)) {  
            printf("Child terminated abnormally");
            exit(0);
        } 
        Total = WEXITSTATUS(status) ;
        Total = Total + A(x);
    } else {
        Total = B(x);
        exit(Total);
    }

    if (pid != 0){
        printf("The total is: %d\n",Total) ;
    }
    
    return;
}