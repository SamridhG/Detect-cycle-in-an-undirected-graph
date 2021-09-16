class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int prevs,vector<int> &visit,vector<int>adj[])
    {
        visit[node]=1;
        for(auto s:adj[node])
        {
            if(visit[s]!=1)
            {
                if (dfs(s,node,visit,adj)) return true;
            }
            else
            {
                if(s!=prevs)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visit(V,0);
        for(int i=0;i<V;i++)
        {
            if(visit[i]!=1)
            {
                if (dfs(i,-1,visit,adj)) return true;
            }
        }
        return false;
        
    }
};
