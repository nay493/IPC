#include<stdio.h>
#include<signal.h> // for sigaction()
#include<string.h> // for memset()
#include<stdlib.h> // for exit()
/*
 * command to find where gcc looks for headers:
 * $ `gcc -print-prog-name=cc1` -v
 *
 *
 * */
#if 0
// No warning but no proper output
void func(int, siginfo_t *, void *);

void func(int signal, siginfo_t *s2, void *arg)
{
printf("Caught segfault address %p\n",s2->si_addr);
exit(0);
}
#endif

// proper output but warning
void func(int, siginfo_t, void *);

void func(int signal, siginfo_t s2, void *arg)
{
printf("Caught segfault address %p\n",s2.si_addr);
exit(0);
}

int main()
{
int *p=NULL,ret;
struct sigaction sa;

memset(&sa, 0, sizeof(sa)); // init all struct elemnts with zeroes.
sa.sa_sigaction=func;

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
