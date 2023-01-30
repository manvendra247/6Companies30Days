class Solution {
public:
    int max_size = 0;
    void str(string s, set<string> &st, int i){
        if(i==s.size()){
            max_size = max(max_size,int(st.size()));
            return;
        }
        for(int j=i;j<s.size();j++){
            string temp = s.substr(i,j-i+1);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                str(s,st,j+1);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string>st;
        str(s,st,0);
        return max_size;
    }
};