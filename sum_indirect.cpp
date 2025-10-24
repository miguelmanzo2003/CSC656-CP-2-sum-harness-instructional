#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include <string.h>

#include "sums.h"
#define MAXSIZE 1 << 28

void 
setup(int64_t N, int64_t A[])
{
   printf(" inside sum_indirect problem_setup, N=%lld \n", N);

   std::mt19937_64 gen(std::random_device{}());
   std::uniform_int_distribution<std::int64_t> dist(0, MAXSIZE);

   int64_t i = 0;
   for(i = 0; i < N; i++){

      
      A[i] = dist(gen);
   }
}

int64_t
sum(int64_t N, int64_t A[])
{
   printf(" inside sum_indirect perform_sum, N=%lld \n", N);

   int64_t i = 0;
   int64_t sum = 0;

   for(i = 0; i < N; i++){

      sum += A[i];

   }

   return sum;
}

