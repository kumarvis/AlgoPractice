#include<string>
#include "common_header.hh"

//vector<string> ans ;


void generateParenthesisHelper(int n, int no_open, int no_close, string str, vector<string> & ans) {
    if(no_open+no_close==2*n && no_open==no_close){
        ans.push_back(str);
        return;
    }
    if(no_close > no_open)
        return ;
    if(no_open > n)
        return ;
    if (no_open==0){
        str = str + "(";
        no_open++;
    }

    str = str + "(";
    //no_open++;
    generateParenthesisHelper(n, no_open+1, no_close, str, ans);
    str.pop_back();
    str = str + ")";
    //no_close++;
    generateParenthesisHelper(n, no_open, no_close+1, str, ans);

}

vector<string> generateParenthesis(int n) {
    int no_open = 0 ;
    int no_close = 0 ;
    string str = "";
    vector<string>  ans;
    generateParenthesisHelper(n, no_open, no_close, str, ans);
    return ans ;
}

void test_generateParenthesis(){
    int n = 3 ;
    vector<string> ans = generateParenthesis(n) ;
    for (string str : ans)
        cout<<"item = "<<str<<endl;
}