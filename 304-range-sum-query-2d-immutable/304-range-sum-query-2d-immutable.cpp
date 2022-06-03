class NumMatrix {
public:
    vector<vector<int>> Sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        Sum.resize(n,vector<int>(m));
        Sum[0][0] = matrix[0][0];
        for(int i = 1 ; i <  m ; i++){
            Sum[0][i] = Sum[0][i-1]+matrix[0][i];
        }
        for(int  i = 1 ; i < n ; i++){
            Sum[i][0] = Sum[i-1][0]+matrix[i][0];
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                Sum[i][j] = Sum[i-1][j]+Sum[i][j-1] - Sum[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = Sum[row2][col2];
        int b = 0;
        if(col1 > 0){
            b = Sum[row2][col1-1];
        }
        int c = 0;
        if(row1 > 0){
            c = Sum[row1-1][col2];
        }
        int d = 0;
        if(row1 > 0 and col1 > 0){
            d = Sum[row1-1][col1-1];
        }
        return a - b - c + d;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */