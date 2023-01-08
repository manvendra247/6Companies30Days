class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total_sum =0;
        int product = 0;
        for(int i = 0;i<nums.size();i++){
            total_sum +=nums[i];
            product+= i*nums[i];
        }
        int max_val = product;
        int n = nums.size();
        for(int i=nums.size()-1;i>=0;i--){
            product += total_sum - n*nums[i];
            max_val = max(max_val , product);
        }
        return max_val;
    }
}; 