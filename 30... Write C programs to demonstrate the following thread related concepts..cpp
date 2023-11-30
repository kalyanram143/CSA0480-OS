1-create
#include <stdio.h>
#include <pthread.h>

void *printMessage(void *message) {
    printf("Thread: %s\n", (char *)message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    const char *message = "Hello from the thread!";
    
    pthread_create(&thread, NULL, printMessage, (void *)message);
    pthread_exit(NULL);
}

2-join
#include <stdio.h>
#include <pthread.h>

void *printMessage(void *message) {
    printf("Thread: %s\n", (char *)message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    const char *message = "Hello from the thread!";
    
    pthread_create(&thread, NULL, printMessage, (void *)message);
    pthread_join(thread, NULL);
    
    printf("Main thread: Thread joined.\n");
    pthread_exit(NULL);
}

3-equal
#include <stdio.h>
#include <pthread.h>

int main() {
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, NULL, NULL);
    pthread_create(&thread2, NULL, NULL, NULL);
    
    if (pthread_equal(thread1, thread2)) {
        printf("Thread identifiers are equal.\n");
    } else {
        printf("Thread identifiers are not equal.\n");
    }
    
    pthread_exit(NULL);
}

4-exit
#include <stdio.h>
#include <pthread.h>

void *printMessage(void *message) {
    printf("Thread: %s\n", (char *)message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    const char *message = "Hello from the thread!";
    
    pthread_create(&thread, NULL, printMessage, (void *)message);
    printf("Main thread: Waiting for thread to finish...\n");
    pthread_join(thread, NULL);
    printf("Main thread: Thread finished.\n");
    pthread_exit(NULL);
}
