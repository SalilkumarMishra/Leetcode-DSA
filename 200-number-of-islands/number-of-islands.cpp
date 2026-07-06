class Solution {
public:
    int m,n;
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&visited)
    {
        visited[i][j]=1;
        queue<pair<int,int>>q;//index of marked 1
        q.push({i,j});
        int drx[4]={-1,0,1,0};
        int dry[4]={0,1,0,-1};
        while(!q.empty())
        {
            int dx=q.front().first;
            int dy=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int dirx=dx+drx[i];
                int diry=dy+dry[i];
                if(dirx>=0 && diry>=0 && diry<n && dirx<m && visited[dirx][diry]==0 && grid[dirx][diry]=='1')
                {
                    visited[dirx][diry]=1;
                    q.push({dirx,diry});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};