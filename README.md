# Applied-OS-Using-C-Programming-
A repository showcasing C programs for Applied Operating System concepts, including MUTEX, process synchronization, scheduling algorithms, SRTF, and system calls. Explore source codes demonstrating key OS principles with practical examples.

This repository contains C programs demonstrating concepts of Applied Operating Systems, including:
- MUTEX
- Process Synchronization
- Scheduling Algorithms
- Shortest Remaining Time First (SRTF)
- System Calls

These examples are designed to help understand and implement fundamental OS principles in C.

---

## Prerequisites

### MINGW Installation for C Programming
To compile and run C programs on Windows, you'll need to install MINGW (Minimalist GNU for Windows):

1. **Download MINGW**:
   - Visit the [MINGW website](https://sourceforge.net/projects/mingw/) and download the setup installer.

2. **Install MINGW**:
   - Run the installer and select `gcc` (GNU Compiler Collection) during the installation process.
   - Complete the installation and ensure the `bin` folder (e.g., `C:\MinGW\bin`) is added to your system's `PATH` environment variable.

3. **Verify Installation**:
   - Open a terminal and type:
     ```bash
     gcc --version
     ```
   - You should see the version details of GCC, confirming the setup.

---

## Header Files and Their Purpose in the Programs

### Common Header Files Used
Ensure the following header files are included in your programs as needed:

- **`<stdio.h>`**: Provides input/output functions like `printf` and `scanf`.
- **`<stdlib.h>`**: Contains utility functions like `malloc`, `free`, and program control (e.g., `exit`).
- **`<pthread.h>`**: Required for handling threads and implementing MUTEX and process synchronization.
- **`<unistd.h>`**: Provides access to POSIX operating system API functions like `fork`, `exec`, and `sleep`.
- **`<sys/types.h>`** and **`<sys/wait.h>`**: Used for system calls and process control functions like `wait`.
- **`<string.h>`**: For string handling functions like `strlen` and `strcpy`.
- **`<time.h>`**: Useful for timing and scheduling-related functions.

---

## Concepts Explained

### 1. MUTEX
MUTEX (Mutual Exclusion) is used to prevent race conditions in multithreaded programs. It ensures that only one thread accesses critical sections of the code at a time.

### 2. Process Synchronization
This involves coordinating processes to ensure correct sequencing of operations. Techniques like semaphores and condition variables are used for this purpose.

### 3. Scheduling Algorithms
Various CPU scheduling algorithms, such as:
- **FCFS (First Come First Serve)**
- **SJF (Shortest Job First)**
- **Round Robin (RR)**

These algorithms determine the order in which processes execute to optimize performance metrics like turnaround time and CPU utilization.

### 4. SRTF (Shortest Remaining Time First)
A preemptive version of SJF, where the process with the shortest remaining execution time is given priority. It is useful for time-critical applications.

### 5. System Calls
System calls are the interface between a program and the operating system, enabling functionalities like process control (`fork`, `exec`), file manipulation (`open`, `read`, `write`), and more.

---

## Usage

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/your-repo.git](https://github.com/Rabin-Mishra/Applied-OS-Using-C-Programming-.git
   ```

2. Compile any program:
   ```bash
   gcc -o program_name program_name.c -lpthread
   ```

3. Run the compiled program:
   ```bash
   ./program_name
   ```

---

## Contributing
Feel free to contribute by creating issues or submitting pull requests. Ensure your code follows proper formatting and includes comments for clarity.

---

## License
This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
```

