class Solution {
public:
    string longestPrefix(string s) {
        vector<int> hash(s.size(),0);
        int i=1;
        int prev = 0;
        while(i<s.size()){
            if(s[i]==s[prev]){
                hash[i]= prev+1;
                prev++;
                i++;
            }else{
                if(prev)prev = hash[prev-1];
                else i++;
            }
        }
        return s.substr(0,hash[s.size()-1]);
    }
};