#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//-------
int partition(int A[], int p, int r);

void quickSort(int A[], int p, int r);

//-----------
int partitionD(int A[], int p, int r);

void quickSortDecrease(int A[], int p, int r);

//--------
//void maxHeapify(int arr[], int size, int i);
//
//void buildMaxHeap(int arr[], int size);
//
//void heapSort(int A[], int size);
//
////--------
//void swap(int* a, int* b);
//
//void heapify(int arr[], int n, int i);
//
//void heapSort1(int arr[], int n);
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
    //const int sz = 20;
    int randArr[sz];     // for Random array

    srand(1);
    for (int i = 0; i<sz; i++) {
        randArr[i] = rand()%(1000-1)+1;
    }

//    printf("=========== Random Increase Decrease arrays ======= \n");
//    printf("Random array: \n");
//    print(randArr, sz);

//------------- Increase sorted array -------
    int sortedArr[sz];   // for Increase sorted array
    copy(sortedArr, randArr, sz);
    //print(sortedArr,sz);

    int p = 0;
    int r = sz-1;

    //clock_t b = clock();
    quickSort(sortedArr, p, r);
    //clock_t e = clock();

    //printf("Increase sorted array: \n");
    //print(sortedArr, sz);
    //printf("QuickSort:  %d  ticks ( %f  seconds) \n", e-b, (e-b)/(double) CLOCKS_PER_SEC);
//---------------Decrease sorted array----
    int reverseSortedArr[sz];   // for Decrease sorted array
    copy(reverseSortedArr, randArr, sz);
    //print(reverseSortedArr,sz);

    //b = clock();
    quickSortDecrease(reverseSortedArr, p, r);
    //e = clock();

    //printf("Decrease sorted  array: \n");
    //print(reverseSortedArr, sz);
    //printf("QuickSort:  %d  ticks ( %f  seconds)", e-b, (e-b)/(double) CLOCKS_PER_SEC);
    //printf("\n\n");

////==================QUICKSORT Algorithm Test======================
    int randArrQuickSort[sz];   // Random array for QuickSort
    copy(randArrQuickSort, randArr, sz);

    int sortedArrQuickSort[sz];   // Increase sorted array for QuickSort
    copy(sortedArrQuickSort, sortedArr, sz);

    int reverseSortedArrQuickSort[sz];   // Decrease sorted array for QuickSort
    copy(reverseSortedArrQuickSort, reverseSortedArr, sz);

    printf("\n#################### QUICKSORT Algorithm Test ###################### \n");
//    print(sortedArrQuickSort, sz);
//    print(randArrQuickSort, sz);
//    print(reverseSortedArrQuickSort, sz);

