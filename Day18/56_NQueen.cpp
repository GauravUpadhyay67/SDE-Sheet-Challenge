// Problem: N Queen
// Link: https://leetcode.com/problems/n-queens/
// Difficulty: Hard
// Approach: Backtracking — place queen col by col, check row & diagonals
// Time: O(n!) | Space: O(n²)


class Solution {
    bool isSafePosition(vector<string>&arr, int i, int j){
       int row = i, col = j;

       while(col >= 0){
        if(arr[row][col] == 'Q') return false;
        col--;
       }

       row = i, col = j;

       while(row >= 0 && col >= 0){
        if(arr[row][col] == 'Q') return false;
        row--;
        col--;
       }

       row = i, col = j;

       while(row < arr.size() && col >= 0){
        if(arr[row][col] == 'Q') return false;
        row++;
        col--;
       }
       return true;
    }

    void solve(int &n, int j, vector<string>&arr, vector<vector<string>>&ans){
        if(j == n){
            ans.push_back(arr);
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafePosition(arr, i, j)){
                arr[i][j] = 'Q';
                solve(n, j+1, arr, ans);
                arr[i][j] = '.';
            }
        }
        
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n, '.');
        vector<string>arr(n);
        vector<vector<string>>ans;

        for(int i=0; i<n; i++){
            arr[i] = str;
        }

        solve(n, 0, arr, ans);
        return ans;
    }
};
