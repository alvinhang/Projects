1. Consider a swapping system in which memory consists of the following hole sizes in memory order: 10MB, 4MB, 20MB, 18MB, 7MB, 9MB, 12MB, and 15MB. Which hole is taken for successive segment requests of:
    - 12MB
    - 10MB
    - 9MB 
    for first fit? 
    
    Repeat the question for best fit, worst fit, and next fit.

    #### Segment Hole Sizes:
    #### 12MB: For the first fit, it would take 20MB, Best fit it should take 12MB, worst fit it should I think takes 20MB, and lastly, next fit should take 20MB.
    #### 10MB: For the first fit, it would take 10MB, Best fit it should take 10MB, worst fit it should take 18MB, and lastly, next fit should take 18MB.
    #### 9MB: For the first fit, it would take 10MB, Best fit it should take 9MB, worst fit should 15MB, and lastly, the next fit should take 9MB.

2. What is the difference between a physical address and a virtual address?
    #### The difference between physical address and virtual address would be that physical address represents the physical memory of hardware. The physical address represents the actual numerical values of the memory chips. While virtual address is considered logical address which represents the process address space.

   
3. Using the page table of Fig. 3-9 of MOS4e, give the physical address corresponding to each of the following virtual addresses:
   - 20
   - 4100
   - 8300

    #### For virtual address 20, it is 8K + 20 = 8212
    #### For virtual address 4100, it is 4K + (4100 - 4K) = 4100
    #### For virtual address 8300, it is 24K + (8300 - 8K) = 24684

4. Copy on write is an interesting idea used on server systems. Does it make any sense on a smartphone? Why?

    #### Modern smartphones should all have multiprogramming which is capable of supporting multiple processes. Given the copy on write idea for server systems, it should be the same for if a smartphone was to use the copy on write idea as well.

5. If FIFO page replacement is used with four page frames and eight pages, how many page faults will occur with the reference string **0172327103** if the four frames are initially empty? Repeat this problem for LRU.

    #### Page frames for FIFO:
    #### 0 1 7 2 3 2 7 1 0 3
    #### ***0*** 0 0 0 ***3*** 3 3 3 3 3
    #### X ***1*** 1 1 1 1 1 1 ***0*** 0
    #### X X ***7*** 7 7 7 7 7 7 7
    #### X X X ***2*** 2 2 2 2 2 2
    #### There would be six page faults for FIFO

    #### Page frames for LRU:
    #### 0 1 7 2 3 2 7 1 0 3
    #### ***0*** 0 0 0 ***3*** 3 3 3 ***0*** 0
    #### X ***1*** 1 1 1 1 1 1 1 1
    #### X X ***7*** 7 7 7 7 7 7 7
    #### X X X ***2*** 2 2 2 2 2 ***3***
    #### There would be seven page faults for LRU

6. In the WSClock algorithm of Fig. 3-20(c) on pg. 220 of **MOS4e**, the hand points to a page with R=0. If tau(400), will this page be removed? What about if tau(1000)?

    #### Based off Figure 3-20, it seems for c and d it shoes that at R=1 then it is 2204 and when R=0 it is 1213. Given this, we subtract 2204 - 1213 = 991. This would be the age of the page. If tau(400), then it is outside of the set which puts it out. When tau(1000), the page comes out of the set. This means that the page will not be removed.

7. Virtual memory provides a mechanism for isolating one process from another. What memory management difficulties would be involved in allowing two operating systems to run concurrently? How might these difficulties be addressed?

    #### Given how virtual machines work, I think that an example of this is when a user is running Windows, and runs a virtual machine to load Linux, the memory management difficulties would be that it has to match the native performance of the operating system. To address the difficulties, we would want to introduce a given number of TLB entries to each of the kernels, this allows the kernel to operate with the correct virtual memory.

8.  When segmentation and paging are both being used, as in *MULTICS*, first the segment descriptor must be looked up, then the page descriptor. Does the TLB also work this way, with two levels of lookup?

    #### No, in systems that use both segmentation and paging, TLB has to use caching to translate from virtual page addresses to physical page addresses. This means that TLB does not directly translate cache from virtual segmented address to physical segmented address. This also means that it does not use two levels of lookup.

9. A student in a compiler design course proposes to the professor a project of writing a compiler that will produce a list of page references that can be used to implement the optimal page replacement algorithm. Is this possible? Why or why not? Is there anything that could be done to improve paging efficiency at run time?

    #### I don't think it's possible to write a compiler that produces a list of page reference to be used in the implementation of optimal page replacement algorithm. Because compilers translate source code to machine code, it doesn't have future memory access. Given the optimal page replacement algorithm, it requires prediction which uses future memory access. This is something that compilers are probably not able to do, so it is not possible for the student to do this. The possible way to improve paging efficiency at run time is utilizing the page replacement algorithm, such as LRU.