#ifndef LEETCODE100_COMMON_HEADER_HH // If MY_HEADER_H is not defined
#define LEETCODE100_COMMON_HEADER_HH // Define MY_HEADER_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& vec){
    for (const int& val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

void printVVector(const vector<vector<int>>& vec) {
    for (const auto& row : vec) {
        for (const int& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

#endif // LEETCODE100_COMMON_HEADER_HH