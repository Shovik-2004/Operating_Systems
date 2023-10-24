// Implementing LRU is more complex and may require data structures like linked lists.
// Here's a simplified example using arrays.

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
    int lruCount[frames];
    
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        lruCount[i] = 0;
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
                lruCount[i] = 0;
            } else {
                lruCount[i]++;
            }
        }
        
        if (!pageFound) {
            int lruIndex = 0;
            for (int i = 0; i < frames; i++) {
                if (lruCount[i] > lruCount[lruIndex]) {
                    lruIndex = i;
                }
            }
            frame[lruIndex] = page;
            lruCount[lruIndex] = 0;
            pageFaults++;
        }
    }
    
    printf("Page Faults: %d\n", pageFaults);
    
    free(pageTable);
    
    return 0;
}
