#include<unistd.h>
#include<stdio.h>
#include<string.h>
void main()
{
	int fd[2];
	int fd2[2];
	pipe(fd);
	pipe(fd2);
	char *temp1 ="hello";
		printf("%s",temp1);
	
	if(fork()==0)    //child
	{
		close(fd[0]);
		write(fd[1],temp1,6);
		close(fd[1]);
		
		sleep(1);
		while(1)
		{
			sleep(1);
			read(fd[0],temp1,6);
			close(fd[1]);
			if(!(strcmp(temp1,"chalo")))
			{	printf("this is child \n");
				close(fd2[1]);
				char buff_r[13];
				read(fd2[0],buff_r,13);
				close(fd2[0]);
				printf("parent said : %s \n",buff_r);
				

				char buff_w[13];
				scanf("%s",buff_w);	
				write(fd2[1],buff_w,sizeof(buff_w));

					temp1 = "heloo";					
					write(fd[1],temp1,6);
			
									
			}
			sleep(1);
		}
	}
	else    //parent
	{
		while(1)
		{
				close(fd[1]);
				read(fd[0],temp1,6);
				if(!(strcmp(temp1,"hello")))
				{	printf("this is parent \n");
					char buff_w[13];
					scanf("%s",buff_w);
					printf("%s",buff_w);
					
					close(fd[0]);
					write(fd2[1],buff_w,sizeof(buff_w));
					close(fd[1]);
					
					printf("2");
					temp1 = "chalo";	
					
					printf("%s",temp1);				
					write(fd[1],temp1,6);

					sleep(2);
					
				}
				if(!(strcmp(temp1,"heloo")))
				{
					char buff_r[13];
					read(fd2[0],buff_r,13);
					printf("child said : %s \n",buff_r);


					char buff_w[13];
					scanf("%s",buff_w);	
					write(fd2[1],buff_w,sizeof(buff_w));

					temp1 = "chalo";					
					write(fd[1], temp1, 6);
					sleep(2);
				}
				close(fd[0]);	
			
		}
	}
}
