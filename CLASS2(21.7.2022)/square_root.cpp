/*Write a program using a function for computing ⌊√n⌋ for any positive integer.
Besides assignment and comparison, your algorithm may only use the four basic
arithmetic operations.*/
#include<bits/stdc++.h>
using namespace std;
int floor_root(int n)
{
    int i=1;
    while(i*i<=n)
    {
        i++;
    }
    return i-1;
}
int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<"The floor root of "<<n<<" is "<<floor_root(n)<<endl;
    return 0;
}
