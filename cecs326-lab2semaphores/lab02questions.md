Q1. In what order should you perform the actions to create shared memory? (HINT: A minimum of three functions must be used the first time you create shared memory.)

#### To create shared memory, we would use shm_open(), ftruncate(), and mmap().
```
shm_open() is used to create or open the shared memory object
ftruncate() is used to set the size of the shared memory object
mmap() is used to map the shared memory object to the address space
```

Q2. What is the return type of mmap, and what can you do with it? (If you are unfamiliar with C/C++, you might need to do some personal research in order to understand this data type.)

#### The return type for mmap is a pointer of type void. The pointer is used to access the mapped memory.

Q3. What does fork() return, and how can that information be used?

#### fork() is used to return a process ID such as pid_t this is also a process ID of the child from the parent's process. The information from fork would be that it helps with the execution of the parent and child processes as well as help identifying and killing the processes when necessary

Q4. If exec works as intended, what happens to the process that calls it?

#### If exec works as intended, then it should replace the current process image with a new process image. This means the original program is replaced by the new execution, the process ID should not change.

Q5. Do all three functions for shared memory need to be called in every single process after the first? If yes, why? If no, which ones are needed, and why would you not need to call all of them?

#### No, the three functions do not need to be called in every process. mmap needs ot be called in each process for files that want to access the shared memory. While shared memory objects only need to be created once with shm_open() and ftruncate(). This is the case for game.c using ftruncate only and not in the other 3 class files.

Q6. What does a struct look like in memory, and if I store a struct in shared memory, how do I access its various fields?

#### To access the various fields , you need to map the shared memory using mmap()
```Such as: int fd = shm_open("/mySharedMemory", O_CREAT | O_RDWR, 0666);```
#### A struct should look something like:
```c
struct Example {
    char a;
    int b;
    char c;
};
```

Q7. How do I determine the size of a struct in bytes?

#### We can determine the size of a struct using sizeof which will determine the size in bytes. This would be written as sizeof(struct MyStruct);