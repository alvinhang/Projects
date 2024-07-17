/* Answer to questions
   1. pthread is used to create threads, it is also used to kill the threads that it creates. In the main function, pthread creates child_thread, after 
   the thread is created, pthread was also used to cancel/kill the child thread after the user pressed the Enter key.

   2. The sleeping thread can print its periodic messages while the main thread is waiting for keyboard input because they were ran simultaneously. This means
   that the main function is waiting for the Enter key press while the child thread continues its execution for sleeping as well as printing the message. 
*/

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

//added stdlib and stdbool for defining true. This allows to create the infinite loop for child sleeping
#include <stdlib.h>
#include <stdbool.h>

//Wrapped the sleep and print in a while loop as per the assignment stating that the child should be looping infinitely and sleeping every 3 seconds
static void *child(void *ignored){
   while(true) {
      sleep(3);
      printf("Child is done sleeping 3 seconds.\n");
   }
   
   return NULL;
}

int main(int argc, char *argv[]){
   // This is the indentifier for the child thread
   pthread_t child_thread;

   // Declared a variable called code
   int code;
   // Child thread is created under the declared variable "code"
   code = pthread_create(&child_thread, NULL, child, NULL);
   // Print statement that says the Child thread was created
   printf("Child thread has been created.\n\n");
   // Error statement for when pthread fails to create a thread.
   if(code){
      fprintf(stderr, "pthread_create failed with code %d\n", code);
   }

   // Tells the user to press enter to kill thread.
   printf("Press Enter to kill the child thread.\n\n");
   // getchar waits and captures Enter key press
   getchar();

   // pthread_cancel is used to kill a thread. In this case it is used to kill child_thread
   code = pthread_cancel(child_thread);
   // error statement will print if it failed to kill thread.
   if (code) {
      fprintf(stderr, "pthread_cancel failed with code %d\n", code);
   }
   
   // print that main is killing child thread in 5 seconds
   printf("The child thread will be killed in 5 seconds.\n\n");
   sleep(5);
   printf("The main thread has successfully killed the child thread after 5 seconds.\n");
   return 0;
}
