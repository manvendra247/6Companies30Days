class Solution {
public:
    vector<string> ans;
    void solve(string &s,int i, string &op,int c){
        if(c==0){
            long long int num = 0;
            if(i==s.size())return;
            for(int j=i;j<s.size();j++){
                num = num*10 + s[j]-'0';
            }
            if(num>=0&&num<256){
                string n = to_string(num);
                op+=n;
                if(op.size()==s.size()+3)ans.push_back(op);
                int t = n.size();
                while(t--)op.pop_back();
            }
            return ;
        }
        long long int num = 0;
        for(int j=i;j<s.size();j++){
            num = num*10 +s[j]-'0';
            if(num>=0&&num<256&&c){
                string n = to_string(num);
                op+=n;
                op.push_back('.');
                solve(s,j+1,op,c-1);
                op.pop_back();
                int t = n.size();
                while(t--)op.pop_back();
            }else return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string op= "";
        solve(s,0,op,3);
        return ans;
    }
};