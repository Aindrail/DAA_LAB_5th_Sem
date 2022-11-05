/*Write a program to find out GCD (greatest common divisor) using the following three
algorithms.
a) Euclid’s algorithm
b) Consecutive integer checking algorithm.
c) Middle school procedure which makes use of common prime factors. For finding list
of primes implement sieve of Eratosthenes algorithm
*/
#include<bits/stdc++.h>
#define MAXFACTORS 1024
using namespace std;
typedef struct{
   int size;
   int factor[MAXFACTORS + 1];
   int exponent[MAXFACTORS + 1];
} FACTORIZATION;
int gcd(int a,int b,int &step)
{
    step++;
    if(b==0)
        return a;
    return gcd(b,a%b,step);
}
int gcd_consecutive(int a,int b,int &step)
{
    int res=min(a,b);
    while(res>0)
    { step++;
        if(a%res==0 && b%res==0)
            return res;
        res--;
    }
    return res;
}
void FindFactorization(int x, FACTORIZATION* factorization){
   int i, j = 1;
   int n = x, c = 0;
   int k = 1;
   factorization->factor[0] = 1;
   factorization->exponent[0] = 1;
   for (i = 2; i <= n; i++) {
      c = 0;
      while (n % i == 0) {

         c++;
         n = n / i;
      }
      if (c > 0) {
         factorization->exponent[k] = c;
         factorization->factor[k] = i;
         k++;
      }
   }
   factorization->size = k - 1;
}
int gcdMiddleSchoolProcedure(int m, int n,int &step){
   FACTORIZATION mFactorization, nFactorization;
   int r, mi, ni, i, k, x = 1, j;
   FindFactorization(m, &mFactorization);
   FindFactorization(n, &nFactorization);
   int min;
   i = 1;
   j = 1;
   while (i <= mFactorization.size && j <= nFactorization.size) {
    step++;
      if (mFactorization.factor[i] < nFactorization.factor[j])
         i++;
      else if (nFactorization.factor[j] < mFactorization.factor[i])
         j++;
      else{
         min = mFactorization.exponent[i] > nFactorization.exponent[j] ? nFactorization.exponent[j] : mFactorization.exponent[i];
         x = x * mFactorization.factor[i] * min;
         i++;
         j++;
      }
   }
   return x;
}
int main()
{
    int n ;
    cout<<"Enter the number"<<endl;
      cin>>n;
      vector<pair<int,int>> v;
      for(int i =0;i<n;i++){
         cout<<"Enter two numbers: \n";
         int a,b;
         cin>>a>>b;
         v.push_back(make_pair(a,b));
      }

    
    cout<<"Sl No."<<"\t"<<"Number"<<"\t "<<"Step1"<<"\t"<<"Step2"<<"\t"<<"Step3"<<"\t"<<"GCD value"<<endl;
    for(int i =0;i<n;i++){
      int a = v[i].first;
      int b = v[i].second;
      int step=0;
       int  gcdVal= gcd(a, b, step);
        int step2=0;
        gcd_consecutive(a,b,step2);
        int step3=0;
        gcdMiddleSchoolProcedure(a,b,step3);
        cout<<1<<"\t"<<a<<" "<<b<<"\t"<<step<<"\t"<<step2<<"\t"<<step3<<"\t"<<gcdVal<<endl;
    }
    
    return 0;
}
