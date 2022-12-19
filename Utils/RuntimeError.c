
#include <stdio.h>
#include "RuntimeError.h"

void RuntimeError(const char * message, int parameter, const char * file, int line)
{
    printf("Run time error in ");
    printf(file);
    printf(": %d\n", line);
    printf("With message: ");
    printf(message);
    printf("\nparameter: %d\n", parameter);
}