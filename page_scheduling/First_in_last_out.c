#include <stdio.h>
#include <stdlib.h>

int main() {
    int capacity, frames;
    printf("Enter the capacity of the page table: ");
    scanf("%d", &capacity);
    
    int *pageTable = (int *)malloc(capacity * sizeof(int));
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int frame[frames];
    int rear = -1;
    
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }
    
    int page, pageFaults = 0;
    printf("Enter the reference string, -1 to end: ");
    
    while (1) {
        scanf("%d", &page);
        if (page == -1) {
            break;
        }
        
        int pageFound = 0;
        for (int i = 0; i < frames; i++) {
            if (frame[i] == page) {
                pageFound = 1;
                break;
            }
        }
        
        if (!pageFound) {
            if (rear < frames - 1) {
                rear++;
                frame[rear] = page;
            } else {
                int replaceIndex = 0;
                frame[replaceIndex] = page;
            }
            pageFaults++;
        }
    }
    
    printf("Page Faults: %d\n", pageFaults);
    
    free(pageTable);
    
    return 0;
}
