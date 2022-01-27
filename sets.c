#include<stdio.h>
#include<stdlib.h>
#define M 5

int Create(int s[]);
void Display(int s[],int x);

int Union(int s1[],int s2[],int s3[],int m,int n);
int Intersection(int s1[],int s2[],int s3[],int m,int n);
int Difference(int s1[],int s2[],int s3[],int m,int n);
int Symm_Difference(int s1[],int s2[],int s3[],int m,int n);

int main()
{
	int s1[M],s2[M],s3[M],m,n,k=0;
	int ch;
  char co;	
    printf("\nCreating first Set: ");
			m=Create(s1);
			printf("\nCreating second Set: ");
			n=Create(s2);
      printf("\nFirst Set is: ");
			Display(s1,m);
			printf("\nSecond Set is: ");
			Display(s2,n);
      printf("\n\t********MENU********");
		printf("\n\t1.Union");
		printf("\n\t2.Intersection");
		printf("\n\t3.Difference");
		printf("\n\t4.Symmentric Difference");
		printf("\n\t5.Quit");
		printf("\n\n\tEnter your choice: ");
		scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			printf("\nUnion of set is: ");
			k=Union(s1,s2,s3,m,n);
			Display(s3,k);
			break;
			
		case 2:
			printf("\nIntersection of Set is: ");
			k=Intersection(s1,s2,s3,m,n);
			Display(s3,k);
			break;
		case 3:
			printf("\nDifference of Set is: ");
			k=Difference(s1,s2,s3,m,n); 
			Display(s3,k);
			break;
		case 4:
			printf("\nSymmentric Difference of Set: ");
			k=Symm_Difference(s1,s2,s3,m,n);
			Display(s3,k);
			break;
		case 5:exit(0);
		default:
			printf("\n!! Invalid Choice !!");
			break;
	}
  for (;;)
    {
      printf("\nContinue [YN]? ");
      scanf(" %c",&co);
      if (co == 'Y')
          return main(); 
      else if (co == 'N')
          return 0;
    }
}
int Create(int s[])
{
	int n,i,x;
	printf("\nEnter no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d set of elements: ",n);
	for(i=0;i<n;i++)
	scanf("%d",&s[i]);
	return(n);
}
void Display(int s[],int x)
{
	int i;
	printf("\t{");
	for(i=0;i<x;i++)
	printf(" %d ",s[i]);
	printf("}");
}
int Union(int s1[],int s2[],int s3[],int m,int n)
{
	int i,j,f,k=0;
	for(i=0;i<m+n;i++)
	{
		s3[i]=0;
	}
	for(i=0;i<m;i++)
	{
		s3[k]=s1[i];
		k++;
	}
	for(i=0;i<n;i++)
	{
	f=0;
		for(j=0;j<m;j++)
		{
			if(s2[i]==s1[j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			s3[k]=s2[i];
			k++;
		}
	}
	return(k);
}
int Intersection(int s1[],int s2[],int s3[],int m,int n)
{
	int i,j,f,k=0;
	for(i=0;i<m+n;i++)
	{
		s3[i]=0;
	}
	for(i=0;i<n;i++)
	{
		f=1;
		for(j=0;j<n;j++)
		{
			if(s1[i]==s2[j])
			{
				f=0;
				break;
			}
		}

	if(f==0)
	{
		s3[k]=s1[i];
		k++;
	}
	}
return(k);
}
int Difference(int s1[],int s2[],int s3[],int m,int n)
{
	int i,j,k=0,f;
	for(i=0;i<m+n;i++)
	{
		s3[i]=0;
	}
	for(i=0;i<m;i++)
	{
		f=0;
		for(j=0;j<n;j++)
		{
			if(s1[i]==s2[j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{	
			s3[k]=s1[i];
			k++;
		}
	}
return(k);
}
int Symm_Difference(int s1[],int s2[],int s3[],int m,int n)
{
	int i,j,k=0,f;
	for(i=0;i<m+n;i++)
	{
		s3[i]=0;
	}
	for(i=0;i<m;i++)
	{
		f=0;
		for(j=0;j<n;j++)
		{
			if(s1[i]==s2[j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			s3[k]=s1[i];
			k++;
		}
	}
	for(i=0;i<n;i++)
	{
		f=0;
		for(j=0;j<m;j++)
		{
			if(s2[i]==s1[j])
			{	
				f=1;
				break;
			}
		}
		if(f==0)
		{
			s3[k]=s2[i];
			k++;
		}
	}
return(k);
}
