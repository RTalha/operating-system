//muhammad talha
//p156087
//specific tree with fork();
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
int p=fork();

	if(p>0)
	{
		int d=fork();
		if(d==0)
		{
		printf("parent id is d =0: %d \n",getppid());
		printf("child id is d=0: %d \n",getpid());
		}
		if(d>0)
		{
			int i=fork();
			if(i==0)
			{
				printf("parent id is i=0: %d \n",getppid());
				printf("child id is i=0: %d \n",getpid());
				
			}
		}
	}
	 if(p==0)
	{
		printf("parent id is p =0: %d \n",getppid());
		printf("child id is p=0: %d \n",getpid());
		int j=fork();
		if(j==0)
		{
		printf("parent id is j=0: %d \n",getppid());
		printf("child id is j=0: %d \n",getpid());
		
		}
		 if(j>0)
		{

			int k=fork();
			if(k==0)
			{
				printf("parent id is k=0: %d \n",getppid());
				printf("child id is k=0: %d \n",getpid());
				
			}
		} 
	}
	
	
	

}