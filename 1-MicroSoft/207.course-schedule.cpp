class Solution {
public:
    vector<int> vis;
    vector<int> path;
    bool dfs(vector<vector<int>>&v,int parent){
        if(vis[parent]!=-1)return false;
        if(path[parent]!=-1)return true;
        path[parent] =1;
        bool ans = false;
        for(auto child:v[parent]){
            ans = ans || dfs(v,child);
        }
        vis[parent] = 1;
        path[parent]=-1;
        return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vis.resize(numCourses, -1);
        path.resize(numCourses,-1);
        bool ans = false;
        for(int i =0;i<numCourses;i++){
            ans = ans ||dfs(v,i);
            if(ans)return false;
        }
        return true;
    }
}; 