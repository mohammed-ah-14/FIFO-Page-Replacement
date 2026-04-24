// OS Homework 2 - FIFO Page Replacement
//                  Name:                  ID:
// (Member 1) -->   Faris Munadhil          U23104246
// (Member 2) -->   Hydyr Babamuradov       U22200809
// (Member 3) -->   Muhammad Azhar          U23102421
// (Member 4) -->   Mohammed Abdul Haris    U23100877
// (Member 5) -->

#include <iostream>
using namespace std;

// ----- Member 2 : FIFO Core Logic (Pointer) -----

    // This function performs the FIFO page replacement
    // When frames are not full → load page into next empty slot
    // When frames are full → replace the oldest page using fifoPointer

void replacePage(int frames[], int framesCount, int &fifoPointer, int &filledFrames, int newPage)
{
    if (filledFrames < framesCount){ // Frames not yet full → insert into next empty slot
        frames[filledFrames] = newPage;
        filledFrames++;

        if (filledFrames == framesCount){ // All frames are now full
            fifoPointer = 0;
        }
    }
    else{ // Frames are full → replace oldest page
        frames[fifoPointer] = newPage;

        fifoPointer = (fifoPointer + 1) % framesCount; // Advance pointer circularly to next oldest slot
    }
}

// ----- Member 3 : Page Fault Detection -----
bool isPageFault(int frames[], int framesCount, int targetPage){
    for (int i = 0; i < framesCount; i++){

        if (frames[i] == targetPage){
            return false;
        }
    }

    return true;
}

int main(){
    // ----- Member 1 : Input & Setup -----

    int framesCount;
    int referenceString[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames[100];
    int pageFaults = 0;

    cout << "Enter number of frames: ";
    cin >> framesCount;

    for (int i = 0; i < framesCount; i++){
        frames[i] = -1;
    }

    int fifoPointer = 0;  // fifoPointer → tracks which frame holds the oldest page
    int filledFrames = 0; // filledFrames → tracks how many frames are currently occupied

    // ----- Member 4 : Simulation Loop -----

    for (int i = 0; i < 12; i++) {  // Loop through all 12 pages in the reference string
        int currentPage = referenceString[i]; // Retrieve the page number at position i

        if (isPageFault(frames, framesCount, currentPage))
        {
            pageFaults++; // Yes → it's a page fault, increment the fault counter

            replacePage(frames, framesCount, fifoPointer, filledFrames, currentPage);
        }
        // If isPageFault returns false → the page is already in memory (page hit)
        // No action needed for a hit; we still print the frame state below

    }

    // ----- Member 5 : Output Formatting -----


    return 0;
}

