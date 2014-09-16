class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            if(matrix.empty()) return;
            int m = matrix.size();
            int n = matrix[0].size();
            bool col_has_zero = false, row_has_zero = false;
            for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) col_has_zero = true;
            for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) row_has_zero = true;

            // save all zero tags to matrix boarder
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            // set zeros according to the tags
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
                }
            }
            // set corner cases
            if (col_has_zero) for(int i = 0; i < m; ++i) matrix[i][0] = 0;
            if (row_has_zero) for(int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
};
