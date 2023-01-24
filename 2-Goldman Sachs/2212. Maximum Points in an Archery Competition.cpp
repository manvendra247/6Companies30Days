class Solution {
public:
    int max_score = 0;
    vector<int>ans;
    void solve(vector<int>& aliceArrows, vector<int>&op, int i, int score,int num){
        if(i==0){
            if(score>max_score){
                max_score = score;
                for(int j=0;j<12;j++)ans[j]=op[j];
                ans[0]=num;
            }
            return;
        }
        solve(aliceArrows,op,i-1,score,num);
        if(num>aliceArrows[i]){
            op[i]=aliceArrows[i]+1;
            solve(aliceArrows,op,i-1,score+i,num-op[i]);
            op[i]= 0;
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>op(12,0);
        ans.resize(12,0);
        solve(aliceArrows,op,11,0,numArrows);
        return ans;
    }
};