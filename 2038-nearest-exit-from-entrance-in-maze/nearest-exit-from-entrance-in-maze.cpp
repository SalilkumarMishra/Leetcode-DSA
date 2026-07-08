class Solution {
public:
    int n,m;
    int r[4]={-1,1,0,0};
    int c[4]={0,0,-1,1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        n=maze.size();
        m=maze[0].size();
        queue<pair<int,int>>q;
        int x=e[0];
        int y=e[1];
        q.push({x,y});
        maze[x][y]='+';
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if((i==0 ||j==0 || i==n-1 || j==m-1) && !(i==x && j==y))
                {
                    return level;
                }
                for(int k=0;k<4;k++)
                {
                    int newi=i+r[k];
                    int newj=j+c[k];
                    if(newi>=0 && newi<n && newj>=0 && newj<m && maze[newi][newj]=='.')
                    {
                        maze[newi][newj]='+';
                        q.push({newi,newj});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
