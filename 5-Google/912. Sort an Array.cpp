class Solution {
public:
    // heap sort
    void heapify(vector<int>&nums,int i,int j){
        int c1 = 2*j+1;
        int c2 = 2*j+2;
        if(c2>i)return;
        if(c2==i){
            if(nums[j]<nums[c1])swap(nums[j],nums[c1]);
            return;
        }else{
            if(nums[c1]>nums[j]&&nums[c1]>=nums[c2]){
                swap(nums[c1],nums[j]);
                heapify(nums,i,c1);
            }else if(nums[c2]>nums[j]&&nums[c2]>nums[c1]){
                swap(nums[c2],nums[j]);
                heapify(nums,i,c2);
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        make_heap(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums;
    }
};