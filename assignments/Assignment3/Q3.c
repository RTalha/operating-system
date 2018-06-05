#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



int main(){

FILE *fp;
int numb;
int read;
fp=fopen("File.txt","w+");


if(fp == NULL){
	
	printf("File not opened.\n");
}

else{

	printf("file opened.\n");
}


printf("Enter a number: ");
scanf("%d",&numb);


fwrite(&numb,sizeof(int),1,fp);
flcose(fp);

if(fork() == 0){

fp=fopen("File.txt","r+");
fread(&read,sizeof(int),1,fp);
fclose(fp);
printf("number is: %d\n",read);

int i;
for(i=read-1;i>0;i--){

read=read * i;


}
rewind(fp);
fwrite(&read,sizeof(int),1,fp);

}

else{

sleep(3);
fp=fopen("File.txt","r");
fread(&read,sizeof(int),1,fp);

printf("Factorial of number is: %d\n",read);

}


fclose(fp);
}
