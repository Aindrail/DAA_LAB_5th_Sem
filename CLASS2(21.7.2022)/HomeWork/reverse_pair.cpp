/*Write an algorithm for finding counting inversions in an array. Inversion is a
pair such that for an array A = {a1, a2, a3,...., an}, and ai > aj and i < j.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int merge(vector<int>& nums,int left ,int mid, int right){

        int n = mid - left + 1;
        int m = right - mid;
        int a[n];
        int b[m];
        for(int i=0; i<n; ++i){
            a[i] = nums[i + left];
        }
        for(int i=0; i<m; ++i){
            b[i] = nums[mid + i + 1];
        }
    
        int i=left, j=mid+1, count = 0;
       
        
        //Merging elements
        
        i = 0, j = 0;
        int k = left;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                nums[k++] = a[i];
                ++i;
            }else{
                nums[k++] = b[j];
                count += n - i  ; 
                ++j;
            }
        }
        while(i < n){
            nums[k++] = a[i];
            ++i;
        }
        while(j < m){
            nums[k++] = b[j];
            ++j;
        }
        return count;
    
    }
    int mergeSort(vector<int>& nums,int low , int high){
        if(low>=high) return 0;
        int ans =0;
        int mid = (low+high)/2;
        ans+=mergeSort(nums,low,mid);
        ans+=mergeSort(nums,mid+1,high);
        ans+=merge(nums,low,mid,high);
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
int main()
{
    Solution s;
    cout<<"Enter the number of elements"<<endl;
    int n;
    cin>>n;
    vector<int> nums;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums.push_back(x);
    }
    
    cout<<s.reversePairs(nums)<<endl;
    return 0;
}