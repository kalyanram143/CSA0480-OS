#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int main() {
    int requests[MAX_REQUESTS];
    int numRequests;
    int headPosition;
    int totalSeekTime = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    printf("Enter the disk requests:\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);

    printf("Disk Scheduling Order:\n");
    printf("%d ", headPosition);
    for (int i = 0; i < numRequests; i++) {
        totalSeekTime += abs(headPosition - requests[i]);
        headPosition = requests[i];
        printf("%d ", headPosition);
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);

    return 0;
}
