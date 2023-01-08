class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int> pre(nums.size(),-1);
        vector<int> count(nums.size(),1);
        int max=0,index =-1;
        for(int i= 0;i<nums.size();i++){
            for(int j= i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(count[i]<1+count[j]){
                        count[i]=count[j]+1;
                        pre[i]=j;
                    }
                }
            }
            if(count[i]>max){
                max = count[i];
                index =i;
            }
        }
        while(index!=-1){
            ans.push_back(nums[index]);
            index = pre[index];
        }
        return ans;
    }
};