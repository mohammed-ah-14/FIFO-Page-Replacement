// OS Homework 2 - FIFO Page Replacement
// Names:Faris munadhil
// IDs:u23104246

#include <iostream>
using namespace std;

int main()
{
    int framesCount;
    int referenceString[12] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int frames[100];
    int pageFaults = 0;

    cout << "Enter number of frames: ";
    cin >> framesCount;

    for (int i = 0; i < framesCount; i++) {
        frames[i] = -1;
    }

    
  

    // ----- Member 2 : FIFO Logic (Pointer) -----

    // ----- Member 3 : Page Fault Detection -----

    // ----- Member 4 : Simulation Loop -----

    // ----- Member 5 : Output Formatting -----

    return 0;
}
