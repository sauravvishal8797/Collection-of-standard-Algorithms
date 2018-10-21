#include <stdio.h>

int main ()
{
    int T;
    scanf("%d", &T);

    int N, M, X, Y, A[T], a, b;

    for (int i=0; i<T; i++)
    {
        scanf("%d %d %d %d", &N, &M, &X, &Y);
        N--; M--;

        if ( (N==1 && M==1) || (N==0 && M==0) )
        {
            A[i] = 1;
        }
        else
        {
            if ( N%X==0 && M%Y==0 )
            {
                A[i] = 1;
            }
            else if ( N > 0 && M > 0 )
            {
                a = N-1;
                b = M-1;
                if ( a%X==0 && b%Y==0 )
                {
                    A[i] = 1;
                }
                else
                {
                    A[i] = 0;
                }
            }
            else
            {
                A[i] = 0;
            }
        }
        //printf("%d, %d ", i, A[i]);
    }

    for (int i=0; i<T; i++)
    {
        //printf("%d %x ", i, A[i]);
        if (A[i] == 1)
        {
            printf("Chefirnemo\n");
        }
        else if (A[i] == 0)
        {
            printf("Pofik\n");
        }
    }

    return 0;
}
