#include "common_header.hh"
#include <numeric>

void subsetSumsHelper(vector<int>& nums, int index, vector<int> curr_combination, vector<vector<int> > &ans){
    if(index==nums.size()){
        ans.push_back(curr_combination);
        return ;
    }
    curr_combination.push_back(nums[index]);
    subsetSumsHelper(nums, index+1, curr_combination, ans);
    curr_combination.pop_back();
    bool is_called = false;
    for(int i = index + 1; i < nums.size(); i++) {
        if(nums[i] != nums[index]) {
            is_called = true ;
            subsetSumsHelper(nums, i, curr_combination, ans);
            break;
        }
    }
    if(!is_called)
        subsetSumsHelper(nums, nums.size(), curr_combination, ans);
}

vector<vector<int> > subsetsWithDup(vector<int>& nums){
    int index=0;
    vector<int> curr_combination;
    vector<vector<int> > ans ;
    sort(nums.begin(), nums.end());
    subsetSumsHelper(nums, index, curr_combination, ans);
    return ans ;
}

void test_subsetsWithDup(){
    vector<int> candidates = {1, 2, 2};
    vector<vector<int> > ans = subsetsWithDup(candidates);
    printVVector(ans);
}