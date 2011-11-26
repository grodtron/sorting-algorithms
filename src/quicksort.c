#include "../include/insertion_sort.h"

void quicksort(int data[], int length);
int getPivotIndex(int data[], int length);
void _swap(int*, int*);

void quicksort(int data[], int length){

   if(length < 15){
      insertion_sort(data, length);
   }                  // can't forget the all important exit condition!

   int pivot_i = getPivotIndex(data, length); // get the position of the pivot value
   int pivot_val = data[pivot_i];             // we'll store the value of the pivot
                                              // I think the four extra bytes are worth it
                                              // to avoid dereferencing a million times


   _swap(data + pivot_i, data + length - 1);   // move the pivot value to the end of the list
   pivot_i = length - 1;                      // keep in mind that we only moved the value of
                                              // the pivot pointer to the end of the list,
                                              // we need to update the pointer itself to point to
                                              // the end of the list as well

   for (int i = 0; i < pivot_i; ++i) {        // Here we loop through the list until we get to the
                                              // index of the pivot value. Keep in mind that the
                                              // pivot index decreases as we loop

      if(data[i] > pivot_val){                     // if the current value is greater than the pivot
         _swap(data + i, data + pivot_i - 1);       // then we move it behind the pivot. This is accomplished
         _swap(data + pivot_i - 1, data + pivot_i); // with two swaps. The first one moves the value to the
         --pivot_i;                                // index right before the pivot. The second switches the 
         --i;                                      // pivot with the element right before it, 
                                                   // which is the element we just moved there
                                                   // we then make sure we decrement the pivot index accordingly
                                                   // we also have to decrement i, otherwise we won't check
                                                   // against whatever we just swapped
      }
   }


   quicksort(data              , pivot_i             ); // This is the recursive component of the algorithm
   quicksort(data + pivot_i + 1, length - pivot_i - 1); // we send off the portion up to the pivot index
                                                        // and the portion following the pivot index to be sorted


}

int getPivotIndex(int data[], int length){
   return length / 2; // a simplistic approach for now
}

void _swap(int * a, int* b){
   int c = *a;
   *a = *b;
   *b = c;
}
