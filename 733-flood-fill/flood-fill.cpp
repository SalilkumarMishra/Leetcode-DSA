class Solution {
public:
    int n,m;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int row,int col,vector<vector<int>>&ans,int ini,int newcolor,vector<vector<int>>& image)
    {
        ans[row][col]=newcolor;
        for(int i=0;i<4;i++)
        {
            int dr=row+dx[i];
            int dc= col+dy[i];
            if(dr>=0 && dc>=0 && dr<m && dc<n && image[dr][dc]==ini && ans[dr][dc]!=newcolor)
            {
                dfs(dr,dc,ans,ini,newcolor,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        int ini=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(sr,sc,ans,ini,color,image);
        return ans;
    }
};