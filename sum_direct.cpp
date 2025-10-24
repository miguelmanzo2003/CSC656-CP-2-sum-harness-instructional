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

void 
setup(int64_t N, int64_t A[])
{
   printf(" inside direct_sum problem_setup, N=%lld \n", N);
}

int64_t
sum(int64_t N, int64_t A[])
{
   printf(" inside direct_sum perform_sum, N=%lld \n", N);

   int64_t i = 0;
   int64_t sum = 0;

   for( i = 0; i < N; i++){

      sum += i;

   }
   printf("Sum = %" PRIu64 "\n", sum);
   return sum;
}

