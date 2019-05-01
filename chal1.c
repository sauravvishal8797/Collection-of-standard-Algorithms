#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int T;
    scanf("%d", &T);

    int N, X, S, A[T], a, b;

    for (int i=0; i<T; i++)
    {
        scanf("%d %d %d", &N, &X, &S);

        int s = 0;
        x:

        //printf("%d\n", X);
        if (s == S)
        {
            A[i] = X;
            //printf("%d ", A[i]);
            continue;
        }

        s++;

        scanf("%d %d", &a, &b);

        if (a == X)
        {
            X = b;
        }
        else if (b == X)
        {
            X = a;
        }

        goto x;
    }

    for (int i=0; i<T; i++)
    {
        printf("%d\n", A[i]);
    }

    return 0;
}
