#!/bin/bash

## Prechecks to make sure the files exist
if [ ! -d "bin" ]; then mkdir bin; fi
if [ ! -d "source" ]; then mkdir source; fi
if [ ! -f "source/00-template.c" ];
then
echo "#include <stdio.h>
#include <stdlib.h>

int main() {
    printf(\"Hello, World!\\n\");
    return 0;
}
" > source/00-template.c
fi

## handle name i/o
PRONAME=$1
if [ ! -f "source/$PRONAME.c" ]; then cp source/00-template.c source/$PRONAME.c;fi
#nano source/$PRONAME.c
gcc source/$PRONAME.c -o bin/$PRONAME
valgrind bin/$PRONAME
