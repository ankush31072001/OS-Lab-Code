//Ans. 3(a)

#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{       
    int pid = fork(); 
    if (pid > 0) 
        printf("in parent process"); 
    else if (pid == 0) 
    { 
        sleep(30); 
        printf("in child process"); 
    } 
    return 0; 
}

//Ans. 3(b)

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main ()
{
  int pid_t child_pid;
  child_pid = fork ();
  if (child_pid > 0) 
  {
      sleep (60);
  }
  else 
  {
      exit (0);
  }
  return 0;
}

//Ans. 3(c) 

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main() 
{ 
    int pid, pid1, pid2;
    pid = fork(); 
    if (pid == 0) 
    { 
        sleep(3); 
        printf("child 1 pid = %d and ppid = %d\n", 
               getpid(), getppid()); 
    } 
    else
    { 
        pid1 = fork(); 
        if (pid1 == 0)
        { 
            sleep(2); 
            printf("child 2  pid = %d and ppid = %d\n", 
                   getpid(), getppid()); 
        } 
        else
        { 
            pid2 = fork(); 
            if (pid2 == 0)
            { 
                printf("child 3  pid = %d and ppid = %d\n", 
                       getpid(), getppid()); 
            } 
            else
            { 
                sleep(3); 
                printf("parent pid = %d\n", getpid()); 
            } 
        } 
    } 
    return 0; 
}
