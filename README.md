📖 Overview

This project is a C++ simulation tool designed to demonstrate and compare the efficiency of various **Page Replacement Algorithms** used in Operating System memory management. 

The program simulates how the OS manages page frames in RAM, visualizes page hits and misses, and calculates the total page faults for different reference strings. This tool is useful for analyzing the behavior of **FIFO**, **LRU**, and **Optimal** algorithms.

 🚀 Features
- **Interactive CLI:** User-friendly menu-driven interface.
- **Visual Simulation:** Displays the state of memory frames step-by-step.
- **Algorithm Support:**
  - **FIFO (First-In-First-Out):** Replaces the oldest page in memory.
  - **LRU (Least Recently Used):** Replaces the page that hasn't been used for the longest time.
  - **Optimal (Belady's Algorithm):** Replaces the page that will not be used for the longest period in the future.
- **Performance Metrics:** Calculates and outputs total page faults for comparison.

 🛠️ Prerequisites

To compile and run this project, you need:
- A Linux environment (Ubuntu, Fedora, Kali, or WSL on Windows).
- **GCC Compiler** (G++) installed.

 📦 Installation & Usage

1. **Clone or Download the Repository**
   ```bash
   git clone [https://github.com/your-username/page-replacement-sim.git](https://github.com/your-username/page-replacement-sim.git)
   cd page-replacement-sim
**Compile the Source Code Use the G++ compiler to build the executable.**

g++ main.cpp -o page_simulator

**Run the Application**

./page_simulator

📖 Usage Example
Step 1: Enter the number of Frames (RAM size) and the number of Pages. Step 2: Input the Reference String (space-separated). Step 3: Choose an algorithm from the menu.

Enter number of Frames: 3
Enter number of Pages: 5
Enter the Page Reference String: 4 1 2 4 5

--- FIFO Algorithm ---
Page 4: MISS -> [4] [ ] [ ] 
Page 1: MISS -> [4] [1] [ ] 
Page 2: MISS -> [4] [1] [2] 
Page 4: HIT  -> [4] [1] [2] 
Page 5: MISS -> [5] [1] [2] 

Total Page Faults: 4

👥 Authors
   Mujtaba Hassan 
   //This project is for Semester Projectt




