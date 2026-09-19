#include <stdio.h>
#include <unistd.h>


int main()
{
  printf("Before PID= %d",getpid());
  
  pid_t result = fork();
  
  if(result<0)
  {
    printf("PID failed");
    return 1;
  }
  else if (result == 0)
  {
    printf("I am child.\n PID =  %d\n",getpid());
  }
  else
  {
    printf("I am parent.\n PID = %d\n", getpid());
    printf("My child has PID = %d\n", result);
  }
  return 0;
}
