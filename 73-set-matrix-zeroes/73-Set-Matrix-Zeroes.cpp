class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();

        // this a optimal soln in case of TC as O(n*n) and better iin case of SC as O(n)+O(m);
        // can we optimise its space
        // vector <int> col(m,0);
        // vector<int> row(n,0);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0){
        //             col[j]=1;
        //             row[i]=1;
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(col[j]==1 || row[i]==1){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }
        

        // Optimal soln
        // vector <int> col(m,0);  -> matrix[0][..]
        // vector<int> row(n,0);  ->  matrix[..][0]
// mRKER
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else col0=0;
                }
            }
        }
// ITERATE 
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // for remaining 
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++) matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<n;i++) matrix[i][0]=0;
        }
    }
};