#include "common_header.hh"
using namespace std ;

int searchInsert(vector<int>& nums, int target) {
    if (nums.empty())
        return 0 ;
    int start_idx = 0 ;
    int end_idx = nums.size() - 1;  
    int mid_idx = 0;
    while(start_idx <= end_idx) {
        mid_idx = start_idx + ((end_idx - start_idx) / 2) ;
        if (nums[mid_idx]==target)
            return mid_idx;
        else {
            if (nums[mid_idx] > target){
                end_idx = mid_idx - 1;
            }else{
                start_idx = mid_idx + 1 ;
            }
        }
    }
    if(start_idx > end_idx )
        return end_idx + 1 ;
    return mid_idx;
}

void test_searchInsert(){
    vector<int> vec_arr = {1, 3, 5, 6};
    int target = 7;
    int ans = searchInsert(vec_arr, target);
    cout<<"Inser Index = "<<ans<<endl;
}