class Solution {
public:
    // vector<bool>prime(1e6+1,true);
    vector<int> closestPrimes(int left, int right) {
        vector<bool>prime(right+1,true);
        vector<int> v;
        for(int i=2;i*i<right+1;i++){
            if(prime[i]){
                // if(i>=left)v.push_back(i);
                for(int j = i*i;j<right+1;j+=i)prime[j]=false;
            }
        }
        for(int i=max(left,2);i<=right;i++)if(prime[i])v.push_back(i);
        if(v.size()<2)return {-1,-1};
        int min_diff = 1e6;
        vector<int>ans;
        for(int i =0;i<v.size()-1;i++){
            if(v[i+1]-v[i]<min_diff){
                min_diff = v[i+1]-v[i];
                ans = {v[i],v[i+1]};
            }
        }
        return ans;
    }
};