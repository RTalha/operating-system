#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ     27

main()
{
    int shmid,i=0;
    key_t key;
    char *shmm, *t;
    key = 1000;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shmm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
	*shmm = '!';
	while(*shmm!='*')
	{		
		char b[100];
		printf("mesaage to send (*to end):");
		gets(b);
		if(b[0]!='*'){
			t = shmm+1;
			for (i=0;i<strlen(b);i++)
				 *t++ = b[i];
			*t = NULL;
			*shmm = '@';

			while(*shmm!='#'&&*shmm!='*')
				sleep(1);

			if(*shmm!='*'){
				printf("client:");
				for (t = shmm+1; *t != NULL; t++)
					putchar(*t);
				putchar('\n');
			}else
			printf("connection closed by client");
		}
		else
			*shmm = '*';
	}
	shmid = shmdt(shmm);

    exit(0);
}
