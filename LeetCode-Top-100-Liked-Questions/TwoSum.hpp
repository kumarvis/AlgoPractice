#include "common_header.hh"
using namespace std ;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans ; 
        unordered_set<int> num_set;
        for(int ii=0 ; ii < nums.size() ; ii++){
            int xx = target - nums[ii] ;
            if (num_set.find(xx) != num_set.end()) {
                int key = xx;
                vector<int>::iterator itr = find(nums.begin(), nums.end(), key);
                int index = std::distance(nums.begin(), itr);
                int min_index = min(ii, index);
                int max_index = max(ii, index);
                ans.push_back(min_index);
                ans.push_back(max_index);
                return ans ;
            }else {
                num_set.insert(nums[ii]);
            }
        }
        return ans ;
    }

void test_twoSum(){
    vector<int> vec_arr = { 2, 7, 11, 15};
    int target = 9;
    vector<int> vec_val = twoSum(vec_arr, target);
    cout<<"Output"<<endl;
    for (auto item : vec_val) {
        cout<<"Element "<<item<<" "<<endl;
    }

}