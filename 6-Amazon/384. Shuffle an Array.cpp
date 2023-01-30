class Solution {
public:
    Solution(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            original.push_back(nums[i]);
            shuf.push_back(nums[i]);
        }
    }
    vector<int> original;
    vector<int> shuf;
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        // int r = rand();  // gives you a number from 0 to RAND_MAX
        // double d = r / RAND_MAX;  // gives you a number from 0 to 1
        // double val = d * (original.size()-1); // gives you a number from 0 to 5
        // int result = round(d);  // rounds to an integer
        for(int curr_idx = 0;curr_idx<original.size();curr_idx++){
            int r= rand();
            double d = r*1.0/ RAND_MAX;
            double val = d *(original.size()-curr_idx-1);
            int res = round(val);
            // cout<<r<<" "<<d<<" "<<val<<" "<<res<<endl;
            swap(shuf[curr_idx],shuf[curr_idx + res]);
        }
        
        // int last = shuf.back();
        // for(int i =shuf.size()-1;i>0;i--){
        //     shuf[i]= shuf[i-1];
        // } 
        // shuf[0]= last;
        return shuf;
        // return original(original.begin()+1,original.end()) + original[0];
        
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */