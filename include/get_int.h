#ifndef INCLUDE_GET_INT_H
#define INCLUDE_GET_INT_H
void getInt(int* returnValue, bool* success);
#endif

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
