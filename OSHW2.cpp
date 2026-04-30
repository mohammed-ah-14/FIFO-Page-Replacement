// OS Homework 2 - FIFO Page Replacement

#include <iostream>
#include <iomanip>
using namespace std;

// ----- Member 2 : FIFO Core Logic ----- 

// This function performs the FIFO page replacement algorithm.
// FIFO (First In First Out) works by keeping track of the order pages were loaded into frames.
// When frames are not full, we load the new page into the next empty slot
// When frames are full, we simply replace the oldest page (the one that was loaded first) using fifoPointer

void replacePage(int frames[], int framesCount, int &fifoPointer, int &filledFrames, int newPage)
{
    if (filledFrames < framesCount) // if there are still empty frames available, we don't need to replace anything yet
    {
        frames[filledFrames] = newPage; // insert the new page into the next empty slot
        filledFrames++;                 // mark one more frame as occupied

        if (filledFrames == framesCount) // check if all frames are now full after this insertion
        {
            fifoPointer = 0; // reset the pointer to 0, so the next replacement starts from the oldest page (the first one loaded)
        }
    }
    else // all frames are full, so we must replace the oldest page
    {
        frames[fifoPointer] = newPage;                 // overwrite the oldest page with the new page
        fifoPointer = (fifoPointer + 1) % framesCount; // move the pointer circularly to the next oldest slot
    }
}

// ----- Member 3 : Page Fault Detection ----- 

// This function checks whether the target page is currently loaded in any of the frames.
// If the page is NOT found in any frame, it is a page fault (returns true).
// If the page IS found then it is a page hit (returns false) — no need to replace.
bool isPageFault(int frames[], int framesCount, int targetPage)
{
    for (int i = 0; i < framesCount; i++)
    {
        if (frames[i] == targetPage) // if the page is already in memory
        {
            return false; // it is a page hit, no fault occurred
        }
    }
    return true; // the page was not found in any frame, so it is a page fault
}

int main()
{
    // ----- Member 1 : Input & Setup ----- 

    int framesCount;
    int referenceString[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; // the fixed sequence of pages that the process will request
    int frames[100];                                                // array to hold the pages currently loaded in memory frames
    int pageFaults = 0;                                             // counter to track how many page faults occur during the simulation

    cout << endl;
    cout << "The Reference String: is [ ";
    for (int i = 0; i < 12; i++)
    {
        cout << referenceString[i] << " "; // print each page number in the reference string
    }
    cout << "]" << endl;

    cout << "Enter Total number of frames: "; // gets the number of frames from the user, determines how many pages can be held at once
    cin >> framesCount;

    for (int i = 0; i < framesCount; i++)
    {
        frames[i] = -1; // initialize all frames to -1 to indicate they are empty at the start
    }

    int fifoPointer = 0;  // fifoPointer -> tracks which frame holds the oldest page (the next one to be replaced)
    int filledFrames = 0; // filledFrames -> tracks how many frames are currently occupied

    // ----- Member 4 : Simulation Loop ----- 

    // Loop through all 12 pages in the reference string one by one
    for (int i = 0; i < 12; i++)
    {
        int currentPage = referenceString[i]; // retrieve the page number being requested at this step

        if (isPageFault(frames, framesCount, currentPage)) // check if this page is already in memory
        {
            pageFaults++;                                                             // the page is not in memory, so it is a page fault — increment the fault counter
            replacePage(frames, framesCount, fifoPointer, filledFrames, currentPage); // load the page into memory using FIFO replacement
        }
        // if isPageFault returns false -> the page is already in memory (page hit)
        // no action needed for a hit we still print the frame state below

        // ----- Member 5 : Output Formatting ----- 
        cout << endl;
        for (int j = 0; j < framesCount; j++)
        {
            cout << "     " << setw(2) << frames[j] << "     ";
        }
    }

    cout << endl;
    cout << endl;
    cout << "Total Page Faults : " << pageFaults << endl; // display the total number of page faults that occurred across all 12 page references

    return 0;
}