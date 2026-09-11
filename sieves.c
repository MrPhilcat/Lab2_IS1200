/*
 print-primes.c
 By Philipp Stah and Aron Corestav.
 Last modified: 2026-09-08
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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
    unsigned char arr[n-1];
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
}

void print_sieves_cool(int n){
    bool myArray[n+1];
    myArray[0] = true;
    myArray[1] = true;
    for(int i = 2; i <= n; i++){
        myArray[i] = false;
    }

    while (1){
        int lastPrime = 0;
        int j = 2;
        while (lastPrime == 0){
            if(myArray[j] == false)
                lastPrime = j;
            if(j > n){
                return;
            }
            j++;
        }
        print_number(lastPrime);
    
        for(int i = lastPrime; i <= n; i += lastPrime){
            myArray[i] = true;
        }
    }
    
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
    if(argc == 2)
    {
        print_sieves_cool(atoi(argv[1]));
    }
  else
    printf("Please state an integer number (n > 1).\n");
  return 0;
}

 
