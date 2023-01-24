class Solution {
public:
    const int M = 1e9 +7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long int count = 0;
        map<int,long long int>mp;
        mp[1]=1;
        for(int i=2;i<=n;i++){
            for(auto el:mp){
                if(el.first+forget<=i){
                    mp.erase(el.first);
                }else if(i>=el.first+ delay){
                    mp[i]+=(el.second)%M;
                }
            }
        }
        for(auto el:mp)count=(count +el.second)%M;
        return count;
    }
};