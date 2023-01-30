class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0,j=0;
        int n= fruits.size();
        map<int,int>mp;
        int distinct = 0;
        int maximum=0;
        while(j<n){
            if(distinct<=2){
                if(mp.find(fruits[j])==mp.end())distinct++;
                mp[fruits[j]]++;
                if(distinct<3)maximum = max(j-i+1,maximum);
            }
            while(distinct>2){
                if(mp[fruits[i]]==1)distinct--;
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                i++;
            }j++;
        }
        return maximum;
    }
};