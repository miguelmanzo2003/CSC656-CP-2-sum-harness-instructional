//
// (C) 2022-2023, E. Wes Bethel
// benchmark-* harness for running different versions of the sum study
//    over different problem sizes
//
// usage: no command line arguments
// set problem sizes, block sizes in the code below

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#define __STDC_FORMAT_MACROS   // safest: enables PRI* macros in C++
#include <cinttypes>           // gives PRIu64 and friends (also pulls in <cstdint>)
#include <cstdio>      

#include "sums.h"

/* The benchmarking program */
int main(int argc, char** argv) 
{
   std::cout << std::fixed << std::setprecision(2);

#define MAX_PROBLEM_SIZE 1 << 28  //  256M
   std::vector<int64_t> problem_sizes{ MAX_PROBLEM_SIZE >> 5, MAX_PROBLEM_SIZE >> 4, MAX_PROBLEM_SIZE >> 3, MAX_PROBLEM_SIZE >> 2, MAX_PROBLEM_SIZE >> 1, MAX_PROBLEM_SIZE};
   
   int64_t *A = (int64_t *)malloc(sizeof(int64_t) * MAX_PROBLEM_SIZE);

   int n_problems = problem_sizes.size();

   /* For each test size */
   for (int64_t n : problem_sizes) 
   {
      int64_t t;
      printf("Working on problem size N=%lld \n", n);

      // invoke user code to set up the problem
      setup(n, &A[0]);

      // insert your timer code here
      auto start = std::chrono::system_clock::now();
      // invoke method to perform the sum
      t = sum(n, &A[0]);
      printf("Sum from within benchmark = %" PRIu64 "\n", sum);

      // insert your end timer code here, and print out elapsed time for this problem size
      auto end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed_time = end - start;
      float elapsed_time_too = elapsed_time.count();

      std::cout << "Elapsed time: " << elapsed_time_too << "seconds" << std::endl;
      std::cout << "Valeue of sum = " << t << std::endl;
      printf(" Sum result = %lf \n\n",t);

   } // end loop over problem sizes
}

// EOF
