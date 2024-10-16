#include "common_header.hh"

void powerSetHelper(vector<int>& nums, int index, vector<int> tmp_ans, vector<vector<int> > &ans){
    if(index >= nums.size()){
        ans.push_back(tmp_ans);
        return ;
    }
        
    tmp_ans.push_back(nums[index]);
    powerSetHelper(nums, index+1, tmp_ans, ans);
    tmp_ans.pop_back();
    powerSetHelper(nums, index+1, tmp_ans, ans);

}

vector<vector<int> > powerSet(vector<int>& nums) {
    vector<vector<int> > ans ;
    vector<int> tmp_ans ;
    int index=0;
    powerSetHelper(nums, index, tmp_ans, ans);
    return ans ;
}

void printVVector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (const int& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test_powerSet(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int> > ans = powerSet(nums);
    cout<<"NUmber of sets = "<<ans.size()<<endl;
    printVVector(ans);
}