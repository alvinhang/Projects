1. Assume that you are trying to download a large 2-GB file from the Internet. The file is available from a set of mirror servers, each of which can deliver a subset of the file’s bytes; assume that a given request specifies the starting and ending bytes of the file. Explain how you might use threads to improve the download time.

    #### Threads would help with partitioning the large 2-GB file. The file could be split into 4 threads: thread0, thread1, thread2, thread3. Each of these threads would then download the divided file split into about 500MB. Downloading smaller files will reduce the bandwidth load of one's internet which in turn will speed up the download of the 2-GB file.

   
2. What is the biggest advantage of implementing threads in user space? What is the biggest disadvantage?

    #### The biggest advantage of implementing threads in user space would be that the kernel would think it is managing a single-threaded process. The threads at user-level can then be implemented in operating systems that does not support threads.
    #### The biggest disadvantage of implementing threads in user space would be how system call blocks are performed. Threads should not make system calls as it would halt all threads. The main purpose to have threads is to have each thread use blocking calls instead of having it prevent other threads from utilizing blocking calls.

   
3. Does Peterson’s solution to the mutual-exclusion problem shown in Fig. 2-24 of - MOS4e work when process scheduling is preemptive? How about when it is nonpreemptive?

    #### I think Peterson's solution to the mutual-exclusion problem does not work reliably for process preemptive scheduling. This is because the system can decide to switch processes at any given time, this causes disruption to existing or current processes in the works. Another reason for it to not be reliable would be that if a process is in the critical region, Peterson's solution does not seem to address that portion. As for nonpreemptive, Peterson's solution looks like it works correctly for the process scheduling. Nonpreemptive, it meaning that once a process starts/executed, it will keep on going until it voluntarily decides to give up the CPU process or is completed. Another reason as to why nonpreemptive works is that the critical region is protected from being preemptive.

   
4. The producer-consumer problem can be extended to a system with multiple producers and consumers that write (or read) to (from) one shared buffer. Assume that each producer and consumer runs in its own thread. Will the solution presented in Fig. 2-28 of MOS4e, using semaphores, work for this system?

    #### Based off Figure 2-28 of MOS4e, the usage of semaphores should work with the system. Semaphores help the system by having a value of 0 which tells the system the wakeups were not saved, or if the value is greater than 0 then there are pending wakeups. Having semaphores work with the up and down system calls in a simple usage of mutex, empty or full is faster than the producer or consumer. This solution shows that it can handle multiple producers and consumers by simply coordinating their access to a shared buffer that uses semaphores.

   
5. How could an operating system that can disable interrupts implement semaphores?

    #### An operating system that can disable interrupts could implement semaphores by having up and down system calls. During the disabling of interrupts, it can then test the semaphores through updates, and putting to sleep the process as well.


6. A fast-food restaurant has four kinds of employees:
    (a) order takers, who take customers’ orders; 
    (b) cooks, who prepare the food;
    (c) packaging specialists, who stuff the food into bags; and
    (d) cashiers, who give the bags to customers and take their money.
    
    Each employee can be regarded as a communicating sequential process. What form of interprocess communication do they use? Relate this model to processes in UNIX.

    #### For order takers, the interprocess communication they use is sending order details to the cooks. Cooks would then receive the order details from the order takers and begin to cook the foods as per the order details. Packaging specialists then receive instructions from the cook on how they can package the foods properly. These packaged foods are then sent to the cashier as instructions by the packaging specialists, informing the cashier what each package of food represents for them to receive the correct amount of money from the customers. Relating this to UNIX, the processes in UNIX also communicate in a similar fashion such that it sends a message, signals are then raised to perform specific actions or events.


7. Five jobs are waiting to be run. Their expected run times are 9, 6, 3, 5, and x. In what order should they be run to minimize average response time? (Your answer will depend on x).


    #### In order to minimize average response times, I would order the response times from least to greatest, 3, 5, 6, 9. Next I would determine the value of x, checking if x is less than 3 then we will organize it as [x, 3, 5, 6, 9]. If x is somewhere in the middle, it would then be [3, 5, x, 6, 9]. Lastly, if x is highest value, then it would be sorted into [3, 5, 6, 9, x]. Because x is unknown, these 3 solutions for possible values of x should help optimize and minimize average response time. 



8. The aging algorithm with a = 1/2 is being used to predict run times. The previous four runs, from oldest to most recent, are 40, 20, 40, and 15 msec. What is the prediction of the next time? Explain.

    #### Formula used S<sub>n</sub> = ***a***T<sub>n</sub> + (1-***a***) * S<sub>n</sub>
    #### Since we have 4 runs, we can label them denoted as T<sub>n</sub>
    #### T<sub>1</sub> = 40 msec
    #### T<sub>2</sub> = 20 msec
    #### T<sub>3</sub> = 40 msec
    #### T<sub>4</sub> = 15 msec

    #### ***a*** = 1/2 or 0.5
    #### We can use the equation to solve for the predicted runtimes.
    #### T<sub>1</sub> = S<sub>0</sub>
    #### S<sub>1</sub> = 0.5 * T1 + 0.5 * T1 = 40
    #### S<sub>2</sub> = 0.5 * T2 + 0.5 * S1 = 30
    #### S<sub>3</sub> = 0.5 * T3 + 0.5 * S2 = 35
    #### S<sub>4</sub> = 0.5 * T4 + 0.5 * S3 = 25
    #### So the next runtime prediction should be 25msec. This is because it is dependant on the average of the previous runtimes.


9. In the dining philosophers problem, let the following protocol be used: An even-numbered philosopher always picks up his left fork before picking up his right fork; an odd-numbered philosopher always picks up his right fork before picking up his left fork. Will this protocol guarantee deadlock-free operation? Why or why not?

    #### I don't think this would guarantee a deadlock-free operation. My reasoning is because what if the left fork for the even-numbered philosopher is not available due to the fork being held by the neighboring philosopher. This would keep on going until every one of the philosophers are waiting for their forks because another philosopher is holding their fork. This would then cause the deadlock.


10. The readers and writers problem can be formulated in several ways with regard to which category of processes can be started when. Carefully describe three different variations of the problem, each one favoring (or not favoring) some category of processes. For each variation, specify what happens when a reader or a writer becomes ready to access the database, and what happens when a process is finished.

    #### If we categorize the processes, we can separate them into 3 types, priority to readers, priority to writers, and no priority at all.

    #### Priority to readers: For readers having priority, readers can concurrently access the resources while giving writers no access to the resource at all. If the readers are ready and there are no writers accessing the resource, then reader can then begin their reading. If a writer wants to access the resource, then there has to be no readers actively using the resource.

    #### Priority to writers: For writers having priority, writers are the ones that have exclusive access to the resource. This means that if a writer is currently writing, no other reader or writer can access the resource. Readers can only access the resource if there are no writers currently writing. Readers can access the resource concurrently. If a writer is ready to access the resource, then it can write immediately as long as there are no active readers or writers. Writers must wait for readers to finish reading to start the writing process.

    #### No priority: Having no priority would create equality for both readers and writers. Readers can read and writers can write as long as long as there are no prior readers or writers actively utilizing the resource.