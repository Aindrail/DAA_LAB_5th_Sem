/*Let A be n*n square matrix array. WAP by using appropriate user defined
functions for the following:
a) Find the number of nonzero elements in A
b) Find the sum of the elements above the leading diagonal.
c) Display the elements below the minor diagonal.
d) Find the product of the diagonal elements.*/
// Language: cpp
#include<bits/stdc++.h>
using namespace std;
int nonzero(vector<vector<int>> a, int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                count++;
            }
        }
    }
    return count;
}
int sum_above_diagonal(vector<vector<int>>a, int n)
{ int  sum_up_diag = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<j){
                sum_up_diag+=a[i][j];

            }      
        }
        
    }
    return sum_up_diag;
}
void display_below_diagonal(vector<vector<int>> a, int n)
{
    for(int i =0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            if(j>n-i-1)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"   ";
        }
        cout<<endl;
    }
}
int product_diagonal(vector<vector<int>>a, int n)
{
    int product = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                product*=a[i][j];
            }
            if(j==n-i-1){
                
                product*=a[i][j];
            }
        }}
        return product;
}
int main()
{
    int n;
    cout<<"Enter the number of rows and columns"<<endl;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The number of nonzero elements in the matrix is "<<nonzero(a,n)<<endl;

    cout<<"The sum of the elements above the leading diagonal is "<<sum_above_diagonal(a,n)<<endl;
    cout<<"The elements below the minor diagonal are "<<endl;
    display_below_diagonal(a,n);
    cout<<endl;
    cout<<"The product of the diagonal elements is "<<product_diagonal(a,n)<<endl;
    return 0;
}
