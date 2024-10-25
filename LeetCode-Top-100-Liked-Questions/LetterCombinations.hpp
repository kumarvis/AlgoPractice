#include "common_header.hh"

void letterCombinationsHelper(vector< vector<char>> vvec_options, string curr_combination, int index_v=0, int index_vv=0, vector< string > &ans){
    if(index_vv==vvec_options.size()){
        ans.push_back(curr_combination);
        return ;        
    }
    
    vector<char> vec_options = vvec_options[index_vv];
    curr_combination = curr_combination + vec_options[index_v];
    letterCombinationsHelper(vvec_options, curr_combination, index_v, index_vv+1, ans);

}

vector< string > letterCombinations(string digits){
    vector< string >  ans ;
    vector< vector<char>> vec_map { {'0', '0', '0'},
                                    {'0', '0', '0'},
                                    {'a', 'b', 'c'},
                                    {'d', 'e', 'f'},
                                    {'g', 'h', 'i'},
                                    {'j', 'k', 'l'},
                                    {'m', 'n', 'o'},
                                    {'p', 'q', 'r', 's'},
                                    {'p', 'q', 'r', 's'},
                                    {'t', 'u', 'v'},
                                    {'w', 'x', 'y', 'z'},
                                };

    vector< vector<char>> vvec_options;

    for (const auto& digit : digits) {
            int idx = digit - '0';
            vector<char> tmp = vec_map[idx];
            vvec_options.push_back(tmp);
        
    }

    string curr_combination;
    int index_v=0;
    int index_vv=0;
    letterCombinationsHelper(vvec_options, curr_combination, index_v=0, index_vv, ans);
    return ans ; 
}

void test_letterCombinations(){
    string str = "23" ;
    vector<string> ans = letterCombinations(str);
}