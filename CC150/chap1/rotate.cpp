#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix) {
    // do a turn according to the diagonal
    if(matrix.empty()) return;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0; i<row-1; i++) {
        for(int j=0; j<col-1; j++) {
            swap(matrix[i][j], matrix[row-1-j][col-1-i]);
        }
    }
    // do a turn according to the center horizontal
    for(int i=0; i<row/2; i++) {
        for(int j=0; j<col; j++) {
            swap(matrix[i][j], matrix[row-i-1][j]);
        }
    }
}

int main() {
    vector<vector<int> > matrix(2, vector<int>(2, 1) );
    matrix[0][1] = 2; matrix[1][0] = 3; matrix[1][1] = 4;
    rotate(matrix);
    for(auto &v:matrix) {
      for(auto x: v) {
        cout << x << " ";
      }
      cout << endl;
    }
    return 0;
}
