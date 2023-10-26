#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, frames, pageFaults = 0;
    
    printf("Enter the number of page frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int referenceString[n];
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &referenceString[i]);
    }
    
    int pageTable[frames];
    for (int i = 0; i < frames; i++) {
        pageTable[i] = -1; // Initialize page table with -1 (indicating an empty frame)
    }
    
    int framePointer = 0;
    
    printf("\nPage Replacement Steps:\n");
    for (int i = 0; i < n; i++) {
        int currentPage = referenceString[i];
        int pageFound = 0;
        
        // Check if the current page is already in a frame
        for (int j = 0; j < frames; j++) {
            if (pageTable[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }
        
        if (!pageFound) {
            printf("Page %d -> Page Fault\n", currentPage);
            pageTable[framePointer] = currentPage;
            framePointer = (framePointer + 1) % frames;
            pageFaults++;
        } else {
            printf("Page %d -> No Page Fault\n", currentPage);
        }
    }
    
    printf("\nTotal Page Faults: %d\n", pageFaults);
    
    return 0;
}
