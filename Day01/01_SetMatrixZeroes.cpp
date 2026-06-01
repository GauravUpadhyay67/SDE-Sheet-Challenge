// Problem: Set Matrix Zeroes
// Link: https://leetcode.com/problems/set-matrix-zeroes/
// Difficulty: Medium
// Approach: O(1) space - using first row & col as markers
// Time: O(n*m) | Space: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int firstCol = matrix[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0 && j == 0) {
                    firstCol = 0;
                    matrix[i][j] = 0;
                } else if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = n - 1; i > 0; i--) {
            for (int j = m - 1; j > 0; j--) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = m - 1; j > 0; j--) {
            if (matrix[0][0] == 0) {
                matrix[0][j] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (firstCol == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};
