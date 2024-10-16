#include "common_header.hh"

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
    if(curr_sum == k){
        ans = true;
        return;
    }
    if(index >=nums.size()){
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
}

void test_checkSubsequenceSum(){
    vector<int> nums = {1, 2, 3};
    int k = 8;
    checkSubsequenceSum(nums, k);

}