//----
    //printf("==================QuickSort Sorted(increase) array====================== \n");

    //print(sortedArrQuickSort, sz);
    clock_t t1 = clock();
    quickSort(sortedArrQuickSort, p, r);
    clock_t t2 = clock();

    //print(sortedArrQuickSort, sz);
    printf("QuickSort Sorted(increase) array: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
//----
    //printf("==================QuickSort Random array====================== \n");

    //print(randArrQuickSort, sz);
    t1 = clock();
    quickSort(randArrQuickSort, p, r);
    t2 = clock();

    //print(randArrQuickSort, sz);
    printf("QuickSort Random arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

//----
    //printf("==================QuickSort Sorted(decrease) array====================== \n");

    // print(reverseSortedArrQuickSort, sz);
    t1 = clock();
    quickSort(reverseSortedArrQuickSort, p, r);
    t2 = clock();

    //print(reverseSortedArrQuickSort, sz);
    printf("QuickSort Sorted(decrease) arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);


    ////==================HEAPSORT Algorithm Test======================
    int randArrHeapSort[sz];   // Random array for QuickSort
    copy(randArrHeapSort, randArr, sz);

    int sortedArrHeapSort[sz];   // Increase sorted array for QuickSort
    copy(sortedArrHeapSort, sortedArr, sz);

    int reverseSortedArrHeapSort[sz];   // Decrease sorted array for QuickSort
    copy(reverseSortedArrHeapSort, reverseSortedArr, sz);

    printf("\n#################### HEAPSORT Algorithm Test ############################ \n");
//    print(sortedArrHeapSort, sz);
//    print(randArrHeapSort, sz);
//    print(reverseSortedArrHeapSort, sz);

//----
    //printf("==================HeapSort Sorted(increase) array====================== \n");

    //print(sortedArrHeapSort, sz);
    t1 = clock();
    heapSort(sortedArrHeapSort, sz);
    //heapSort1(sortedArrHeapSort, sz);
    t2 = clock();

    //print(sortedArrHeapSort, sz);
    printf("HeapSort Sorted(increase) array: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
//----
    //printf("==================HeapSort Random array====================== \n");

    //print(randArrHeapSort, sz);
    t1 = clock();
    heapSort(randArrHeapSort, sz);
    //heapSort1(randArrHeapSort, sz);
    t2 = clock();

    //print(randArrHeapSort, sz);
    printf("HeapSort Random arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

//----
    //printf("==================HeapSort Sorted(decrease) array====================== \n");

    //print(reverseSortedArrHeapSort, sz);
    t1 = clock();
    heapSort(reverseSortedArrHeapSort, sz);
    //heapSort1(reverseSortedArrHeapSort, sz);
    t2 = clock();

    //print(reverseSortedArrHeapSort, sz);
    printf("HeapSort Sorted(decrease) arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

    ////==================SELECTSORT Algorithm Test======================
    int randArrSelectSort[sz];   // Random array for QuickSort
    copy(randArrSelectSort, randArr, sz);

    int sortedArrSelectSort[sz];   // Increase sorted array for QuickSort
    copy(sortedArrSelectSort, sortedArr, sz);

    int reverseSortedArrSelectSort[sz];   // Decrease sorted array for QuickSort
    copy(reverseSortedArrSelectSort, reverseSortedArr, sz);

    printf("\n####################### SELECTSORT Algorithm Test ######################## \n");
//    print(sortedArrSelectSort, sz);
//    print(randArrSelectSort, sz);
//    print(reverseSortedArrSelectSort, sz);

//----
    //printf("==================SelectSort Sorted(increase) array====================== \n");

    //print(sortedArrSelectSort, sz);
    t1 = clock();
    selectSort(sortedArrSelectSort, sz);
    t2 = clock();

    //print(sortedArrSelectSort, sz);
    printf("SelectSort Sorted(increase) array: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);
//----
    //printf("==================SelectSort Random array====================== \n");

    //print(randArrSelectSort, sz);
    t1 = clock();
    selectSort(randArrSelectSort, sz);
    t2 = clock();

    //print(randArrSelectSort, sz);
    printf("SelectSort Random arrays: %f seconds (%d  ticks)\n", (t2-t1)/(double) CLOCKS_PER_SEC, t2-t1);

//----
    //printf("==================SelectSort Sorted(decrease) array====================== \n");

    //print(reverseSortedArrSelectSort, sz);
    t1 = clock();
    selectSort(reverseSortedArrSelectSort, sz);
    t2 = clock();

    //print(reverseSortedArrSelectSort, sz);
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

//////=============== HeapSort =======================
//
//void maxHeapify(int arr[], int size, int i) //i - index
//{
//    int l = 2*i+1;
//    int r = 2*i+2;
//    //int l = 2 * i ;
//    //int r = 2 * i + 1;
//    int largest;
//    //int largest = i;
//    int temp;
//
//    if (l<=size && arr[l]>arr[i]) {
//        largest = l;
//    }
//    else {
//        largest = i;
//    }
//
//    if (r<=size && arr[r]>arr[largest]) {
//        largest = r;
//    }
//
//    if (largest!=i) {
//        temp = arr[i];
//        arr[i] = arr[largest];
//        arr[largest] = temp;
//
//        maxHeapify(arr, size, largest);
//    }
//}
//
//void buildMaxHeap(int arr[], int size)
//{
//    int n = (size-1)/2;
//    for (int i = n; i>=0; i--)
//        maxHeapify(arr, size, i);
//}
//
//void heapSort(int A[], int size)
//{
//    buildMaxHeap(A, size);
//    int temp;
//    int heapSize = size;
//    for (int i = size; i>=1; i--) {
//        temp = A[i];
//        A[i] = A[0];
//        A[0] = temp;
//
//        heapSize = heapSize-1;
//        maxHeapify(A, heapSize, 0);
//    }
//}
//////=============== HeapSort 1=======================
//
//void swap(int* a, int* b)
//{
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//
//void heapify(int arr[], int n, int i)
//{
//    int largest = i;
//    int l = 2*i+1;
//    int r = 2*i+2;
//
//    // if left child is larger than root
//    if (l<n && arr[l]>arr[largest])
//        largest = l;
//
//    // if right child is larger than largest so far
//    if (r<n && arr[r]>arr[largest])
//        largest = r;
//
//    // if largest is not root
//    if (largest!=i) {
//        swap(&arr[i], &arr[largest]);
//
//        // recursively heapify the affected sub-tree
//        heapify(arr, n, largest);
//    }
//}
//
//void heapSort1(int arr[], int n)
//{
//    // build heap (rearrange array)
//    for (int i = n/2-1; i>=0; i--)
//        heapify(arr, n, i);
//
//    // one by one extract an element from heap
//    for (int i = n-1; i>=0; i--) {
//        // move current root to end
//        swap(&arr[0], &arr[i]);
//
//        // call max heapify on the reduced heap
//        heapify(arr, i, 0);
//    }
//}

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