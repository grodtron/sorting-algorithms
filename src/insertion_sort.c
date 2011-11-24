#include <stdlib.h>

void swap(int* a, int* b){
   int c = *a;
   *a = *b;
   *b = c;
}

void insertion_sort(int data[], int length){

   for (int i = 0; i < length; i++) {

      // check the item to the left of the current item.
      // if it is greater than the current item, then swap them
      for (int j = i; j > 0; --j) {
         if(data[j] < data[j - 1]){
            swap(data + j, data + j - 1);
         }
      }
   }
}
