/*
 print-primes.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int counter = 0;

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

void print_number(int n){
  if (counter == COLUMNS){
    printf("\n");
    counter = 1;
  }
  else{
    counter++;
  }
  printf("%10d ", n);
}

void print_primes(int n){
    for(int i = 2; i <= n; i++){
      if (is_prime(i))
        print_number(i);
    }
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
    if(argc == 2)
    {
        print_primes(atoi(argv[1]));
    }
  else
    printf("Please state an integer number.\n");
  return 0;
}

 
