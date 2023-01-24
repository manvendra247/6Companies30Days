class Solution {
public:
    int dist(vector<vector<int>>& points,int i , int j){
        int x = points[j][0]-points[i][0];
        int y = points[j][1]-points[i][1];
        return x*x + y*y;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3)return 0;
        unordered_map<int,unordered_map<int,int>>mp;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                mp[i][dist(points,i,j)]++;
            }
        }
        for(auto boom : mp){
            for(auto el : boom.second){
                count += (el.second-1)*el.second;
            }
        }
        return count;
    }
};