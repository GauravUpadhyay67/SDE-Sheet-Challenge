// Problem: Pascal's Triangle
// Link: https://leetcode.com/problems/pascals-triangle/
// Difficulty: Easy
// Approach: Build row by row using previous row
// Time: O(n²) | Space: O(n²)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;

        vector<int>r(1, 1);
        pascal.push_back(r);

        for(int i=1; i<numRows; i++){
            int m = i+1;
            vector<int>row;
            for(int j=0; j<m; j++){
                if(j == 0 || j == m-1){
                    row.push_back(1);
                }
                else{
                    row.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
                }
            }
            pascal.push_back(row);
        }

        return pascal;
    }
};
