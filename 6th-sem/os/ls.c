#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
main(int argc, char *argv[])
{
DIR *dp;
struct dirent *dirp;
if(argc<2)
{
printf("\n You have provided only 1 argument\n");
exit(1);
}
if((dp=opendir(argv[1]))==NULL)
{
printf("\nCannot open %s file!\n",argv[1]);
exit(1);
}
while((dirp=readdir(dp))!=NULL)
printf("%s\n",dirp->d_name);
closedir(dp);
}