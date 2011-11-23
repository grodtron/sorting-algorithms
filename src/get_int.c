#include <stdio.h>
#include <stdlib.h>
#include "../include/bool.h"

void getInt(int* returnValue, bool* success){

   const int INPUT_LENGTH = 10;

   // a c string that will be filled with the inputted numbers;
   // length of 11 characters is based on the assumtion that 
   // 2147483648 is the maximum value we can store. It requires 
   // 11 characters INCLUDING the \0 to terminate the cstring
   // (The plus one is for the '\0')
   char input[INPUT_LENGTH + 1];

   // Pretty straightforward - the curernt index in the string
   int i = 0;

   // Also straightforward - the var that holds the character we read in
   char c;

   // this keeps track of whether we are currently reading in a number
   // the first time we hit a digit character, this is set to true
   // and whenever we hit a non-digit character, if this is true,
   // then we break
   bool haveStarted = false;

   while((c = getchar()) && (i < INPUT_LENGTH)){

      // if the character we read in is a digit
      if(c >= '0' && c <= '9'){
         input[i++] = c;
         if (!haveStarted) haveStarted = true;
      }else if(haveStarted){
         break;
      }
   }
   // if i (i > 0) then we were able to get an integer, so
   // use atoi to parse it and then set it in the return value
   // and set the status to true (success!)
   // otherwise set the status to false (failure)
   if(i){
      input[i] = '\0';
      *success = true;
      *returnValue = atoi(input);
   }else{
      *success = false;
   }
}

/* USAGE:

int main(int argc, const char *argv[])
{
   int i;
   bool status;


   while(1){

      getInt(i, status);

      if(status){
         printf("got value %d\n", i);
      }else{
         break;
      }
   }

   return 0;
}

*/
