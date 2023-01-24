class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        sort(barcodes.begin(),barcodes.end());
        int same =1;
        for(int i=0;i<barcodes.size()-1;i++){
            if(barcodes[i]==barcodes[i+1])same++;
            else{
                pq.push({same,barcodes[i]});
                same = 1;
            }
        }
        pq.push({same,barcodes.back()});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            if(!ans.empty()&&ans.back()==temp.second){
                auto temp2 = pq.top();
                pq.pop();
                ans.push_back(temp2.second);
                if(temp2.first-1>0)pq.push({temp2.first-1,temp2.second});
                pq.push(temp);
            }
            else{
                ans.push_back(temp.second);
                if(temp.first-1>0)pq.push({temp.first-1,temp.second});
            }
        }
        return ans;
    }
};