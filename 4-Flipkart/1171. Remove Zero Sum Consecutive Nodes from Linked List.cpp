/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findSize(ListNode* itr){
        int curr_size = 0;
        while(itr!=NULL){
            curr_size++;
            itr = itr->next;
        }
        return curr_size;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*itr = head;
        int prev_size = -1;
        int curr_size = findSize(itr);
        while(curr_size!=prev_size){
            prev_size = curr_size;
            itr = head;
            unordered_map<int,ListNode*>mp;
            mp.insert({0,NULL});
            int curr_sum = 0;
            while(itr!=NULL){
                curr_sum+=itr->val;
                if(mp.find(curr_sum)!=mp.end()){
                    if(mp[curr_sum]==NULL)head = itr->next;
                    else mp[curr_sum]->next = itr->next;
                }else{
                    mp[curr_sum]=itr;
                }
                itr=itr->next;
            }
            itr = head;
            curr_size = findSize(itr);
        }
        return head;
    }
};