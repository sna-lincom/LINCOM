#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp;
int main(int argc, char ** argv)
{
	//FILE *fp;
	FILE *fp,*fp1,*fp2;
	
	int **array,n,n1,**array1;
	int k1,j1,i,comm,i1,max_label; int detected_Comm;
	comm = atoi(argv[1]);
	max_label=atoi(argv[2]);
	//printf("Enter the number of communities after printing rehashing ( initial number fed to louvain )\n");
	//scanf("%d",&comm);
	//printf("Enter the number of nodes in the network\n");
	//scanf("%d",&max_label);
	int *arr1=(int *)calloc(max_label+2,sizeof(int));
	char filename2[50]="",filename1[50]="",filename3[50]="";
	strcat(filename1,argv[3]);
	strcat(filename2,argv[4]);
	strcat(filename3,argv[5]);
	detected_Comm=atoi(argv[6]);
	//printf("\nEnter the membership file (along with extension): ");
	//scanf("%s",filename1);
	//printf("\nEnter the filename which contains cluster of community representatives (along with extension): ");
	//scanf("%s",filename2);
	fp1=fopen(filename2,"r");
	//printf("\nEnter the filename to store final cover (along with extension): ");
	//scanf("%s",filename3);
	fp2=fopen(filename3,"w+");
	/*printf("Enter the number of nodes\n");
	scanf("%d",&n);*/
	array=(int**)calloc(max_label+1,sizeof(int*));
	for(i=0;i<=max_label;i++)
		array[i]=(int*)calloc(10,sizeof(int));
	array1=(int**)calloc(comm+1,sizeof(int*));
	for(i=0;i<=comm;i++)
		array1[i]=(int*)calloc(max_label+1,sizeof(int));
	int a,b,k,l=-1;
	int count=0,j;
	fp=fopen(filename1,"r");
	while(fscanf(fp,"%d %d",&a,&b)!=EOF)
	{
		i=0;
		while(b!=-1)
		{
			array[a][++i]=b;
			fscanf(fp,"%d",&b);
		}
		array[a][0]=i;
	}
	fclose(fp);
	
	int t=0;
	for(i1=1;i1<=comm;i1++)
	{
		for(i=1;i<=max_label;i++)
		{
			for(j=1;j<=array[i][0];j++)
			{
				if(array[i][j]==i1)
				{
					array1[i1][++t]=i;
					break;
				}
			}
		}
		array1[i1][0]=t;
		t=0;
	}

	//int *counter=(int *)calloc(max_label+2,sizeof(int));
	
	
	if(fp1== NULL)
   	{
      		printf("File not found\n");
      		exit(EXIT_FAILURE);
   	}
	fprintf(fp2,"%d \n",max_label);
   	while((fscanf(fp1,"%d ",&n))!=EOF)
   	{
       		if(n!=-1)
       		{
			for(j=1;j<=array1[n][0];j++)
			{
				if(arr1[array1[n][j]]==0)
				{
					fprintf(fp2,"%d ",array1[n][j]);
					//counter[array1[n][j]]++;
					arr1[array1[n][j]]=1;
				}
			}
		}
       		else
       		{	
           		fprintf(fp2,"%d\n",-1);
           		for(i=1;i<=max_label;i++)
    			{
    	    			arr1[i]=0;
    			}
       		}

   	}
    	fclose(fp1);
    	free(arr1);
    	fclose(fp2);
	/*FILE *ab;
	ab=fopen("list_of_ov_nodes.txt","w+");
	for(i=1;i<=max_label;i++)
	{
		if(counter[i]>=2)
			fprintf(ab,"%d %d\n",i,counter[i]);
	}
	fclose(ab);*/
}
















