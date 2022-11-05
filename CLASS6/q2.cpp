/*
Write a program to sort a list of n elements using the Merge Sort method and determine
the time required to sort the elements. Repeat the experiment for different values of n and
different nature of data (random data, sorted data, reversely sorted data) in the list. n is
the user input and n integers can be generated randomly. Finally plot a graph of the time
taken versus n.
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = rand()%100;
    }
    cout<<"Array is: ";
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"Sorted array is: ";
    printArray(arr,n);
    return 0;
}

