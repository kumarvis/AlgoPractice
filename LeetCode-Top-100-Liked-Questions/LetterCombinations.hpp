#include "common_header.hh"

// Mapping for digit to corresponding letters (e.g., 2 -> "abc", 3 -> "def", etc.)
vector<string> codes = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> getLetterCombinations(const string &digits, int idx) {
    if (idx == digits.length()) {
        return {""};
    }
    
    vector<string> myResult;
    vector<string> recResult = getLetterCombinations(digits, idx + 1);
    char ch = digits[idx];
    string code = codes[ch - '0'];

    for (const string &recString : recResult) {
        for (char chCode : code) {
            myResult.push_back(chCode + recString);  // Combine current char with results
        }
    }

    return myResult;
}

void test_letterCombinations(){
    string digits = "23";
    vector<string> combinations = getLetterCombinations(digits, 0);
    
    // Print the combinations
    for (const string &comb : combinations) {
        cout << comb << " ";
    }
    cout<<endl;
}