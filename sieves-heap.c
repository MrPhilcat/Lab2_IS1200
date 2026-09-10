/*
 print-primes.c
 By Philipp Stah and Aron Corestav.
 Last modified: 2026-09-08
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>


#define COLUMNS 6
int counter = 0;


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

void print_sieves(int n){
    unsigned char* arr = malloc((n-1)*sizeof(unsigned char));
    for(unsigned char i = 0; i <= (n - 2); i++){
        arr[i] = i + 2;
    }
    unsigned char p = 2;
    unsigned char lastPrime;
    do{
        // We interpret "marked" = 0
        for(unsigned char i = 2; i*p <= n; i++){
            arr[i*p-2] = 0;
        }
    
        lastPrime = p;
        for(unsigned char i = p-2; p == lastPrime && i <= (n-2); i++){
            if(arr[i] > p){
                p = arr[i];
                //printf("%d\n", p);
            }
        }
    } while (lastPrime != p);

    for(unsigned char i = 0; i <= (n - 2); i++){
        if(arr[i] != 0)
            print_number(arr[i]);
    }
    free(arr);
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
    if(argc == 2)
    {
        print_sieves(atoi(argv[1]));
    }
  else
    printf("Please state an integer number (n > 1).\n");
  return 0;
}

 
