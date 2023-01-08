class Solution {
public:
    vector<vector<int>>ans;
    void solve(int n , int i , int k, int sum,vector<int>&v){
        if(sum==n&&k==0){
            ans.push_back(v);
            return ;
        }
        if(i>9||k<0)return;
        for(int j=i;j<10;j++){
            if(sum+j>n)return;
            v.push_back(j);
            solve(n,j+1,k-1,sum+j,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(n,1,k,0,v);
        return ans;
    }
}; 