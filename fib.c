#include <stdio.h>
#include <stdlib.h>

// Recursive Fibonacci function
long long int recursive(long long int n) {
   if (n <= 1) return n;
   return recursive(n - 1) + recursive(n - 2);
}

// Iterative Fibonacci function
long long int iterative(int n) {
   if (n <= 1) return n;
   long long int prev = 0, curr = 1, next;
   for (long long int i = 2; i <= n; i++) {
      next = prev + curr;
      prev = curr;
      curr = next;
   }
      return curr;
}

int main(int argc, char *argv[]) {

   // Variable Assignments
   long long int firstInt = atoi(argv[1]);
   char method = argv[2][0];
   FILE *file = fopen(argv[3], "r");
   long long int secondInt;
   fscanf(file, "%lld", &secondInt);
   fclose(file);

   // Calculations
   long long int N = firstInt + secondInt - 1;

   long long int fibNum;

   if (method == 'r') {
      fibNum = recursive(N);
   } else if (method == 'i') {
      fibNum = iterative(N);
   }

   // Output
   printf("%lld\n", fibNum);
   return fibNum;
}
