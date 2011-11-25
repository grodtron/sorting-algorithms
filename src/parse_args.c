#include <stdlib.h>
#include "../include/bool.h"
#include "../include/parse_args.h"

void parse_args(int argc, const char* argv[], struct parameters* params){
   params->length = -1;
   params->verbose = false;
   for (int i = 1; i < argc; i++) {
      switch( argv[i][0] ){

         case 'v':
            params->verbose = true;
            break;

         case '0': case '1': case '2': case '3': case '4':
         case '5': case '6': case '7': case '8': case '9':
            params->length = atoi(argv[i]);
            break;


      }
   }
}


