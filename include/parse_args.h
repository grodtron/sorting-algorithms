#ifndef INCLUDE_PARSE_ARGS_H
#define INCLUDE_PARSE_ARGS_H

#include <stdlib.h>
#include "bool.h"

struct parameters {
   bool verbose;
   int length;
};

void parse_args(int argc, const char* argv[], struct parameters* params);

#endif
