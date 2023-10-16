#include "common_header.hh"
using namespace std ;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans ;
    vector<int> first_row = {1};
    if(numRows==1)
        vector<int> vec_row = {1};
        ans.push_back(first_row);
        return ans;
    
    ans.push_back(first_row);
    for(int ii=1 ; ii < numRows ; ii++){
        vector<int> prev_row = ans[ii-1];
        vector<int> row ;
        for(int jj=0 ; jj < prev_row.size() ; jj++){
            if(jj==0)
                row.push_back(0+prev_row[jj]);
            else {
                if (jj==numRows-1)
                    row.push_back(prev_row[jj]+0);
                row.push_back(prev_row[jj-1] + prev_row[jj]);            
            }
        }
        ans.push_back(row);
    }
    return ans ;
}

void test_generate(){
    int no_rows = 5 ;
    vector<vector<int>> ans = generate(no_rows);
    for(int ii=0 ; ii < ans.size() ; ii++){
        vector<int> row = ans[ii];
        for(int jj=0 ; jj < row.size() ; jj++)
            cout<<row[jj]<<"\t";
        cout<<endl;
    }

}