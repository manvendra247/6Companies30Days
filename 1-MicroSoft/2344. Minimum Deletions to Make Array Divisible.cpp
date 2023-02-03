class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // find hcf of numsdivide 
        // sort nums
        // if hcf%nums[i]==0 return i ;
        int hcf = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            hcf = gcd(hcf,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(hcf%nums[i]==0)return i;
        }
        return -1;
    }
};