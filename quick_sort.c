/* C implementation QuickSort */
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  
    int i = (low - 1); 
 
    for (int j = low; j <= high- 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
 
       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
   
}
 
int main()
{
    
    
    
    int arr[500000],arr2[500000];

    for(int i=0;i<500000;i++){
        arr[i] = rand();
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t t;
    t = clock();
    quickSort(arr, 0, n-1);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nQuick Sort took %f seconds to sort 500000 random numbers \n", time_taken);

    
    for(int i=0;i<500000;i++){
        arr2[i]= i;
    }
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    clock_t t2;
    t2 = clock();
    quickSort(arr2, 0, n2-1);
    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
    printf("\nQuick Sort took %f seconds to sort 500000 sorted numbers \n", time_taken2);

    return 0;
}