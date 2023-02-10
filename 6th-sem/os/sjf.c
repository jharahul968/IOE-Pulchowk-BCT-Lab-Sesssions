#include<stdio.h>
struct ff
{
int pid,ser,wait;
}p[20];

struct ff tmp;
main()
{
int i,n,j,tot=0,avwait,totwait=0,tturn=0,aturn;
printf("enter the number of process");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter process id");
scanf("%d",&p[i]);
printf("enter service time");
scanf("%d",&p[i].ser);
p[i].wait=0;
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].ser>p[j].ser)
{
tmp=p[i];
p[i]=p[j];
p[j]=tmp;
}
}
}
printf("PID\tSER\tWAIT\tTOT\n");
for(i=0;i<n;i++)
{
tot=tot+p[i].ser;
tturn=tturn+tot;
p[i+1].wait=tot;
totwait=totwait+p[i].wait;
printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].ser,p[i].wait,tot);
}
avwait=totwait/n;
aturn=tturn/n;
printf("TOTAL WAITING TIME :%d\n",totwait);
printf("AVERAGE WAITING TIME : %d\n",avwait);
printf("TOTAL TURNAROUND TIME :%d\n",tturn);
printf("AVERAGE TURNAROUND TIME:%d\n",aturn);
}