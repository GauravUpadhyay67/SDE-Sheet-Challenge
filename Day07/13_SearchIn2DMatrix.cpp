// Problem: Search in a 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Difficulty: Hard
// Approach: Treat matrix as 1D sorted array, apply Binary Search
// Time: O(log(n*m)) | Space: O(1)


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = n * m - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};
