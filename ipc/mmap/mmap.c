#include<stdio.h>
#include<stdlib.h> // for exit()
#include<sys/mman.h> // for mmap()
#include <string.h> // for strcpy()
int main()
{
FILE *fd;
void *memptr;

fd=fopen("test.txt","r+");
if(fd == NULL)
{
printf("opening file failed\n");
exit(255);
}
printf("file opened success\n");

memptr = mmap(NULL,100,PROT_WRITE|PROT_READ,MAP_SHARED,fd,NULL);
if (memptr == MAP_FAILED)
{
  printf("mem map failed!!\n");
}
printf("memmap success %x\n",memptr);

//*memptr="chal";
strncpy(memptr,"CHAL HAT",8);

return 0;
}
