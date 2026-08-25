class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=1;i<=numRows;i++){
            int res=1;
            vector<int> row;
            row.push_back(1);
            for(int j=1;j<i;j++){
                res=res*(i-j);
                res=res/j;
                row.push_back(res);
            }
            ans.push_back(row);
        }
        return ans;
    }
};