/*
Dekho be - you have to identify numbers whose xor is a sum of primes.
What is a sum of primes?
23+41 = 64;
23x1 + 41x1 = 64

otherwise,
24 + 34 = 85;
3x8x1 + 17x2 = 58;

Now, what do you have? The sum (say X).
We have to check if X is a sum of primes. How?
1. One method is simple: check if X-2 is prime, if not, then if X-3 is prime,
                        then X-5 and so on ...
But this is fucked as shit and I am not doing it.
So, something else...

2. One fact: if X-2 != prime, then the number is even, for the exception of X=4.
So, an even number is essentially: X/2 + X/2
So we can look for primes in (2, X/2] and (X/2, X-2)
and check if the sum of any pair gives us X.
... or better, check for primes in (2, X/2] and if X-prime = prime.
This is still computation intensive.

Man, this is the same as 1 computation wise - in fact, it is EXACTLY the same as
1 in all wise-es.

3. Factorise.
64 = 8x8
    = 23 + 41
    = 8*2 + 5 + 8*5 + 1
    = 8x(7) + 6

4. Bhak bc.
See, every even number can be represented as a sum of primes (Goldbach's
Conjecture). That holds for everything greater than 2. Yay!
So our solution becomes all the pairs which give an even XOR, as only even
numbers can be represented as a sum of 2 odd numbers (which we can be hoped to
be prime).
Okay - so top down once more.
You have a value X that can be represented as a sum of 2 primes. Only odd numbers
are prime (assume for now). Hence this value is always going to be even.
Now, X is actually a XOR of 2 elements from our array. That means that BOTH the
elements are either going to be even (0^0=0) or odd (1^1=0) to make the last bit
of the number 0.
So, we simply have to find all possible pairs of odd-odd and even-even numbers in
the given array.

how to do that? odd numbers - o; even numbers - n
So, make an equation. oC2 + eC2
Now, breaking the assumption: 2 is also a prime. But that case is already
covered as we have included all possible even numbers already.
But: 2 and 0 are even numbers, we need to exclude them from the count.
So,
q1. When do 2 numbers have xor 0?
When they are same.
q1. When do 2 numbers have xor 2?
When they have a difference of 2.
*/

#include <stdio.h>
#include <stdlib.h>



void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}



int main()
{
    int T;
    scanf("%d", &T);

    int N[T], *arr[T], e_c[T], c;

    for (int i=0; i<T; i++)
    {
        scanf("%d", &N[i]);

        arr[i] = malloc( sizeof(int) * N[i] );

        e_c[i] = N[i]-1;
        int j = 0;
        while ( j + N[i]-1-e_c[i] != N[i] )
        {
            /*
            From where do we get no. of iterations?
            num_of_times j has icremented + num_of_times e_c[i] has decremented
            j + (N[i]-1-e_c[i])
            */

            scanf("%d", &c);
            if (c%2 == 0)
            {
                arr[i][j] = c;
                j++;
            }
            else
            {
                arr[i][e_c[i]] = c;
                e_c[i]--;
            }
        }
        e_c[i]++;

        /*
        for (int j=0; j<N[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
        */
    }


    unsigned int pcnt, fpcnt, o, e, a, b;
    int k1, k2;

    for (int i=0; i<T; i++)
    {
        pcnt = 0;
        fpcnt = 0;
        int temp[N[i]];

        mergeSort(arr[i], e_c[i], N[i]-1);
        mergeSort(arr[i], 0, e_c[i]-1);

        //printf("%d %d\n", o, e);

        for (int j=0; j<N[i]; j++)
        {
            temp[j] = arr[i][j];
        }

        int num_oc = 0;

        for (int j=0; j<e_c[i]; j++)
        {
            int k = j+1;
            while ( (temp[j] == temp[k]) && (k < e_c[i]) )
            {
                k++;
                //printf("%d %d\n", temp[j], temp[k-1]);
            }

            num_oc = k-j;
            fpcnt += num_oc*(num_oc-1)/2;

            //printf("%d\n", fpcnt);

            j = k-1;
            //printf("%d %d\n", temp[j], e_c[i]);
            if ( temp[j] % 4 == 0 )
            {
                if ( (j <= e_c[i]-2) && ( temp[j+1]-temp[j] == 2 ) )
                {
                    //printf("%d\n", temp[j]);
                    k = j+1;
                    while ( (temp[k] == temp[k+1]) && (k+1 < e_c[i]) )
                    {
                        k++;
                    }
                    //printf("%d %d\n", temp[j], temp[k-1]);
                    fpcnt += num_oc*(k-j);
                }

                //printf("%d ", temp[j]);
            }
            //printf("%d\n", fpcnt);
        }

        for (int j=e_c[i]; j<N[i]; j++)
        {
            //printf("%d %d\n", temp[j], j);
            int k = j+1;
            while ( (temp[j] == temp[k]) && (k < N[i]) )
            {
                k++;
                //printf("%d %d\n", temp[j], temp[k-1]);
            }

            num_oc = k-j;
            fpcnt += num_oc*(num_oc-1)/2;

            j = k-1;
            if ( temp[j] % 4 == 1 )
            {
                if ( (j <= N[i]-2) && ( temp[j+1]-temp[j] == 2 ) )
                {
                    //printf("%d\n", temp[j]);
                    k = j+1;
                    while ( (temp[k] == temp[k+1]) && (k+1 < N[i]) )
                    {
                        k++;
                    }
                    //printf("%d %d\n", temp[j], temp[k-1]);
                    fpcnt += num_oc*(k-j);
                }
            }
        }

        a =  e_c[i];
        b = N[i]-e_c[i];
        //printf("%d %d %d\n", a, b, fpcnt);

        a = a*(a-1)/2;
        b = b*(b-1)/2;

        pcnt = a + b - fpcnt;
        printf("%d\n", pcnt);

    }

    return 0;
}
