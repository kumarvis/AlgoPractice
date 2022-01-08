# Two Sum
**Problem Description:**

Given an array of integers ``nums`` and an integer ``target``, return indices of the two numbers such that they add up to target.

You may assume that each input would have ***exactly one solution***, and you may not use the same element twice. You can return the answer in any order.

## Solution01:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> track_map;
        vector<int> ans(2) ; 
        
        for(int ii=0 ; ii < nums.size() ; ii++){
            int key = target-nums[ii];
            if(track_map.find(key) == track_map.end()){
                 track_map[nums[ii]] = ii;
            }else{
                ans[0] = track_map[key] ; 
                ans[1] = ii ;
            }
                
        }
        
        return ans ; 
    }
};

```

## Submission Details Solution01:

|  Status | Accepted  |
|---|---|
| Total Test Case Passed | xx  |
| Runtime | xx ms |
| Memory Usage  | xx MB  |
|  Runtime Percentile |   xx |
|  Memory Usage Percentile |  xx |

## Improvements:

1. It is clearly mentioned in problem statement their is Only ONE solution. We can exit the loop once we find it. 

## Solution02:

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> track_map;
        vector<int> ans(2) ; 
        
        for(int ii=0 ; ii < nums.size() ; ii++){
            int key = target-nums[ii];
            if(track_map.find(key) != track_map.end()){
                ans[0] = track_map[key] ; 
                ans[1] = ii ;
                break;
            }
            track_map[nums[ii]] = ii;
            
                
        }
        
     return ans ;   
    }
};
```

## Submission Details Solution02:

|  Status | Accepted  |
|---|---|
| Total Test Case Passed | xx  |
| Runtime | xx ms |
| Memory Usage  | xx MB  |
|  Runtime Percentile |   xx |
|  Memory Usage Percentile |  xx |