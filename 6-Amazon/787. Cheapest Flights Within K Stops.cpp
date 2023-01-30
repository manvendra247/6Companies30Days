class Solution {
public:
    vector<set<pair<int,int>>>v;
    vector<vector<int>>vis;
    vector<vector<int>>dp;
    int reach(int k,int vertex,int dst){
        if(k<0)return 1e9;
        if(vis[vertex][k]!=-1)return dp[vertex][k];
        if(vertex==dst)return 0;
        int min_val = 1e9;
        vis[vertex][k]=1;
        for(auto el:v[vertex]){
            min_val = min(min_val,(reach(k-1,el.second,dst) + el.first));
        }
        dp[vertex][k]=min_val;
        return dp[vertex][k];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        v.resize(n);
        vis.resize(n,vector<int>(k+2,-1));
        dp.resize(n,vector<int> (k+2,1e9));
        for(int i=0;i<flights.size();i++){
            v[flights[i][0]].insert({flights[i][2],flights[i][1]});
        }
        int ans = reach(k+1,src,dst);
        if(ans==1e9)return -1;
        return ans;
    }
};