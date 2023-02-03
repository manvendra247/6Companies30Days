class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3,0);
        int distinct =0;
        int i =0,j=0;
        int count = 0;
        // int d = 0;
        while(j<s.size()){
            if(arr[s[j]-'a']==0)distinct++;
            arr[s[j]-'a']++;
            // if(distinct==3){
                while(distinct==3){
                    arr[s[i]-'a']--;
                    if(arr[s[i]-'a']==0)distinct--;
                    i++; 
                }
                // count+=i+s.size()-j-d;d++;
            // }
            // if(j==s.size())return count;
            j++;
            count+=i;
        }
        return count;
    }
};