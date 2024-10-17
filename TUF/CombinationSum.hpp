#include "common_header.hh"


void combinationSumHelper(vector<int>& candidates, int target, int index, vector<int> sub_arr, vector<vector<int>> & ans){
    if(target==0){
        ans.push_back(sub_arr);
        return ;
    }
    if(target < 0 || index == candidates.size())
        return;
    sub_arr.push_back(candidates[index]);
    combinationSumHelper(candidates, target-candidates[index], index, sub_arr, ans);
    sub_arr.pop_back();
    combinationSumHelper(candidates, target, index+1, sub_arr, ans);
} 

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans ; 
    vector<int> sub_arr ; 
    int index = 0 ; 
    combinationSumHelper(candidates, target, index, sub_arr, ans);
    return ans ; 
}

void test_combinationSum(){
    vector<int> candidates = {2, 3, 5, 4};
    vector<vector<int>> ans ; 
    int target = 7;
    ans = combinationSum(candidates, target) ;
    printVVector(ans) ;  
}