
## Operating System

**What is the main purpose of an operating system? Discuss different types?**

An operating system (OS) is system software that manages computer hardware, software resources, and provides common services for computer programs. So it manages the computer’s memory, processes, devices, files, and security aspects of the system. It also allows us to communicate with the computer without knowing how to speak the computer’s language. Without an operating system, a computer is not useful.

Types of operating system:

- Batch OS
- Distributed OS
- Multitasking OS
- Network OS
- Real-Time OS
- Mobile OS

**What is a socket, kernel and monolithic kernel ?**

- Socket:
A socket is defined as an endpoint for communication, A pair of processes communicating over a network employ a pair of sockets ,one for each process. A socket is identified by an IP address concatenated with a port number.
The server waits for incoming client requests by listening to a specified port. Once a request is received, the server accepts a connection from the client socket to complete the connection.

- Kernel is the central core component of an operating system that manages operations of computer and hardware. Kernel Establishes communication between user level application and hardware. Manages memory and CPU time. Decides state of incoming processes. Controls Disk, Memory, Task Management

- Monolithic Kernel (provides good performance but lots of lines of code)
It is one of the types of kernel where all operating system services operate in kernel space. It has dependencies between system components. It has huge lines of code which is complex.
Example : Unix, Linux, Open VMS, XTS-400 etc.


**Difference between process and program and thread? Different types of process**

- Process:
Process is an instance of an executing program. For example, we write our computer programs in a text file and when we execute this program, it becomes a process which performs all the tasks mentioned in the program.

- Program:
Program is a set of instructions to perform a certain task. Eg: chrome.exe, notepad.exe

- Thread:
Thread is a path of execution within a process. A thread is also known as a lightweight process. The idea is to achieve parallelism by dividing a process into multiple threads. For example,Word processor uses multiple threads: one thread to format the text, another thread to process inputs.


**Define virtual memory, thrashing, threads**

- **Virtual Memory:**
A computer can address more memory than the amount physically installed on the system. This extra memory is actually called virtual memory and it is a section of a hard disk that’s set up to emulate the computer’s RAM.
The main visible advantage of this scheme is that programs can be larger than physical memory. Virtual memory serves two purposes. First, it allows us to extend the use of physical memory by using a disk. Second, it allows us to have memory protection, because each virtual address is translated to a physical address. (Example Swap in Linux)

