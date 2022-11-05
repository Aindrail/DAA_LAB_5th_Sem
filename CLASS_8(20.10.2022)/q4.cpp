//matrix chain multiplication code
#include <bits/stdc++.h>
using namespace std;
int matrixChainMultiplication(int arr[], int i, int j)
{
    if (i == j)
        return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int count = matrixChainMultiplication(arr, i, k) + matrixChainMultiplication(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (count < min)
            min = count;
    }
    return min;
}
int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int arr[n];
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Minimum number of multiplications is " << matrixChainMultiplication(arr, 1, n - 1);
    return 0;
}