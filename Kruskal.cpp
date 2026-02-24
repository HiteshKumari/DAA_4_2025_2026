class Solution {
  public:
    int findp(int x , vector<int> &p){
        if(p[x]==x) return x;
        return p[x]=findp(p[x],p);
    }
    int kruskalsMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),
        [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });
        vector<int> parent(V);
        for(int i=0;i<V;i++) parent[i]=i;
        int sum=0;
        for(auto &e : edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            int pu=findp(u,parent);
            int pv=findp(v,parent);
            if(pu!=pv){
                sum+=w;
                parent[pu]=pv;
            }
        }
        
        
        return sum;
    }
};