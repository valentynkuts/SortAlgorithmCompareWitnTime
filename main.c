#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//-------
int partition(int A[], int p, int r);

void quickSort(int A[], int p, int r);

//-----------
int partitionD(int A[], int p, int r);

void quickSortDecrease(int A[], int p, int r);

//---------

void maxHeapify(int arr[], int size, int i);

void heapSort(int arr[], int sz);
//---------------
void selectSort(int A[], int size);

//---------------
void print(int a[], int size);

void copy(int a[], int b[], int size);

//---------

int main()
{
////=========== Random Increase Decrease arrays =======
//------------- Random array -------
    const int sz = 10000;
    int randArr[sz];     // for Random array

    srand(1);
    for (int i = 0; i<sz; i++) {
        randArr[i] = rand()%(1000-1)+1;
    }

//------------- Increase sorted array -------
    int sortedArr[sz];   // for Increase sorted array
    copy(sortedArr, randArr, sz);

    int p = 0;
    int r = sz-1;

    quickSort(sortedArr, p, r);


//---------------Decrease sorted array----
    int reverseSortedArr[sz];   // for Decrease sorted array
    copy(reverseSortedArr, randArr, sz);

    quickSortDecrease(reverseSortedArr, p, r);

////==================QUICKSORT Algorithm Test======================
    int randArrQuickSort[sz];   // Random array for QuickSort
    copy(randArrQuickSort, randArr, sz);

    int sortedArrQuickSort[sz];   // Increase sorted array for QuickSort
    copy(sortedArrQuickSort, sortedArr, sz);

    int reverseSortedArrQuickSort[sz];   // Decrease sorted array for QuickSort
    copy(reverseSortedArrQuickSort, reverseSortedArr, sz);

    printf("\n#################### QUICKSORT Algorithm Test ###################### \n");

    clock_t t1 = clock();
    quickSort(sortedArrQuickSort, p, r);
    clock_t t2 = clock();

    //print(sortedArrQuickSort, sz);
    printf("QuickSort Sorted(increase) array: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
//----

    t1 = clock();
    quickSort(randArrQuickSort, p, r);
    t2 = clock();

    printf("QuickSort Random arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

//----

    t1 = clock();
    quickSort(reverseSortedArrQuickSort, p, r);
    t2 = clock();

    printf("QuickSort Sorted(decrease) arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);


    ////==================HEAPSORT Algorithm Test======================
    int randArrHeapSort[sz];   // Random array for QuickSort
    copy(randArrHeapSort, randArr, sz);

    int sortedArrHeapSort[sz];   // Increase sorted array for QuickSort
    copy(sortedArrHeapSort, sortedArr, sz);

    int reverseSortedArrHeapSort[sz];   // Decrease sorted array for QuickSort
    copy(reverseSortedArrHeapSort, reverseSortedArr, sz);

    printf("\n#################### HEAPSORT Algorithm Test ############################ \n");
//----

    t1 = clock();
    heapSort(sortedArrHeapSort, sz);
    t2 = clock();

    printf("HeapSort Sorted(increase) array: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
//----

    t1 = clock();
    heapSort(randArrHeapSort, sz);
    t2 = clock();

    printf("HeapSort Random arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

//----
    t1 = clock();
    heapSort(reverseSortedArrHeapSort, sz);
    t2 = clock();

    printf("HeapSort Sorted(decrease) arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

    ////==================SELECTSORT Algorithm Test======================
    int randArrSelectSort[sz];   // Random array for QuickSort
    copy(randArrSelectSort, randArr, sz);

    int sortedArrSelectSort[sz];   // Increase sorted array for QuickSort
    copy(sortedArrSelectSort, sortedArr, sz);

    int reverseSortedArrSelectSort[sz];   // Decrease sorted array for QuickSort
    copy(reverseSortedArrSelectSort, reverseSortedArr, sz);

    printf("\n####################### SELECTSORT Algorithm Test ######################## \n");
//----
 t1 = clock();
    selectSort(sortedArrSelectSort, sz);
    t2 = clock();

    printf("SelectSort Sorted(increase) array: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
//----

    t1 = clock();
    selectSort(randArrSelectSort, sz);
    t2 = clock();

    printf("SelectSort Random arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

//----

    t1 = clock();
    selectSort(reverseSortedArrSelectSort, sz);
    t2 = clock();

    printf("SelectSort Sorted(decrease) arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
////==========================END===================
    return 0;
}

////============== QuickSortIncrease ==========================
int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = (p-1);

    for (int j = p; j<=r-1; j++) {
        if (A[j]<=x) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return (i+1);
}

void quickSort(int A[], int p, int r)  //for increase numbers
{
    if (p<r) {

        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

////============== QuickSortDecrease ==========================
int partitionD(int A[], int p, int r)
{
    int x = A[r];
    int i = (p-1);

    for (int j = p; j<=r-1; j++) {
        if (A[j]>=x) {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return (i+1);
}

void quickSortDecrease(int A[], int p, int r)
{
    if (p<r) {

        int q = partitionD(A, p, r);
        quickSortDecrease(A, p, q-1);
        quickSortDecrease(A, q+1, r);
    }
}

////=============== HeapSort =======================
void maxHeapify(int arr[], int size, int i) //i - index
{
    int l = 2*i+1;
    int r = l+1;//2*i+2

    int largest = i;

    if (l<size && arr[l]>arr[i]) {
        largest = l;
    }

    if (r<size && arr[r]>arr[largest]) {
        largest = r;
    }

    if (largest!=i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, size, largest);
    }

}

void heapSort(int arr[], int sz)
{
    // buildMaxHeap
    for (int i = sz/2-1; i>=0; i--)
        maxHeapify(arr, sz, i);

    for (int i = sz-1; i>=0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}

////============= SelectSort =======================
void selectSort(int A[], int size)
{

    for (int j = 0; j<size; j++) {
        int min = A[j];
        int min_pos = j;
        for (int i = j; i<size; i++) {
            if (A[i]<min) {
                min_pos = i;
                min = A[i];
            }
        }
        A[min_pos] = A[j];
        A[j] = min;
    }
}

////=========== Print ==================

void print(int a[], int size)
{
    for (int i = 0; i<size; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

////=========== Copy ==================
void copy(int a[], int b[], int size)
{
    for (int i = 0, j = 0; i<size; ++i, ++j) {
        a[i] = b[j];
    }
}