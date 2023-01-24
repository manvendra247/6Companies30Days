class Solution {
public:
    pair<double,double> makeLine(vector<vector<int>>&points, int i, int j){
        double m ;
        if(points[j][0]==points[i][0])m = DBL_MAX;
        else m = ((points[j][1]-points[i][1])*1.000000000/(points[j][0]-points[i][0]));
        double c;
        if(m==DBL_MAX)c = points[i][0];
        else c = points[i][1]- m*1.0*points[i][0];
        return {m,c};
    }
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        map<pair<double,double>,set<pair<int,int>>> mp;
        int cnt = 1;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                auto line = makeLine(points,i,j);
                mp[line].insert({points[i][0],points[i][1]});
                mp[line].insert({points[j][0],points[j][1]});
                cnt = max(cnt, int(mp[line].size()));
            }
        }
        return cnt;
    }
};