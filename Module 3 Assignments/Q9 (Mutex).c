#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_t threadid[5];
int count;
pthread_mutex_t mut;

void* sample(void *id){
	int tid = *((int *)id);
	int i;
	for(i=0;i<2;i++){
		pthread_mutex_lock(&mut);
		count++;
		printf("Thread: %d Count: %d \n\n",id,count);
		pthread_mutex_unlock(&mut);
	}
	return NULL;
}

int main(){
	int i=0;
	int thread_ids[5];
	pthread_mutex_init(&mut, NULL);
	
	for(i=0;i<5;i++){
		thread_ids[i] = i;
		pthread_create(&threadid[i], NULL, sample, &thread_ids[i]);
	}
	
	for(i=0;i<5;i++){
		pthread_join(threadid[i], NULL);
	}
	pthread_mutex_destroy(&mut);
	return 0;
}
