class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.size()<n){
            if(s[i]=='1'){
                char temp = s.back();
                if(temp=='1')s.push_back('2');
                else s.push_back('1');
            }else{
                char temp = s.back();
                if(temp =='1'){
                    s.push_back('2');
                    s.push_back('2');
                }else{
                    s.push_back('1');
                    s.push_back('1');  
                }
            }
            i++;
        }
        while(s.size()>n)s.pop_back();
        int count =0;
        for(auto el:s)if(el=='1')count++;
        return count;
    }
};