class Solution {
public:
    // int cSum(vector<int>v){
    //     int ans = 0;
    //     for(int i=0;i<v.size();i++)ans+=v[i];
    //     return ans;
    // }
    int t_sum = 0;
    // vector<vector<int>> dp;
    bool solve(vector<int>&nums,int k, vector<int>&op,int i){
        if(i==nums.size()){
            for(int j= 0;j<k;j++){
                if(op[j]!=t_sum/k)return false;
            }
            return true;
        }
        bool ans = false;
        for(int j=0;j<k;j++){
            if(op[j]+nums[i]>t_sum/k){
                continue;
            } 
            op[j]+=nums[i];
            ans = ans || solve(nums,k,op,i+1);
            if(ans)return true;
            op[j]-=nums[i];
            if(op[j]==0)break;
        }
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[&](int a, int b){return a>b;});
        for(int i=0;i<n;i++)t_sum +=nums[i];
        if(t_sum%k)return false;
        vector<int> op(k);
        return solve(nums,k,op,0);
    }
};