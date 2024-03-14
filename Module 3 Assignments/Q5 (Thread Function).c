#include <stdio.h>
#include <pthread.h>

void *disp1(void *arg) {
    printf("Hello\n");
    pthread_exit(NULL);
}

void *disp2(void *arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, disp1, NULL);
    pthread_join(thread1, NULL);
    
    pthread_create(&thread2, NULL, disp2, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}

