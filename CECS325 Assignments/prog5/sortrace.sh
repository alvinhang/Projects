# Alvin Hang
# Class (CECS 325-01)
# Project Name (Prog 5 - Sorting Contest using Threads)
# Due Date (11/01/2023)
#
# I certify that this program is my own original work. I did not copy any part of 
# this program from any other source. I further certify that I typed each and
# every line of code in this program.


echo "=======Start======="
date
echo My machine has this many processors
nproc				
echo Generating 1000000 random numbers
sleep 1
./generate 1000000 100000 999999  
sleep 1
echo Starting system sort
sleep 1
{ time sort numbers.txt > systemsort.out; } 2>> sortrace.log
sleep 1
echo Starting my sort
sleep 1
{ time ./mysort numbers.txt > mysort.out; } 2>> sortrace.log    
sleep 1
ls -l systemsort.out
ls -l mysort.out
echo Comparing systemsort.out to mysort.out
diff systemsort.out mysort.out 2>> sortrace.log 
echo All done
echo "=======End======="
date
