#include <stdio.h>
struct process
{

int id,wait,ser,tottime;
}p[20];
main()
{
int i,n,j,totalwait=0,totalser=0,avturn,avwait;
printf("enter number of process");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("enter process_id");
scanf("%d",&p[i].id);
printf("enter process service time");
scanf("%d",&p[i].ser);
}
p[1].wait=0;
p[1].tottime=p[1].ser;
for(i=2;i<=n;i++)
{
for(j=1;j<i;j++)
{
p[i].wait=p[i].wait+p[j].ser;
}
totalwait=totalwait+p[i].wait;
p[i].tottime=p[i].wait+p[i].ser;
totalser=totalser+p[i].tottime;
}
avturn=totalser/n;
avwait=totalwait/n;
printf("Id\tservice\twait\ttotal");
for(i=1;i<=n;i++)
{
printf("\n%d\t%d\t%d\t%d\n",p[i].id,p[i].ser,p[i].wait,p[i].tottime);
}
printf("average waiting time %d\n",avwait);
printf("average turnaround time %d\n",avturn);
}