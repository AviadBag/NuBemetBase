#include <stdio.h>

/*
 If TEST is defined, it means that we are compiled for unit-testing, and we already have one main() - the main
 of the tester, and no more than one main is allowed.
 */
#ifndef TEST
int main()
{
    printf("BOOOOOOO4!\n");
    return 0;
}
#endif