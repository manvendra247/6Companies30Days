class Solution {
public:
    bool hasmatch(string&w,string&s){
        int i= s.find(w[0]);
        if(i==-1)return false;
        for(int j=1;j<w.size();j++){
            i=s.find(w[j],i+1);
            if(i==-1)return false;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(auto w:words){
            if(hasmatch(w,s))count++;
        }
        return count;
    }
};