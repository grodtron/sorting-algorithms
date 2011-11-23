#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bool.h"
#include "../include/linked_list.h"
#include "../include/get_int.h"

int main(int argc, const char *argv[])
{
   int input;
   bool inputStatus;

   struct listNode *list_head  = NEW_LISTNODE;
   struct listNode *list_position = list_head;

   list_head->prev  = NULL;
   list_head->next  = NULL;

   // get the input list of integers
   while(1){

      getInt(&input, &inputStatus);

      if(inputStatus){
         list_position->value = input;
         add_after(list_position, NEW_LISTNODE);
         list_position = list_position->next;
      }else{
         break;
      }
   }

   // SETUP TIMING
   struct timespec start_time;
   struct timespec end_time;

   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
   // END SETUP TIMING

   // SORT!!!!!!!!!!!!!!!!!!!!!!!!!
   list_head = insertion_sort(list_head);

   // FINISH TIMING!
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

   double elapsed_time = difftime(end_time.tv_sec, start_time.tv_sec) + (1e-9 * (double)(end_time.tv_nsec - start_time.tv_nsec)) ;
   // END FINISH TIMING!

   printf("%.9f\n", elapsed_time * 1e3);

   /*
   list_position = list_head;
   while(list_position->next != NULL){
      printf("%d ", list_position->value);
      list_position = list_position->next;
   }
   putchar('\n');
*/
   free_list(list_head);

   return 0;
}
