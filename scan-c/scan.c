
#include <string.h>  // for strcmp()
#include <stdlib.h>  // for malloc(), strtod()
#include <stdio.h>   // for printf


// NOTE: this code has bugs.

void
integrate(double dst[], double const src[], int n)
{
    double acc = 0;
    for (int i = 1; i <= n; ++i)
    {
        acc += src[i - 1];
        dst[i] = acc;
    }
}

// Error checking elided for clarity.

int
main(int argc, char* argv[])
{
    if (argc < 2 || strcmp(argv[1], "-h") == 0)
    {
        printf(
"raw(Usage:\n"
"  scan <numbers>...\n"
"\n"
"Computes the scan of the given sequence of numbers.\n");
        return 0;
    }

    // We can assume `argc > 1` henceforth.

    int n = argc - 1;
    double* src = malloc(sizeof(double)*n);
    double* dst = malloc(sizeof(double)*n);
    for (int i = 0; i < n; ++i)
    {
        char* arg = argv[i + 1];
        char* argEnd = arg + strlen(arg);
        src[i] = strtod(arg, &argEnd);
    }

    integrate(dst, src, n);

    for (int i = 0; i < n; ++i)
    {
        printf("%g ", dst[i]);
    }
    printf("\n");

    free(src);
    free(dst);
}
