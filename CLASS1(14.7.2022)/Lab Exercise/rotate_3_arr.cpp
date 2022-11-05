/*Write a program that takes three variable (a, b, c) as separate parameters and
rotates the values stored so that value a goes to be, b, b to c and c to a by using
SWAP(x,y) function that swaps/exchanges the numbers x & y.
*/
#include <bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    swap(a,b);
    swap(a,c);
    // swap(a,c);
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}