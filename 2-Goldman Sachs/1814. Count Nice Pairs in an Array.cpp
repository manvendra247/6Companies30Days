class Solution {
public:
    const int M = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        long long int count =0;
        int n= nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int rev=0;
            int n1 = nums[i];
            while(n1){
                rev = rev*10 + n1%10;
                n1/=10;
            }
            mp[nums[i]-rev]++;
        }
        for(auto ele: mp){
            count += (ele.second*1ll*(ele.second-1))/2;
        }
        return count%M;
    }
};