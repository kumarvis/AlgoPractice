#include "common_header.hh"
#include <numeric>


void subsetSumsHelper(vector<int>& nums, int index, vector<int> curr_combination, vector<int> &ans){
    if(index==nums.size()){
        if(curr_combination.size()==0){
            ans.push_back(0);
            return ;
        }
        int sum_of_elems = 0;
        std::for_each(curr_combination.begin(), curr_combination.end(), [&] (int n) {
            sum_of_elems += n;
        });
        ans.push_back(sum_of_elems);
        return;
    }
    curr_combination.push_back(nums[index]);
    subsetSumsHelper(nums, index+1, curr_combination, ans);
    curr_combination.pop_back();
    subsetSumsHelper(nums, index+1, curr_combination, ans);
}

vector<int> subsetSums(vector<int>& nums){
    int index=0;
    vector<int> curr_combination;
    vector<int> ans ; 
    subsetSumsHelper(nums, index, curr_combination, ans);
    return ans ;
}

void test_subsetSums(){
    vector<int> candidates = {2, 3};
    vector<int> ans = subsetSums(candidates);
    for (const int& val : ans) {
            cout << val << " "<<endl;
    }
}