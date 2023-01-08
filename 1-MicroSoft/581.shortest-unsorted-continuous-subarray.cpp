class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> cpy;
        for(int i= 0;i<nums.size();i++){
            cpy.push_back(nums[i]);
        }
        sort(cpy.begin(),cpy.end());
        int i=0,j=cpy.size()-1;
            while(i<cpy.size()&&cpy[i]==nums[i])i++;
            while(j>0&&cpy[j]==nums[j])j--;
        return max(0,j-i+1);
    }
};