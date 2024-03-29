#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int main() {
    int indexBlock[MAX_BLOCKS];
    int numBlocks = 0;
    int choice, block;

    while (1) {
        printf("\nFile Allocation Strategy Simulation\n");
        printf("1. Allocate block\n");
        printf("2. Read index block\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numBlocks < MAX_BLOCKS) {
                    printf("Enter block value: ");
                    scanf("%d", &block);
                    indexBlock[numBlocks++] = block;
                    printf("Block allocated.\n");
                } else {
                    printf("File is full. Cannot allocate more blocks.\n");
                }
                break;

            case 2:
                printf("Index block contents:\n");
                for (int i = 0; i < numBlocks; i++) {
                    printf("Index %d: Block %d\n", i, indexBlock[i]);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

