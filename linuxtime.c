/*********************************************************************
* Week 7 Linux Assignment
* Beatriz Mazati Anderson
*  February 28th, 2018
* linuxtime.c
* The main objective of this program is calculate the amount of time
* that the cpu utilized to perform arithmetic steps from the function
* work().
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

void work();
void work()
{
    double y;
    double x = 3.0;
    double e = 2.0;
    int i,j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 400000; j++)
        {
            y = pow(x, e);
        }
    printf("Loop %d of work cycle", i );
    // pause for one second between loops so that the work cycle takes a little time.
    sleep (1);
    }
}



int main()
{
FILE *fptr;

float uptime_Before; // for token_1
float idletime_Before; // for token_2
// specifies what files need to be opened
float uptime_After;
float idletime_After;
int bytes_read;
char*my_string=(char*)malloc(256);
int nbytes = 255;

fptr = fopen("/proc/uptime", "r");
// if the first file is incorrect, it is not possible to get info
if (fptr == NULL)
{
	printf ("Cannot get information");
	return 0;
}

   puts ("Please enter a line of text.");

bytes_read = getline (&my_string, &nbytes, fptr);
fclose(fptr);

  if (bytes_read == -1)
    {
      puts ("ERROR Before!");
      return;
    }
  else
    {
      puts ("You typed:");
      puts (my_string);
    }
// tokenization

sscanf(my_string, "%d %d", &uptime_Before, &idletime_Before);
printf("uptime=%.2f idleTime=%.2f", uptime_Before,idletime_Before);





  work();

fptr = fopen("/proc/uptime", "r");

  bytes_read = getline (&my_string, &nbytes, fptr);

  if (bytes_read == -1)
    {
      puts ("ERROR After!");
      return;
    }
  else
    {
      puts ("You typed:");
      puts (my_string);
    }


sscanf(my_string, "%f %f", &uptime_After, &idletime_After);

printf("\nAfterL uptime=%.2f idleTime=%.2f\n", uptime_After,idletime_After);
//formula for percent utlization
// Step 1: Compute Idle time faction
float programTotalTime = uptime_After-uptime_Before;
float programIdleTime = idletime_After-idletime_Before;
float programCPUTime = programTotalTime - programIdleTime;
float cpu_time_perentage = (programCPUTime/programTotalTime)*100;

printf("\nprogramTotalTime: %f: \n ",programTotalTime) ;
printf("programIdleTime: %f: \n ",programIdleTime) ;
printf("programCPUTime: %f: \n ",programCPUTime) ;
printf("cpu_time_perentage: %f: \n ",cpu_time_perentage) ;


  printf(" Percent Utilization = %.2f",cpu_time_perentage);
 // prints utilization
  return 0;
}

