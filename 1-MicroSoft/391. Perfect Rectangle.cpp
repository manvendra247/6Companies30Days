class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long int total_area =0;
        long long int bigger_area= 0;
        set<vector<int>>mp;
        int corners = 0;
        int x1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        int y1 = INT_MAX;
        for(int i=0;i<rectangles.size();i++){
            total_area += (rectangles[i][2]-rectangles[i][0])*1ll*(rectangles[i][3]-rectangles[i][1]);
            
            x1 = min(x1,rectangles[i][0]);
            y1 = min(y1,rectangles[i][1]);
            x2 = max(x2,rectangles[i][2]);
            y2 = max(y2,rectangles[i][3]);
            
            if(mp.find({rectangles[i][0],rectangles[i][1]})==mp.end())mp.insert({rectangles[i][0],rectangles[i][1]});
            else mp.erase({rectangles[i][0],rectangles[i][1]});
            if(mp.find({rectangles[i][0],rectangles[i][3]})==mp.end())mp.insert({rectangles[i][0],rectangles[i][3]});
            else mp.erase({rectangles[i][0],rectangles[i][3]});
            if(mp.find({rectangles[i][2],rectangles[i][1]})==mp.end())mp.insert({rectangles[i][2],rectangles[i][1]});
            else mp.erase({rectangles[i][2],rectangles[i][1]});
            if(mp.find({rectangles[i][2],rectangles[i][3]})==mp.end())mp.insert({rectangles[i][2],rectangles[i][3]});
            else mp.erase({rectangles[i][2],rectangles[i][3]});
        }
        if(mp.find({x1,y1})==mp.end()||mp.find({x1,y2})==mp.end()||mp.find({x2,y1})==mp.end()||mp.find({x2,y2})==mp.end()|| mp.size()!=4)return false;
        bigger_area = (x2-x1)*1ll*(y2-y1);
        if(total_area == bigger_area)return true;
        return false;
    }
};