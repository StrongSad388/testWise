#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

u_long bitwiseAnd(u_long n, u_long m)
{
    printf("%lu & %lu = %lu\n", n, m, n&m);
    return n & m;
}

int main(int argc, char * argv[])
{
    u_long op1 = 0, op2 = 100;
    if (argc > 2)
    {
        op1 = strtoul(argv[1], NULL, 10);
        op2 = strtoul(argv[2], NULL, 10);
        if (op1 > op2)
        {
            op1 = strtoul(argv[2], NULL, 10);
            op2 = strtoul(argv[1], NULL, 10);
        }
    }
    u_long intermediateValue = op1;
    for (int i = op1; i < op2; i++)
    {
        //printf("%d %d\n", intermediateValue, i+1);
        intermediateValue = bitwiseAnd(intermediateValue, i + 1);
    }
    printf("%lu\n", intermediateValue);
    return intermediateValue;
}