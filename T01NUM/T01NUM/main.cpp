
#include "num.h"

int main()
{
    Number N = -55;

    for (; N < 100.1;)
    {
        N = (N + 1);
        printf ("Number is: %d", !N);
    }

    return 0;
}