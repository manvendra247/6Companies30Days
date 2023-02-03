class Solution {
public:
    vector<int> path;
    vector<int> depth;
    vector<vector<int>> graph;
    bool dfs1(int vertex,int bob,int parent){
        path.push_back(vertex);
        if(vertex==bob)return true;
        bool a = false;
        for(auto child:graph[vertex]){
            if(child==parent)continue;
            a = a||dfs1(child,bob,vertex);
        }
        if(a)return true;
        path.pop_back();
        return false;
    }
    void dfs2(int vertex,int parent,int d){
        depth[vertex]=d;
        for(auto child :graph[vertex]){
            if(child==parent)continue;
            dfs2(child,vertex,d+1);
        }
    }
    int maxi=INT_MIN;
    void dfs3(int vertex,int parent,int d,vector<int>&amount){
        d+=amount[vertex];
        if(graph[vertex].size()==1&&parent!=-1)maxi=max(maxi,d);
        for(auto child :graph[vertex]){
            if(child==parent)continue;
            dfs3(child,vertex,d,amount);
        }
        d-=amount[vertex];
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        graph.resize(n);
        depth.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1(0,bob,-1);
        dfs2(0,-1,0);
        int i=path.size()-1;
        int d = 0;
        while(i>=0){
            if(depth[path[i]]==d)amount[path[i]]/=2;
            else if(depth[path[i]]>d)amount[path[i]]=0;
            d++;i--;
        }
        dfs3(0,-1,0,amount);
        return maxi;
    }
};