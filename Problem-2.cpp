// https://leetcode.com/problems/01-matrix/
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach
// Visit the matrix and add all the indices where the value is 0 to a queue, and mark all 1 as -1.
// Perform BFS on the given queue and increase the dist for each level.

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            queue<pair<int,int>> q;
            vector<pair<int,int>> dir = {{0,1}, {0, -1}, {1,0}, {-1,0}};
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(mat[i][j] == 0) q.push({i,j});
                    if(mat[i][j] == 1) mat[i][j] = -1;
                }
            }
            int dist=1;
            while(!q.empty()){
                int size = q.size();
                for(int i=0; i<size; i++){
                    auto [x,y] = q.front();
                    q.pop();
                    for(auto [dx,dy]:dir){
                        int i = x+dx;
                        int j = y+dy;
                        if(i>=0 && i<n && j>=0 && j<m && mat[i][j] == -1){
                            q.push({i,j});
                            mat[i][j] = dist;
                        }
                    }
                }
                dist++;
            }
            return mat;
        }
    };