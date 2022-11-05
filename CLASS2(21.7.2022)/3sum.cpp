//3sum is equal to k
#include<iostream>
using namespace std;
void threeSum(int a[], int n, int k)
{
    int i, j, l;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(l=j+1;l<n;l++)
            {
                if(a[i]+a[j]+a[l]==k)
                {
                    cout<<a[i]<<" "<<a[j]<<" "<<a[l]<<endl;
                }
            }
        }
    }
}
int main(){
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
    threeSum(a,n,k);
    return 0;

}


