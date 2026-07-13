class Solution {
public:
    vector<int> parent, rank;

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            swap(rootX, rootY);

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY])
            rank[rootX]++;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;

        }
        for(auto x:edges){
            unite(x[0],x[1]);
        }
        return find(source) ==find(destination);

    }
};