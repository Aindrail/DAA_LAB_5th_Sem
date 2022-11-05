/*Suppose an array A has n distinct integers. Increasing sequence is given as
A[1]....A[k] and decreasing sequence is given as A[k+1]....A[n].*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
            }
        }
    }
    cout<<"The number of distinct elements in the array are "<<count<<endl;
    return 0;
}