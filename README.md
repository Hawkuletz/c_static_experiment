# C static experiment
Plain C "namespace" experiment for "private" functions (i.e. functions that
can only be called using function pointers from within structs)

The main program (ex.c) only needs to include buru.h and mumu.h

Those header files define the respective structs as well as a function
prototype needed to initialize the "object" (struct). Those functions have
different names (i.e. init\_mumu and init\_buru)

Those commonly named methods (getmsg and setmsg) are implemented by static
functions getmsg and setmsg in buru.c and mumu.c

getmsg and setmsg are not visible to the main program (ex.c) except as
function pointers inside buru or mumu structures.

Of course, by doing this, we lose type protection offered by the compiler,
i.e. one could call buru-\>setmsg(mumu *,...) because afaik there is no concept of
"this" in plain C (one has to have the corresponding struct passed as an
argument to the method).

This is only "proof-of-concept" to settle an argument, nothing more.

Build with GNU make
