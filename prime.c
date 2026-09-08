/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>

int is_prime(int n) {
  // As per Ibn al-Haythams or Wilsons theorem 
  if (n < 2) return 0;
    
  long long ans = 1;
  // Calculate (n-1)! mod n
  for (int i = 1; i < n; i++) {
    ans = (ans * i) % n; 
  }
    
  // Check if the result is equivalent to -1 (which is n - 1)
  return (ans == n - 1);
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
