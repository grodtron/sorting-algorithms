#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bool.h"
#include "../include/insertion_sort.h"
#include "../include/get_int.h"

int main(int argc, const char *argv[])
{

   bool verbose = false;

   if(argc == 1){
      printf("must supply the number of integers to be sorted as first arg\n");
      return 1;
   }
   if(argc > 2){
      if(argv[2][0] == 'v'){
         verbose = true;
      }
   }

   int length = atoi(argv[1]);

   int *input = (int*) malloc( sizeof(int) * length );
   bool status = true;

   // get the input list of integers
   for (int i = 0; i < length && status; i++) {

      getInt(input + i, &status);

   }

   // SETUP TIMING
   struct timespec start_time;
   struct timespec end_time;

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
   // END SETUP TIMING

   // SORT!!!!!!!!!!!!!!!!!!!!!!!!!
   insertion_sort(input, length);

   // FINISH TIMING!
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

   double elapsed_time = difftime(end_time.tv_sec, start_time.tv_sec) + (1e-9 * (double)(end_time.tv_nsec - start_time.tv_nsec)) ;
   // END FINISH TIMING!

   printf("%.9f\n", elapsed_time * 1e3);

   if(verbose){
      for (int i = 0; i < length; i++) {
         printf("%d ", input[i]);
      }
      putchar('\n');
   }

   free(input);

   return 0;
}
