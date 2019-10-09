/********************************************************************
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
// declares files
FILE *fptr;
char c;
// specifies what files need to be opened
fptr = fopen("/proc/uptime", "r");
// if the first file is incorrect, it is not possible to get info
if (fptr == NULL)
{
printf ("Cannot get information \n");
return 0;
}
// Read contents of file and includes five 'while' loops to access
// and open each file
c = fgetc(fptr);
while (c !=EOF)
{
printf ("%c", c);
c = fgetc (fptr);
} //end loop
// closes opened file
fclose(fptr);
return 0;
} // end main