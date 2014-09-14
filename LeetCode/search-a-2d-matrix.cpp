class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            if (matrix.empty()) return false;
            int m = matrix.size();
            int n = matrix[0].size();
            int start = 0, end = m*n;
            while (start < end) {
                int mid = start + (end - start)/2;
                int row = mid / n;
                int col = mid - n*row;
                if (matrix[row][col] == target) return true;
                else if (matrix[row][col] < target) start = mid + 1;
                else end = mid;
            }
            return false;
        }
};
