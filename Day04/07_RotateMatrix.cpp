// Problem: Rotate Image (Rotate Matrix by 90 degrees)
// Link: https://leetcode.com/problems/rotate-image/
// Difficulty: Medium
// Approach: Transpose the matrix, then reverse each row
// Time: O(n²) | Space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};
