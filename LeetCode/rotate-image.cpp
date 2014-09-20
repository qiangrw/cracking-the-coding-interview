class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            if (matrix.empty()) return;
            int m = matrix.size();
            for (int i = 0; i < m-1; i++) {
                for (int j = 0; j < m-1-i; j++) {
                    swap(matrix[i][j], matrix[m-1-j][m-1-i]);
                }
            }
            for (int i = 0; i < m/2; i++) {
                for (int j = 0; j < m; j++) {
                    swap(matrix[i][j], matrix[m-1-i][j]);
                }
            }
        }
};
