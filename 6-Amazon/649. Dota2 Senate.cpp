class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<int> hash(senate.size(),0);
        int r = 0,d=0;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                r++;
            }
            else{
                d++; 
            } 
        }
        if(r==0)return "Dire";
        if(d==0)return "Radiant";
        while(1){
            for(int i=0;i<senate.size();i++){
                if(hash[i]==0){
                    int j= i;
                    while(senate[j]==senate[i]||hash[j]!=0)j=(j+1)%senate.size();
                    hash[j]=1;
                    if(senate[i]=='R')d--;
                    else r--;
                }
                if(r==0)return "Dire";
                if(d==0) return "Radiant";
            }
        }
        return "";
    }
};