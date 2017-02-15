
/* Array-of-Structures vs. Structure-of-Arrays */

// includes
#include <stdlib.h>
#include <stdio.h>

// Adjust the number of elements based on architecture
#ifdef __arm__
  #define NUMVALUES 16777216
#elif defined __x86_64__
  #define NUMVALUES 268435456
#endif

// You'll need to modifiy this struct
typedef struct nums {
  double mydouble;
  float myfloat;
  long long int mylonglong;
} myNums;

void init_nums(myNums *);
void compute_averages(myNums *);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

  // Data structure for the program
  myNums *AoS;  // AoS will be an array of structs
                // You'll want to convert to a struct of arrays

  // Allocate and initialize the array of structs
  // This will also need to change
  AoS  = (myNums *) malloc(NUMVALUES*sizeof(myNums));

  init_nums(AoS);  // time the initialization
  
  compute_averages(AoS);  // time the computation

  // Free 
  free(AoS);
  return 0;
}

////////////////////////////////////////////////////////////////////////
// You'll need to modify the following two functions to adjust how
// the data structure is accessed. 

void init_nums (myNums *AoS) {
  unsigned int fseed = 2016;
  unsigned int dseed = 2017;

  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    AoS[i].myfloat = (rand_r(&fseed) / (float)RAND_MAX);
    AoS[i].mydouble = (rand_r(&dseed) / (double)RAND_MAX);
    AoS[i].mylonglong = (rand_r(&dseed) / (long long int)RAND_MAX);
  }
}

void compute_averages (myNums *AoS) {
  float sumf = 0.0;
  double sumd = 0.0;
  long long int sumll = 0;

  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    sumf += AoS[i].myfloat; 
  }
  fprintf(stdout, "Average of %d floats = %.5f.\n", 
      NUMVALUES, sumf/(float)NUMVALUES);

  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    sumd += AoS[i].mydouble; 
  }
  fprintf(stdout, "Average of %d doubles= %.5lf.\n", 
      NUMVALUES, sumf/(double)NUMVALUES);
  for (unsigned int i = 0; i<NUMVALUES; ++i) {
    sumll += AoS[i].mylonglong; 
  }
  fprintf(stdout, "Average of %d long long ints= %lld.\n", 
      NUMVALUES, sumll/(long long int)NUMVALUES);
}
