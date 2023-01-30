class Solution {
public:
    const int M = 1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long int>ps(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        // create nse and pse;
        vector<int> nse(n);
        vector<int> pse(n);
        stack<int> temp;
        for(int i=0;i<n;i++){
            while(!temp.empty()&&nums[temp.top()]>=nums[i])temp.pop();
            if(temp.empty())pse[i]=-1;
            else pse[i]=temp.top();
            temp.push(i);
        }
        while(!temp.empty())temp.pop();
        for(int i=n-1;i>=0;i--){
            while(!temp.empty()&&nums[temp.top()]>=nums[i])temp.pop();
            if(temp.empty())nse[i]=n;
            else nse[i]=temp.top();
            temp.push(i);
        }
        long long int max_min_product = 0;
        for(int i=0;i<n;i++){
            max_min_product = max(max_min_product,nums[i]*1ll*(ps[nse[i]-1]-(pse[i]<0?0:ps[pse[i]])));
        }
        return max_min_product%M;
    }
};