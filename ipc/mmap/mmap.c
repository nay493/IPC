#include<stdio.h>
#include<stdlib.h> // for exit()
#include<sys/mman.h> // for mmap()
#include <string.h> // for strcpy()
// for fstat
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
// for fstat


int main()
{
//FILE *fd;
int fd;
void *memptr;
struct stat *stat_ptr;
int fstatd;

fd=fopen("test.txt","r+");
if(fd == NULL)
{
printf("opening file failed\n");
exit(255);
}
printf("file opened success\n");

if(fstatd=fstat(fd,stat_ptr)==0)
{
printf("fstat.size=%lu\n",stat_ptr->st_size);
}


memptr = mmap(NULL,stat_ptr->st_size,PROT_WRITE|PROT_READ,MAP_SHARED,fd,NULL);
if (memptr == MAP_FAILED)
{
  printf("mem map failed!!\n");
}
printf("memmap success %x\n",(int)memptr);

//*memptr="chal";
strcpy(memptr,"CHALHAT");

return 0;
}
