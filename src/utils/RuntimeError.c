
#include <stdio.h>
#include "RuntimeError.h"

void RuntimeError(const char * message, int parameter, const char * file, int line)
{
    printf("Run time error in file:\n");
    printf("%s", file);
    printf(": line, %d\n", line);
    printf("With message:\n");
    printf("%s", message);
    printf("parameter: %d\n\n", parameter);
}