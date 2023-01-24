class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> hash(26,0);
        for(int i=0;i<s.size();i++)hash[s[i]-'a']++;
        vector<bool> o(order.size(),false);
        for(int i=0;i<order.size();i++){
            if(hash[order[i]-'a']){
                o[i]= true;
                hash[order[i]-'a']--;
            }
        }
        string ans = "";
        for(int i=0;i<order.size();i++){
            if(o[i]){
                ans+=string(hash[order[i]-'a']+1,order[i]);
                hash[order[i]-'a']=0;
            }
        }
        for(int i = 0;i<26;i++){
            ans+= string(hash[i],i+'a');
        }
        return ans;
    }
};