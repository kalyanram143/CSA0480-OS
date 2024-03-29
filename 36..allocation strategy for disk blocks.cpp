#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

typedef struct Block {
    int data;
    struct Block *next;
} Block;

typedef struct File {
    Block *firstBlock;
    Block *lastBlock;
} File;

void addBlock(File *file, int data) {
    Block *newBlock = (Block *)malloc(sizeof(Block));
    newBlock->data = data;
    newBlock->next = NULL;

    if (file->firstBlock == NULL) {
        file->firstBlock = newBlock;
        file->lastBlock = newBlock;
    } else {
        file->lastBlock->next = newBlock;
        file->lastBlock = newBlock;
    }
}

void printBlocks(File *file) {
    Block *currentBlock = file->firstBlock;
    while (currentBlock != NULL) {
        printf("%d ", currentBlock->data);
        currentBlock = currentBlock->next;
    }
    printf("\n");
}

int main() {
    File files[MAX_BLOCKS];
    int numFiles = 0;
    int choice, fileIndex, data;

    while (1) {
        printf("\nLinked Allocation File Strategy Simulation\n");
        printf("1. Create file\n");
        printf("2. Add block to file\n");
        printf("3. Read blocks of file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numFiles < MAX_BLOCKS) {
                    files[numFiles].firstBlock = NULL;
                    files[numFiles].lastBlock = NULL;
                    printf("File created.\n");
                    numFiles++;
                } else {
                    printf("Maximum number of files reached.\n");
                }
                break;

            case 2:
                printf("Enter file index: ");
                scanf("%d", &fileIndex);
                if (fileIndex >= 0 && fileIndex < numFiles) {
                    printf("Enter data for block: ");
                    scanf("%d", &data);
                    addBlock(&files[fileIndex], data);
                    printf("Block added to file.\n");
                } else {
                    printf("Invalid file index.\n");
                }
                break;

            case 3:
                printf("Enter file index: ");
                scanf("%d", &fileIndex);
                if (fileIndex >= 0 && fileIndex < numFiles) {
                    printf("Blocks of file %d: ", fileIndex);
                    printBlocks(&files[fileIndex]);
                } else {
                    printf("Invalid file index.\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
