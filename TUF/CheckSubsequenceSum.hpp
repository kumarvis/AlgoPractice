#include "common_header.hh"

#define EFFICIENT 1

#ifndef EFFICIENT
int sum_arr(vector<int> vec_arr){
    int sum = 0 ; 
    for(int x: vec_arr){
        sum = sum+x;
    }
    return sum ;
}

void checkSubsequenceSumHelper(vector<int>& nums, int k, vector<int> sub_arr, int index, bool &ans) {
    int curr_sum = sum_arr(sub_arr);
    if(curr_sum > k){
        return ;
    }
    
    if(index >=nums.size()){
        if(curr_sum == k)
            ans = true;
        return ;
    }
    sub_arr.push_back(nums[index]);
    checkSubsequenceSumHelper(nums, k, sub_arr, index+1, ans);
    sub_arr.pop_back();
    checkSubsequenceSumHelper(nums, k, sub_arr, index+1, ans);

}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    bool ans = false;
    vector<int> sub_arr;
    int index=0;
    checkSubsequenceSumHelper(nums, k, sub_arr, index, ans);
    return ans ;
}
#endif

bool checkSubsequenceSumHelper(vector<int> &nums, int index, int sum){
    if(sum==0)
        return true ;
    if(sum < 0 || index==nums.size())
        return false; 
    
    bool p1 = checkSubsequenceSumHelper(nums, index+1, sum-nums[index]);
    bool p2 = checkSubsequenceSumHelper(nums, index+1, sum);
    return p1 | p2 ;
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    int index = 0 ;
    bool ans = checkSubsequenceSumHelper(nums, index, k);
    return ans ; 
}

void test_checkSubsequenceSum(){
    vector<int> nums = {4, 3, 9, 2};
    int k = 10;
    bool ans = checkSubsequenceSum(nums, k);
    if(ans)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;    

}