class Solution {
public:
    // josephus problem recursion . 
    
    void remove(vector<int> &arr, int i){
        for(int j = i;j<arr.size()-1;j++){
            arr[j]= arr[j+1];
        }
        arr.pop_back();
    }
    int recursion(vector<int> &arr,int i, int n, int k){
        if(arr.size()==1)return arr[0];
        // cout<<i<<" "<< arr[(i+k)%arr.size()] <<endl;
        remove(arr, (i+k)%(arr.size()) );
        return recursion(arr, (i + k)%(arr.size()+1) , n -1, k);
    }
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i =0;i<n;i++){
            arr.push_back(i+1);
        }
        k--;
        return recursion(arr,0, n, k);
        
    }
};