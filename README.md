# cpe315-lab5
Cache and Virtual Memory Optimization

######You may work in pairs on this assignment.
###Purpose
To optimize data cache accesses for two different applications, and compare 
the impact on performance.

###Method
Modify data structures to exploit cache locality. Measure your optimizations 
using performance measurement tools (perf) for multiple architectures 
(intel, arm).

###What to Do
There are two programs, `matmul` and `structs` you need to optimize. You can 
do the optimizations in either order.

####matmul
For the `matmul` program, you will modify two functions in `matmul.cpp`; 
`matmul` and `Allocate2ndMatrix`. The goal is to access the second matrix in 
a way that exploits the spatial locality of the cache. You'll do this both in 
the allocation/initialization, and in the actual computation.

The program computes the matrix multiplication of two 1024x1024 matrices, and 
writes the result to `stdout`. Run the program like `./mm > myout`. 
I've provided a correct output file you can compare your answer to. Some 
small differences in floating point values (±0.01) might be observed, and ar
e not a problem. Timing results are printed to `stderr`.

####structs
For the `structs` program, you'll modify the `structs.cpp` file. The goal is 
to convert the array-of-structures (AoS) to a structure-of-arrays (SoA). Run 
the program like `./computeavg`. This program prints timing results to `stdout`.

###Measurements
You can measure the number of cache misses using:
    perf stat -e cache-misses ./mm > myout

Measure the number of page-faults by running perf stat with no other options.

###Record your run times, cache misses, and page-faults
You should create a table of the execution times and cache misses, one per 
benchmark, before and after optimization, and present the table with your 
data in your report.

An example table:

Experiment | ARM no opt | ARM opt | Intel no opt | Intel opt
-----------|------------|---------|--------------|----------
Runtime (matmul) | | | |
Cache Misses (matmul) | | | |
Page Faults (matmul) | | | |
Runtime (structs) | | | |
Cache Misses (structs) | | | |
Page Faults (structs) | | | |

Explain your results in your report (e.g. correlate cache misses and 
    page-faults to measured performance).

###What to Hand In
An electronic copy of your report in PDF format. Please do not submit 
Microsoft Office documents. One report per group. Also submit a documented 
version of your code for both programs. 

###Submission Instructions
Submit the following files via GitHub:
  * Report in PDF format (no Docs!):
  * any scripts you wrote/used.

