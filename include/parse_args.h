#include <stdlib.h>
#include "bool.h"

struct parameters {
   bool verbose;
   int length;
};

void parse_args(int argc, const char* argv[], struct parameters* params);
