#include "common_header.hh"


void countSubsequenceWithTargetSumHelper(vector<int>& nums, int sum, int index, int &ans){
    if(sum==0){
        ans++;
        return ;
    }
    if(sum < 0 || index==nums.size())
        return; 
    countSubsequenceWithTargetSumHelper(nums, sum - nums[index], index+1, ans);
    countSubsequenceWithTargetSumHelper(nums, sum, index+1, ans);
}

int countSubsequenceWithTargetSum(vector<int>& nums, int sum){
    int index = 0 ;
    int ans = 0 ; 
    countSubsequenceWithTargetSumHelper(nums, sum, index, ans);
    return ans ;
}

void test_countSubsequenceWithTargetSum(){
    vector<int> nums = {4, 9, 2, 5, 1};
    int k = 10;
    int ans = countSubsequenceWithTargetSum(nums, k);
    cout<<"Number of Answer = "<<ans<<endl;

}