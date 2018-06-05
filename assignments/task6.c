//muhammad talha
//p156087
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/sem.h>
#include<semaphore.h>

double balance = 0;
double temp1 = 0;
double temp2 = 0;
int times = 0;


sem_t semaphore;

void *credit(void * arg)
{ 	

	sem_wait(&semaphore);
	
	int a = *(int *) arg;
	printf("%d a gotten\n",a);
	
	int local=balance;
	printf("%d credit local \n",local);
	
	local =local+a;
	sleep(1);
	printf("%d credit local aftre \n",local);
	
	balance = local;
	printf("%f credit balance after \n",balance);
sem_post(&semaphore);
	
}
void *debit(void * arg)
{ 	sem_wait(&semaphore);	
	int a = *(int *) arg;
	printf("%d a gotten\n",a);
	int local=balance;
	printf("%d debit local \n",local);
	local =local-a;
	sleep(1);
	printf("%f Balance Before \n",balance);
	balance = local;
	printf("%f Balance After \n",balance);
	
sem_post(&semaphore);
}
int main()
{ 	int choice;
	sem_init(&semaphore, 0, 1);
	pthread_t credit_thread, debit_thread;
int var=0;
	while(var==0)
	{
		system("clear");
		printf("Name: Alif Noon\nAcc No.: 420\n");
		printf("Available Balance: Rs. %f/-\n", balance);
		printf("\nChoose Transaction Type:\n");
		printf("------------------------\n");
		printf("1. Account Credit\n2. Account Debit\n 3. One Credit + One Debit\n 4. Multiple Credits\n 5. Multiple Debits\n");
		printf("6. Multiple Credit and Debit\n 7. Exit\n");
		scanf("%d", &choice);
		if (choice == 1)
		{ printf("Enter amount to credit\n");
		scanf("%d", &temp1);
		printf("main. balance = %d\n", balance);
		pthread_create(&credit_thread, NULL,
		credit, &temp1);
		}
		else if (choice == 2)
		{ printf("Enter amount to debit\n");
		scanf("%d", &temp2);
		pthread_create(&debit_thread, NULL,debit, &temp2);
		}
		else if (choice == 3)
		{ printf("Enter amount to credit\n");
		scanf("%d", &temp1);
		printf("Enter amount to Debit\n");
		scanf("%d", &temp2);
		pthread_create(&credit_thread, NULL,credit, &temp1);
		pthread_create(&debit_thread, NULL,debit, &temp2);
		}
		else if (choice == 4)
		{ printf("\nHow many times to make credit transaction?");
		scanf("%d", &times);
		printf("Enter amount to credit\n");
		scanf("%d", &temp1);
		int loop;
		for (loop = 0; loop < times; loop++)
		{ pthread_create(&credit_thread, NULL,
		credit, &temp1);
		}
		}
		else if (choice == 5)
		{ printf("\nHow many times to make debit transaction?");
		scanf("%d", &times);
		printf("Enter amount to debit\n");
		scanf("%d", &temp2);
		int loop;
		for (loop = 0; loop < times; loop++)
		{	 pthread_create(&debit_thread, NULL,debit, &temp2);
		}
		}
		else if (choice == 6)
		{ 	printf("Enter amount to credit\n");
			scanf("%d", &temp1);
			printf("Enter amount to Debit\n");
			scanf("%d", &temp2);
			printf("Enter number of times to Credit and Debit\n");
			scanf("%d", &times);
			//pthread_create(&credit_thread, NULL,credit, &temp1);
			int loop;
			for (loop = 0; loop < times; loop++)
			{ 
				//sleep(1);
				pthread_create(&credit_thread, NULL,credit, &temp1);
			}
			for (loop = 0; loop < times; loop++)
			{	 pthread_create(&debit_thread, NULL,debit, &temp2);
			}
		}
		else if (choice == 7)
		{ 
			var=1;
		}
		else
		{ printf("Wrong Choice");
		continue;
		}
	}
	pthread_join(credit_thread, NULL);
	pthread_join(debit_thread, NULL);
	printf("Account Summary:\n----------------\n");
	printf("Available Balance: Rs. %f/-\n", balance);
	exit(0);
}
