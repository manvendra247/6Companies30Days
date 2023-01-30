class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        long long int max_views = 0;
        map<string,pair<string,vector<long long int>>>mp;
        for(int i =0;i<n;i++){
            if(mp.find(creators[i])==mp.end()){
                mp[creators[i]]={ids[i],{views[i],views[i]}};
            }else{
                int h = mp[creators[i]].second[1];
                if(h==views[i]){
                    mp[creators[i]].first = min(ids[i],mp[creators[i]].first);

                }
                else if(h<views[i]){
                    mp[creators[i]].second[1]= views[i];
                    mp[creators[i]].first = ids[i];
                }
                mp[creators[i]].second[0] +=views[i];
            }
                max_views  = max(max_views,mp[creators[i]].second[0]);
        }
        vector<vector<string>> ans;
        for(auto el:mp){
            if(el.second.second[0]==max_views){
                ans.push_back({el.first,el.second.first});
            }
        }
        return ans;
    }
};