- **Thrashing:**
Thrashing is a condition or a situation when the system is spending a major portion of its time in servicing the **page faults** <mark>(In computing, a page fault (sometimes called PF or hard fault) is an exception that the memory management unit (MMU) raises when a process accesses a memory page without proper preparations. Accessing the page requires a mapping to be added to the process's virtual address space)</mark> , but the actual processing done is very negligible. High degree of multiprogramming(if number of processes keeps on increasing in the memory), lack of frames (if a process is allocated too few frames, then there will be too many and too frequent page faults) causes Thrashing.

    * **Page** (or memory page, or virtual page, or logical page) is a fixed-length contiguous block of <mark>virtual memory</mark>

    * A **frame** (or memory frame, or physical page, or page frame) is a fixed-length block of <mark>RAM</mark> (ie. physical memory, it exists - as in <mark>physical<mark/>

        * It is the smallest unit of data for memory management in a virtual memory operating system. A frame refers to a storage frame or central storage frame. In terms of physical memory, it is a fixed sized block in physical memory space, or a block of central storage

        

- **Threads:**
A thread is a single sequential flow of execution of tasks of a process so it is also known as thread of execution or thread of control


**What is RAID ? Different types**

RAID, or <mark>Redundant Arrays of Independent Disks</mark> is a technique which makes use of a combination of multiple disks instead of using a single disk for increased performance, data redundancy or both.Data redundancy, although taking up extra space, adds to disk reliability. This means, in case of disk failure, if the same data is also backed up onto another disk, we can retrieve the data and go on with the operation


* **RAID 0**
    * RAID level 0, often called <mark>stripping</mark> The idea behind this level is data to be stored is divided into some parts called strips and loaded these strips across the member of the disk of the array

        * Advantages
            * Very Fast
            * Performance Oriented Disk Mapping Method
            * Performance is better than single drive since the workload is balanced by the array memebers
            * useful for high - performance systems

        * Disadvantages
            * No redundancy of data
            * No fault tolerance
            * any disk member fails, it affects the entire array


* **RAID 1**
    * RAID level 1 uses at least two duplicate hard drives and store the same blocks of information between them. So, it is often called <mark>Mirroring</mark>. If one of the mirrored drives failure due to a mechanical problem or does not respond then the remaining drive will continue to serve and provide correct data.

        * Advantages
            * High Reliability
            * Fault tolerance, recovery from failure is simple
            * Good Performance

        * Disadvantages
            * Costly because of mirroring of data
            * Min 2 drives are required      

* **RAID 2**
    * RAID level is called <mark>Hamming code</mark> The strips are very small at this level, often as small as a single byte or word. The hamming code is calculated across corresponding bit positions on each data disk and the bits of the code are stored in the corresponding bit positions on multiple disks

        * Disadvantages
            * Its rarely implemented (RAID 2 controller was expensive and hard to implement)  


* **RAID 3**
    * RAID level 3 requires only a <mark>single redundant disk</mark>. RAID 3 employs parallel access with data distributed in small strips. Instead of an error corresponding code, a single <mark>parity bit</mark> is computed for the set of individual bits in the same position on all of the data disks. In the event of a drive failure, the parity drive is accessed and data is reconstructed from the remaining devices

        * Advantages
            * RAID 3 can achieve very high data transfer rates
            * Any I/O request will involve the parallel transfer of data from all of the data disks

        * Disadvantages
            * RAID level 3 is also rarely implemented (because of below draw back)
            * Only processes one I/O at a time

* **RAID 4**
    * RAID 4 <mark>stripes</mark> the data across multiple disks just like RAID 0. In addition to that, it also stores <mark>parity information</mark> of all the disks in a separate dedicated disk to achieve redundancy. If one of the data disks failed is the information re-built on a separate disk using the parity information. If the parity disk fails, the parity information is recalculated on a spare disk. It is better suited to the transaction I/O rather than large file transfers.

    * Advantages
            * RAID 4 can recover data from one lost disk


* **RAID 5**
    * It is the most common type of RAID level 5. It distributes the parity strips across all disks. RAID 5 eliminates the write bottlenecks. The only it has is the parity calculations process. But with modern CPUs and software of RAID that is not even a very big bottleneck

        * Advantages
            * Highest (read) data transmission rate
            * Low Ration of ECC (Parity) disks to data disks, means high efficiency.

        * Disadvantages
            * Most Complex controller design
            * Difficult to rebuilt in the event of disk failure
            * High overhead for small writes. to change 1 byte in a file, the entire strip must be read, the byte changed, the parity information recalculated and the entire stripe rewritten


* **RAID 6**
    * In RAID 6 method, two different parity calculations are carried out and stored in separate blocks on different disks. So, this scheme needs N+2 disks (2 for parity).

        * Advantages:
            * Privides extremely high data availability

* There are also other RAID like software RAID and hardware RAID


**What is a deadlock? Different conditions to achieve a deadlock**

A Deadlock is a situation where each of the computer processes waits for a resource which is being assigned to some other process. In this situation, none of the processes gets executed since the resource it needs is held by some other process which is also waiting for some other resource to be released.

How deadlock is achieved: Deadlock happens when Mutual exclusion, hold and wait, No preemption and circular wait occurs simultaneously.

Necessary Conditions for deadlock:

- Mutual Exclusion
- Hold and Wait
- No preemption
- Circular Wait

**What is fragmentation? Types of fragmentation**

The conditions of fragmentation depend on the memory allocation system. As the process is loaded and unloaded from memory, these areas are fragmented into small pieces of memory that cannot be allocated to incoming processes. It is called fragmentation


* Internal Fragmentation

    ![Internal Fragmentation](https://static.javatpoint.com/operating-system/images/internal-vs-external-fragmentation2.png)


* External Fragmentation
    ![External Fragmentation](https://static.javatpoint.com/operating-system/images/internal-vs-external-fragmentation3.png)


**What is spooling ?**

SPOOL is an acronym for <mark>simultaneous peripheral operations online</mark>. Spooling is a process in which data is temporarily held to be used and executed by a device, program, or system.
In spooling, there is no interaction between the I/O devices and the CPU. That means there is no need for the CPU to wait for the I/O operations to take place. Such operations take a long time to finish executing, so the CPU will not wait for them to finish.
The biggest example of Spooling is printing. The documents which are to be printed are stored in the SPOOL and then added to the queue for printing. During this time, many processes can perform their operations and use the CPU without waiting while the printer executes the printing process on the documents one-by-on


**What is semaphore and mutex (Differences might be asked)? Define Binary semaphore**

* Mutex
A mutex provides mutual exclusion, either producer or consumer can have the key (mutex) and proceed with their work. As long as the buffer is filled by the producer, the consumer needs to wait, and vice versa. 
At any point of time, only one thread can work with the entire buffer. The concept can be generalized using semaphore. 
A mutex is a locking mechanism used to synchronize access to a resource. Only one task (can be a thread or process based on OS abstraction) can acquire the mutex. It means there is ownership associated with a mutex, and only the owner can release the lock (mutex). 


* Semaphore (faster than mutex)
A semaphore is a generalized mutex. In lieu of a single buffer, we can split the 4 KB buffer into four 1 KB buffers (identical resources). A semaphore can be associated with these four buffers. The consumer and producer can work on different buffers at the same time. 
Semaphore is signaling mechanism (“I am done, you can carry on” kind of signal). For example, if you are listening to songs (assume it as one task) on your mobile phone and at the same time, your friend calls you, an interrupt is triggered upon which an interrupt service routine (ISR) signals the call processing task to wakeup

* Binary Semaphore
Definition. A Binary Semaphore is a semaphore whose integer value range over 0 and 1. A counting semaphore is a semaphore that has multiple values of the counter. The value can range over an unrestricted domain

<mark>The critical section refers to the segment of code where processes access shared resources, such as common variables and files, and perform write operations on them. Since processes execute concurrently, any process can be interrupted mid-execution</mark>


**Belady’s Anomaly**

Bélády’s anomaly is the name given to the phenomenon where increasing the number of page frames results in an increase in the number of page faults for a given memory access pattern

* Solution to fix Belady’s Anomaly:
Implementing alternative page replacement algo helps eliminate Belady’s Anomaly.. Use of stack based algorithms, such as Optimal Page Replacement Algorithm and Least Recently Used (LRU) algorithm, can eliminate the issue of increased page faults as these algorithms assign priority to pages

**Starving and Aging in OS**

Starving/Starvation(also called Lived lock): Starvation is the problem that occurs when low priority processes get jammed for an unspecified time as the high priority processes keep executing. So starvation happens if a method is indefinitely delayed.

Solution to Starvation : Ageing is a technique of gradually increasing the priority of processes that wait in the system for a long time.

**Why does trashing occur?**

High degree of multiprogramming(if number of processes keeps on increasing in the memory) , lack of frames(if a process is allocated too few frames, then there will be too many and too frequent page faults.) causes Thrashing.

**What is paging and why do we need it?**

Paging is a function of memory management where a computer will store and retrieve data from a device's secondary storage to the primary storage. Memory management is a crucial aspect of any computing device, and paging specifically is important to the implementation of virtual memory

Paging is used for faster access to data. When a program needs a page, it is available in the main memory as the OS copies a certain number of pages from your storage device to main memory. Paging allows the physical address space of a process to be noncontiguous.

Page Hit. When the CPU attempts to obtain a needed page from main memory and the page exists in main memory (RAM), it is referred to as a <mark>PAGE HIT</mark>

Overview. In an operating system, page replacement is referred to a scenario in which a page from the main memory should be replaced by a page from secondary memory. Page replacement occurs due to page faults



**Demand Paging, Segmentation**

Demand paging is a method of virtual memory management which is based on the principle that pages should only be brought into memory if the executing process demands them. This is often referred to as lazy evaluation as only those pages demanded by the process are swapped from secondary storage to main memory.
So demand paging works opposite to the principle of loading all pages immediately.

Segmentation is a memory management technique in which the memory is divided into the variable size parts. Each part is known as a segment which can be allocated to a process.

The details about each segment are stored in a table called a segment table. Segment table is stored in one (or many) of the segments.

Segment table contains mainly two information about segment:

Base: It is the base address of the segment
Limit: It is the length of the segment


**Real Time Operating System, types of RTOS**

A real-time operating system (RTOS) is a special-purpose operating system used in computers that has strict time constraints for any job to be performed and is intended to serve real time applications that possess data as it comes in , typically without buffer delays.

Example Flight control, real time simulation

Types of RTOS:

Hard RTOS
Firm RTOS
Soft RTOS


**Difference between main memory and secondary memory.**


* Primary memory is the computer memory that is directly accessible by CPU. It is comprised of DRAM and provides the actual working space to the processor. It holds the data and instructions that the processor is currently working on (RAM, ROM (computer chips), Cache,PROM, Register etc)

* The contents of the secondary memory first get transferred to the primary memory and then are accessed by the processor, this is because the processor does not directly interact with the secondary memory (hard Disk, Floppy Disk, Magnetic Tapes etc)

**Dynamic Binding**

Static binding happens when the code is compiled, while dynamic bind happens when the code is executed at run time.

* Static Binding
When a compiler acknowledges all the information required to call a function or all the values of the variables during compile time, it is called “static binding”. As all the required information is known before runtime, it increases the program efficiency and it also enhances the speed of execution of a program. Static Binding makes a program very efficient, but it declines the program flexibility, as ‘values of variable’ and ‘function calling’ are predefined in the program. Static binding is implemented in a program at the time of coding. Overloading a function or an operator is the example of compile time polymorphism i.e. static binding

* Dynamic Binding
 Calling a function or assigning a value to a variable, at run-time is called “Dynamic Binding”. Dynamic binding can be associated with run time ‘polymorphism’ and ‘inheritance’ in OOP. Dynamic binding makes the execution of a program flexible as it can decide what value should be assigned to the variable and which function should be called, at the time of program execution. But as this information is provided at run time it makes the execution slower as compared to static binding


 **FCFS Scheduling**

First Come First Serve (FCFS) is an operating system scheduling algorithm that automatically executes queued requests and processes in order of their arrival. It is the easiest and simplest CPU scheduling algorithm. In this type of algorithm, processes which requests the CPU first get the CPU allocation first

**SJF Scheduling**

Shortest Job First (SJF) is an algorithm in which the process having the smallest execution time is chosen for the next execution. This scheduling method can be preemptive or non-preemptive. It significantly reduces the average waiting time for other processes awaiting execution

<mark>non pre emptive</mark>  does not interrupt a process running CPU in middle of execution

<mark>pre emptive</mark> program can be interrupted

**SRTF Scheduling**

SRTF Scheduling is a preemptive version of SJF scheduling. In SRTF, the execution of the process can be stopped after a certain amount of time. At the arrival of every process, the short term scheduler schedules the process with the least remaining burst time among the list of available processes and the running process

* Completion Time (CT): This is the time when the process completes it’s execution.

* Arrival Time (AT): This is the time when the process has arrived in the ready state.

* Waiting Time (WT):
The time spent by a process waiting in the ready queue for getting the CPU.
The time difference b/w Turnaround Time and Burst Time is called Waiting Time.

* Burst Time (BT): This is the time required by the process for it’s execution

* Turn around Time (TAT): Burst time + Waiting Time

**LRTF Scheduling**

This is a preemptive version of Longest Job First (LJF) scheduling algorithm. In this scheduling algorithm, we find the process with the maximum remaining time and then process it. We check for the maximum remaining time after some interval of time(say 1 unit each) to check if another process having more Burst Time arrived up to that time

**Priority Scheduling**

Priority Scheduling is a method of scheduling processes that is based on priority. In this algorithm, the scheduler selects the tasks to work as per the priority.

The processes with higher priority should be carried out first, whereas jobs with equal priorities are carried out on a round-robin or FCFS basis. Priority depends upon memory requirements, time requirements, etc


**Round Robin Scheduling**

In Round-robin scheduling, each ready task runs turn by turn only in a cyclic queue for a limited time slice. This algorithm also offers starvation free execution of processes. Widely used preemptive scheduling method in traditional OS. All the jobs get a fair allocation of CPU. 
* Cons include : Finding a correct time quantum is a quite difficult task in this system, Round-robin scheduling doesn’t give special priority to more important tasks


**Producer Consumer Problem**

About Producer-Consumer problem: The Producer-Consumer problem is a classic problem that is used for multi-process synchronisation i.e. synchronisation between more than one processes.

The job of the Producer is to generate the data, put it into the buffer, and again start generating data. While the job of the Consumer is to consume the data from the buffer.

What’s the problem here?
The following are the problems that might occur in the Producer-Consumer:

The producer should produce data only when the buffer is not full. If the buffer is full, then the producer shouldn’t be allowed to put any data into the buffer.
The consumer should consume data only when the buffer is not empty. If the buffer is empty, then the consumer shouldn’t be allowed to take any data from the buffer.
The producer and consumer should not access the buffer at the same time.

We can solve this problem by using semaphores


**Banker’s Algorithm**

The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.
The banker’s algorithm is named because it checks whether a person should be sanctioned a loan amount or not to help the bank system safely simulate allocation resources.



**Explain Cache**

Cache is a type of memory that is used to increase the speed of data access. Normally, the data required for any process resides in the main memory. However, it is transferred to the cache memory temporarily if it is used frequently enough. The process of storing and accessing data from a cache is known as caching.

Cache Memory is a special very high-speed memory. It is used to speed up and synchronizing with high-speed CPU. Cache memory is costlier than main memory or disk memory but economical than CPU registers. Cache memory is an extremely fast memory type that acts as a buffer between RAM and the CPU. It holds frequently requested data and instructions so that they are immediately available to the CPU when needed.

**Fast Memory**

<mark>Level 1 or Register , Level 2 or Cache , Level 3 or Main Memory, Level 4 or Secondary Memory</mark>

**Difference between Direct-mapping, Associative Mapping & Set-Associative Mapping**

* Direct Mapping
Each block from main memory has only one possible place in the cache organization in this technique. 

For example : every block i of the main memory can be mapped to block j of the cache using the formula : 

>j = i modulo m
Where : i = main memory block number
       j = cache block number
       m = number of blocks in the cache

* Associative Mapping
Here the mapping of the main memory block can be done with any of the cache block. The memory address has only 2 fields here : word & tag. This technique is called as fully associative cache mapping.

* Set-Associative Mapping
It is the combination of advantages of both direct & associative mapping. 

    * Cache lines are grouped into sets where each set contains k number of lines
    * A particular block of main memory can map to only one particular set of the cache.
    * However, within that set, the memory block can map to any freely available cache line.
    

**Diff between multitasking and multiprocessing**

* Multi-tasking : 
Multi-tasking is the logical extension of multiprogramming. In this system, the CPU executes multiple jobs by switching among them typically using a small time quantum, and these switches occur so frequently that the users can interact with each program while it is running. Multitasking is further classified into two categories: Single User & Multiuse

![multi tasking](https://media.geeksforgeeks.org/wp-content/uploads/20201024154200/multitasking.png)

*  Multiprocessing : 
Multiprocessing is a system that has two or more than two processors. In this, CPUs are added for increasing computing speed of the system. Because of Multiprocessing, there are many processes that are executed simultaneously. Multiprocessing is further classified into two categories: Symmetric Multiprocessing and Asymmetric Multiprocessing

    * multiprocessing, in computing, a mode of operation in which two or more processors in a computer simultaneously process two or more different portions of the same program (set of instructions).

![multi processing](https://media.geeksforgeeks.org/wp-content/uploads/20201024154456/multiprocessing1.png)

## Linux Commands

  **What do you understand by Linux Kernal? Is it legal to edit it?**
 
  Answer: ‘Kernal’ basically refers to that core component of the computer operating system that provides basic services for the other parts as well as interacts with user commands. When it comes to ‘Linux Kernal’, it is referred to as low-level system software providing an interface for user-level interactions
 
  Linux Kernal is considered as free and open-source software which is capable of managing hardware resources for the users. As it is released under General Public Licence (GPL), it becomes legal for anyone to edit it.

  **Differentiate between LINUX and UNIX?**
 
  Answer:
  | Linux | Unix |
  |-------|------|
  |LINUX is an open source software development and free operating system used for computer hardware & software, game development, PCs, etc | UNIX is an operating system which is basically used in Intel, HP, internet servers, etc|
  | LINUX has priced as well as freely distributed and downloaded versions | Different versions/flavours of UNIX have different price structures |
  | Users of this operating system could be anyone including home users, developers, etc | This operating system was basically developed for mainframes, servers and workstations except for OSX which is designed such that it can be used by anyone |
  | File support system includes Ext2, Ext3, Ext4, Jfs, Xfs, Btrfs, FAT, etc | File support system includes jfs, gpfs, hfs, etc |
  BASH (Bourne Again Shell) is the Linux default shell i.e. text mode interface which supports multiple command interpreters | Bourne shell serves as the text mode interface which is now compatible with many others including BASH |
  LINUX provides two GUIs, KDE and Gnome | Common desktop environment was created which serves as a GUI for UNIX|
  Examples: Red Hat, Fedora, Ubuntu, Debian, etc | Examples: Solaris, All Linux
  t provides higher security and has about 60-100 viruses listed till date |It is also highly secured and has about 85-120 viruses listed till date |



  **Enlist the basic components of LINUX?**
  Answer: Linux operating system basically consists of 3 components. They are:
  
  **Kernel:** This is considered as the core part and is responsible for all major activities of the Linux operating system. Linux Kernel is considered as free and open-source software that is capable of managing hardware resources for the users. It consists of various modules and interacts directly with the underlying hardware.
  **System Library:** Most of the functionalities of the operating system are implemented by System Libraries. These act as a special function using which application programs accesses Kernel’s features.
  **System Utility:** These programs are responsible for performing specialized, individual-level tasks.


## Questions to ask in the intervew

#### For Hiring Manager

* What are the key challenges of the role?
* why this role is available? (think about this later whether to ask this in my interview or not)
* Ask what kind of traits would make a candidate successful ? (ask this early round or may be with the hiring manager)
* What is his favourite leadership principle is ?


#### For Team Members

* What drew you to this team?
* What surprised you in this team?
* What is your manager's favourite leadership principle ?


#### For different team member or Bar Raisers

* What do you find most challenging about working at Amazon ?
* Is there anything that continuously surprise you (in a positive way) about working at Amazon?


## Important notes in the interview

* Don't be shy to ask the negative questions in the interview, just frame them politely
