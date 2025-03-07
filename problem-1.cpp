// https://leetcode.com/problems/flood-fill/description/
// Time Complexity : BFS - O(n*m), DFS - O(n*m)
// Space Complexity : BFS - O(n*m), DFS - O(n*m)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach
// BFS 
// Initialize a queue and insert the given indeces. From there move in all 4 directions and check if it has the initial color.
// In that case, change the color and push it to the queue.

// DFS
// Starting from the given position, iterate in all 4 directions and mark the color by doing the bounds check.

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int st = image[sr][sc];
            if(st == color) return image;
            int n = image.size();
            int m = image[0].size();
            queue<pair<int,int>> q;
            vector<pair<int,int>> dir = {{0,1}, {0, -1}, {1,0}, {-1,0}};
            q.push({sr,sc});
            image[sr][sc] = color;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : dir){
                    int i = dx + x;
                    int j = dy + y;
                    if(i>=0 && i<n && j>=0 && j<m && image[i][j] == st){
                        image[i][j] = color;
                        q.push({i,j});
                    }
                }
            }
            return image;
    
        }
    };


// DFS

class Solution {
    public:
        void dfs(vector<vector<int>>& image, int sr, int sc, int color, int st, int n, int m, vector<pair<int,int>>& dir){
            if(sr<0 || sr==n || sc<0 || sc==m || image[sr][sc] != st) return;
            image[sr][sc] = color;
            for(auto [dx,dy]:dir){
                int i=dx+sr;
                int j=dy+sc;
                dfs(image, i, j, color, st, n, m, dir);
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int st = image[sr][sc];
            if(st == color) return image;
            int n = image.size();
            int m = image[0].size();
            vector<pair<int,int>> dir = {{0,1}, {0, -1}, {1,0}, {-1,0}};
            dfs(image, sr, sc, color, st, n, m, dir);
            return image;
    
        }
    };