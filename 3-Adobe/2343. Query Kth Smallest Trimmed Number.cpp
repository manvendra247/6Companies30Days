class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries){
            vector<pair<string,int>>cpy;
            for(auto num:nums){
                string temp="";
                for(int i=num.size()-q[1];i<num.size();i++){
                    temp.push_back(num[i]);
                }
                cpy.push_back({temp,cpy.size()});
            }
            sort(cpy.begin(),cpy.end());
            
            ans.push_back(cpy[q[0]-1].second);
        }
        return ans;
    }
};