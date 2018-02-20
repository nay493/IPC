#include<stdio.h>
#include<signal.h> // for sigaction()

/*
 * command to find where gcc looks for headers:
 * $ `gcc -print-prog-name=cc1` -v
 *
 *
 * */


int main()
{
int *p=NULL,ret;
struct sigaction sa;
ret=sigaction(SIGSEGV, &sa, NULL);
if(ret == 0)
{
printf("sigaction success\n");
}
else
{
printf("sigaction failed!!\n");
}
*p=25;

return 0;
}
