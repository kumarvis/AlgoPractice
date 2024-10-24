#include "common_header.hh"
#include "algorithm"

int get_jump(vector<int> vec_arr, int index){
    int ans = vec_arr.size();

    for(int ii=index; ii < vec_arr.size() - 1 ; ii++){
        if(vec_arr[ii]!=vec_arr[ii+1]){
            ans = ii+1;
            break;
        }
    }
    return ans - index ;
}

void combinationSum2Helper(vector<int>& candidates, int sum, int index, vector<int> sub_arr, vector<vector<int> > &ans) {
    if(sum==0){
        ans.push_back(sub_arr);
        return ;
    }
    if(sum < 0 || index==candidates.size())
        return ;

    sub_arr.push_back(candidates[index]);
    combinationSum2Helper(candidates, sum-candidates[index], index+1, sub_arr, ans);
    sub_arr.pop_back();
    int jump  = get_jump(candidates, index);
    combinationSum2Helper(candidates, sum, index+jump, sub_arr, ans);
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > ans;
    vector<int> sub_arr;
    int index=0;
    sort(candidates.begin(), candidates.end());
    combinationSum2Helper(candidates, target, index, sub_arr, ans);
    return ans ;
}

void test_combinationSum2Helper(){
    int target = 8 ;
    vector<int> candidates = {2, 1, 2, 7, 6, 1, 5};
    vector<vector<int> > ans ;
    ans = combinationSum2(candidates, target);
    printVVector(ans);
}

