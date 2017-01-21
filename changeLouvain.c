#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp;
int main(int argc, char ** argv)
{
//FILE *fp;
int n=atoi(argv[3]);
//printf("Enter the no. of communities in the cover fed to louvain \n");
//scanf("%d",&n);
int *array=(int*)calloc(n+1,sizeof(int));
int a,b,i=-1,k,l=-1;
int count=0,j;
char filename[50]="",filename1[50]="";
strcat(filename,argv[1]);
//printf("Enter membership file \n");
//scanf("%s",filename);
//printf("Enter storage file \n");
//scanf("%s",filename1);
strcat(filename1,argv[2]);
fp=fopen(filename,"r");
while(fscanf(fp,"%d %d",&a,&b)!=EOF)
{
	array[++i]=b;
}
fclose(fp);
fp=fopen(filename1,"w+");
for(i=1;i<=n;i++)
{
	k=array[i];
	if(k==-1)
		continue;
	else
	{++count;
	for(j=1;j<=n;j++)
	{
		if(array[j]==k)
		{
			array[j]=-1;
			fprintf(fp,"%d ",j);
		}
	}
	fprintf(fp,"%d\n",l);
	}
}
fclose(fp);
printf("Number of Communities finally detected : %d\n",count);
}

