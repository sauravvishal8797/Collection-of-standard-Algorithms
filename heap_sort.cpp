// C++ program for implementation of Heap Sort
#include <iostream>
#include<time.h>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
 

void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
   
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
       
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i=n-1; i>=0; i--)
    {
        
        swap(arr[0], arr[i]);
 
        
        heapify(arr, i, 0);
    }
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    int lower=0; int upper=500000;
    int arr[500000],arr2[500000];

    for(int i=0;i<500000;i++){
        arr[i] = (rand() + lower) % (upper + 1);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t t;
    t = clock();

    heapSort(arr, n);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\nHeap Sort took %f seconds to execute random \n", time_taken);
 
    for(int i=0;i<500000;i++){
        arr2[i]= i;
    }
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    clock_t t2;
    t2 = clock();

    heapSort(arr2, n2);

    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC; // in seconds
    printf("\nHeap Sort took %f seconds to execute sorted \n", time_taken2);

}