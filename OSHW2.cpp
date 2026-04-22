// OS Homework 2 - FIFO Page Replacement
//                       Name:                  ID:
// (Member 1) -->    Faris Munadhil          U23104246
// (Member 2) -->    Hydyr Babamuradov       U22200809
// (Member 3) -->
// (Member 4) -->
// (Member 5) -->

#include <iostream>
using namespace std;

int main()
{
    // ----- Member 1 : Input & Setup -----
    
    int framesCount;
    int referenceString[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames[100];
    int pageFaults = 0;

    cout << "Enter number of frames: ";
    cin >> framesCount;

    for (int i = 0; i < framesCount; i++) {
        frames[i] = -1;
    }


    // ----- Member 2 : FIFO Core Logic (Pointer) -----

int fifoPointer = 0;  // fifoPointer → tracks which frame holds the oldest page
int filledFrames = 0; // filledFrames → tracks how many frames are currently occupied

// This function performs the FIFO page replacement
// When frames are not full → load page into next empty slot
// When frames are full → replace the oldest page using fifoPointer
void replacePage(int frames[], int framesCount, int &fifoPointer, int &filledFrames, int newPage) 
{
    if (filledFrames < framesCount) 
    {   // Frames not yet full → insert into next empty slot
        frames[filledFrames] = newPage;          
        filledFrames++;                          

        if (filledFrames == framesCount) {       // All frames are now full
            fifoPointer = 0;                     
        }

    } else {  // Frames are full → replace oldest page
        frames[fifoPointer] = newPage;                 

        fifoPointer = (fifoPointer + 1) % framesCount; // Advance pointer circularly to next oldest slot
    }
}
    
    // ----- Member 3 : Page Fault Detection -----

    // ----- Member 4 : Simulation Loop -----

    // ----- Member 5 : Output Formatting -----

    return 0;
}
