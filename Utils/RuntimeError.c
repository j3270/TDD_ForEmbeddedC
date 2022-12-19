
#include <stdio.h>
#include "RuntimeError.h"

void RuntimeError(const char * message, int parameter, const char * file, int line)
{
    printf("Run time error in file:\n");
    printf(file);
    printf(": line, %d\n", line);
    printf("With message:\n");
    printf(message);
    printf("parameter: %d\n\n", parameter);
}