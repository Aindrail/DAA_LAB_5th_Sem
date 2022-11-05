/*The quick sort algorithm is an efficient and popular sorting technique that sorts a list of
keys recursively by choosing a pivot key. A pivot may be chosen as the first or last or
mean or median or any random element of the list. Write a program to implement this
sorting algorithm and execute the sorting programs for the following sets of data.
i. Ordered List
ii. Reverse order List
iii. A list containing the same value through out
iv. Random List
v. 50% of the List sorted
*/
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    clock_t start, end;
    int n;
    int expression;
    cout<<"Enter \n 1.Order List\n 2.Reverse order List\n 3.A list containing the same value through out\n 4.Random List\n 5.50% of the List sorted\n";
    cin>>expression;

   switch (expression)
   {
   case 1:
       cout<<"Enter the size of array: ";
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           arr[i]=i;
       }
       cout<<"Array is: ";
       printArray(arr,n);
       start = clock();
       quickSort(arr,0,n-1);
       end = clock();
       cout<<"Sorted array is: ";
       printArray(arr,n);
       cout<<"Time taken by quick sort is: "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
       break;
    break;
   
   default:
    break;
   }





    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%n;
    }
    cout<<"Array is: ";
    printArray(arr,n);
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    cout<<"Sorted array is: ";
    printArray(arr,n);
    cout<<"Time taken by quick sort is: "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return 0;
}
