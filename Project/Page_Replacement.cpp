/**
 * Project: Page Replacement Algorithm Simulator
 * Language: C++
 * Environment: Linux (GCC)
 * Description: Simulates FIFO, LRU, and Optimal page replacement algorithms
 * to calculate page faults and hits.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
#include <map>

using namespace std;

// Function to print current frame status
void printFrames(const vector<int>& frames) {
    for (int f : frames) {
        if (f == -1) cout << "[ ] ";
        else cout << "[" << f << "] ";
    }
    cout << endl;
}

// 1. FIFO Algorithm
void calculateFIFO(int framesCount, const vector<int>& pages) {
    cout << "\n--- FIFO Algorithm ---\n";
    vector<int> frames(framesCount, -1);
    int pageFaults = 0;
    int index = 0; // Points to the oldest page

    for (int page : pages) {
        bool hit = false;
        // Check if page exists
        for (int f : frames) {
            if (f == page) {
                hit = true;
                break;
            }
        }

        if (hit) {
            cout << "Page " << page << ": HIT  -> ";
        } else {
            cout << "Page " << page << ": MISS -> ";
            frames[index] = page;
            index = (index + 1) % framesCount; // Circular increment
            pageFaults++;
        }
        printFrames(frames);
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}


void calculateLRU(int framesCount, const vector<int>& pages) {
    cout << "\n--- LRU Algorithm ---\n";
    vector<int> frames(framesCount, -1);
    int pageFaults = 0;
    
    
    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];
        bool hit = false;
        
        for (int f : frames) {
            if (f == currentPage) {
                hit = true;
                break;
            }
        }

        if (hit) {
            cout << "Page " << currentPage << ": HIT  -> ";
        } else {
            cout << "Page " << currentPage << ": MISS -> ";
            bool placed = false;
            
            // Check for empty slot first
            for(int j=0; j<framesCount; j++) {
                if(frames[j] == -1) {
                    frames[j] = currentPage;
                    placed = true;
                    pageFaults++;
                    break;
                }
            }

            // If no empty slot, find LRU
            if(!placed) {
                int lruIndex = -1;
                int val = 999999;
                
                for(int j=0; j<framesCount; j++) {
                    // Find when frames[j] was last seen in pages[0...i-1]
                    int lastSeen = -1;
                    for(int k=i-1; k>=0; k--) {
                        if(pages[k] == frames[j]) {
                            lastSeen = k;
                            break;
                        }
                    }
                    if(lastSeen < val) {
                        val = lastSeen;
                        lruIndex = j;
                    }
                }
                frames[lruIndex] = currentPage;
                pageFaults++;
            }
        }
        printFrames(frames);
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}

// 3. Optimal Algorithm
void calculateOptimal(int framesCount, const vector<int>& pages) {
    cout << "\n--- Optimal Algorithm ---\n";
    vector<int> frames(framesCount, -1);
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int currentPage = pages[i];
        bool hit = false;
        for (int f : frames) {
            if (f == currentPage) {
                hit = true;
                break;
            }
        }

        if (hit) {
            cout << "Page " << currentPage << ": HIT  -> ";
        } else {
            cout << "Page " << currentPage << ": MISS -> ";
            bool placed = false;
             // Check empty
            for(int j=0; j<framesCount; j++) {
                if(frames[j] == -1) {
                    frames[j] = currentPage;
                    placed = true;
                    pageFaults++;
                    break;
                }
            }
            
            if(!placed) {
                // Find the page that will not be used for the longest time
                int farthest = -1;
                int replaceIndex = -1;

                for(int j=0; j<framesCount; j++) {
                    int nextUse = -1;
                    for(int k=i+1; k<pages.size(); k++) {
                        if(pages[k] == frames[j]) {
                            nextUse = k;
                            break;
                        }
                    }
                    
                    if(nextUse == -1) {
                        replaceIndex = j;
                        break; 
                    } else {
                        if(nextUse > farthest) {
                            farthest = nextUse;
                            replaceIndex = j;
                        }
                    }
                }
                if(replaceIndex == -1) replaceIndex = 0; // Default safety
                frames[replaceIndex] = currentPage;
                pageFaults++;
            }
        }
        printFrames(frames);
    }
    cout << "Total Page Faults: " << pageFaults << endl;
}

int main() {
    int frames, n, choice;
    cout << "========================================================================================================================\n";
    cout << "  				\tOS PROJECT: PAGE REPLACEMENT (Group 11)\n";
    cout << "========================================================================================================================\n";
    cout << "Enter number of Frames (Like 5): ";
    cin >> frames;
    cout << "Enter number of Pages (like 2): ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the Page Reference String (space separated): ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. FIFO (First In First Out)\n";
        cout << "2. LRU (Least Recently Used)\n";
        cout << "3. Optimal Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: calculateFIFO(frames, pages); break;
            case 2: calculateLRU(frames, pages); break;
            case 3: calculateOptimal(frames, pages); break;
            case 4: cout << "Exiting..."; break;
            default: cout << "Invalid Choice!";
        }
    } while (choice != 4);

    return 0;
}
