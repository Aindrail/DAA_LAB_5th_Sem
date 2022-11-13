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
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low+1;
    int j=high;
    while(i<=j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[low],a[j]);
    return j;
}

void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}