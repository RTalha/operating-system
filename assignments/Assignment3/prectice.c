#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int arg,char* argv[])
{	
	FILE *fp=NULL,*fd=NULL;
	fd=fopen(argv[1],"w+");
	fp=fopen(argv[2],"a+");
	if ( fp == NULL || fd == NULL ) {
        printf( "Opening file failed " );
        exit(1);
    }
	char buff[30];
fgets(buff,30,fp);

	while(!(feof(fp)))
{	
	
	fputs(buff,fd);
	printf("%s",buff);
fgets(buff,30,fp);
}

	fclose(fp);
}
