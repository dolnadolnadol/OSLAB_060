#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int msum = 0;
int csum = 0;
void *runner(void *param);
int main(int argc, char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, argv[1]);

	// pthread_join(tid, NULL);
	int upper = atoi(argv[1]);
	if(upper > 0){
		for(int i = 1; i <= upper; i++){
			msum += i;
		}
	}
	
	// if dont have pthread_join maybe csum will late come out
	// line 24 will = 0 but maybe come out when print line 25
	printf("msum = %d  csum = %d\n", msum, csum);
	printf("diff = %d\n", csum - msum);
}

void *runner(void *param){
	int upper = (atoi(param) * 2);
	if(upper > 0){
		for(int i = 1; i <= upper; i++){
			csum += i;
		}
	}
	pthread_exit(0);
}
