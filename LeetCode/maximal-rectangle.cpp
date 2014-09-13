class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> H(col, 0), R(col, col), L(col, 0);
        
        for (int i = 0; i < row; ++i) {
            int left = 0, right = col;
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    L[j] = max(L[j], left);
                    H[j] += 1;
                } else {
                    H[j] = L[j] = 0;
                    R[j] = col;
                    left = j + 1;
                }
            }
            for (int j = col-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    // rectangle with (i,j)
                    res = max(res, H[j]*(R[j]-L[j]));
                } else {
                    right = j;
                }
            }
        }
        return res;
    }
};