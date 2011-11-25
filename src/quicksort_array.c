#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bool.h"
#include "../include/quicksort.h"
#include "../include/get_int.h"
#include "../include/parse_args.h"

int main(int argc, const char *argv[])
{

   struct parameters params;

   parse_args(argc, argv, &params);

   if(params.length == -1){
      printf("the number of elements to be sorted MUST be specified as a command line argument!\n");
      return 1;
   }

   int *input = (int*) malloc( sizeof(int) * params.length );
   bool status = true;

   // get the input list of integers
   for (int i = 0; i < params.length && status; i++) {

      getInt(input + i, &status);

   }

   // SETUP TIMING
   struct timespec start_time;
   struct timespec end_time;

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
   // END SETUP TIMING

   // SORT!!!!!!!!!!!!!!!!!!!!!!!!!
   quicksort(input, params.length);

   // FINISH TIMING!
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

   double elapsed_time = difftime(end_time.tv_sec, start_time.tv_sec) + (1e-9 * (double)(end_time.tv_nsec - start_time.tv_nsec)) ;
   // END FINISH TIMING!


   if(params.verbose){
      for (int i = 0; i < params.length; i++) {
         printf("%d ", input[i]);
      }
      putchar('\n');
   }else{
      printf("%.9f\n", elapsed_time * 1e3);
   }

   free(input);

   return 0;
}
