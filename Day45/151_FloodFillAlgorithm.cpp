// Problem: Flood Fill Algorithm
// Link: https://leetcode.com/problems/flood-fill/
// Difficulty: Medium
// Approach: BFS — Start from the given pixel and recolor all connected cells having the same original color.
// Time: O(m*n) | Space: O(m*n)

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size()
        int n = image[0].size();
        int originalColor = image[sr][sc];

        if(originalColor == color) return image;
            
        queue<pair<int,int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        vector<pair<int,int>> dir = {
            {0,-1},
            {0,1},
            {-1,0},
            {1,0}
        };

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc]: dir){
                int row = r + dr;
                int col = c + dc;

                if(row >= 0 && row < m &&
                   col >= 0 && col < n &&
                   image[row][col] == originalColor){
                    image[row][col] = color;
                    q.push({row, col});
                }
            }
        }

        return image;
    }
};
