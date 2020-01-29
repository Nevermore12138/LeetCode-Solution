/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * minusNode = new ListNode(-1);
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pri_q(cmp);
        int lenth = 0;
        vector<ListNode*> headBuff;
        unordered_map<ListNode*, int> hashRec;
        for(int i=0; i<lists.size(); ++i){
            ListNode* temp = lists[i];
            headBuff.push_back(temp);
            if(temp){
                hashRec[temp] = i;
                pri_q.push(temp);
                while(temp){
                    ++lenth;
                    temp = temp->next;
                }
            }
        }
        ListNode* p = minusNode;
        for(int j=0; j<lenth; ++j){
            p->next = pri_q.top();
            int insertLabel = hashRec[pri_q.top()];
            hashRec.erase(headBuff[insertLabel]);
            headBuff[insertLabel] = headBuff[insertLabel]->next;
            hashRec[headBuff[insertLabel]]=insertLabel;
            pri_q.pop();
            if(headBuff[insertLabel])
                pri_q.push(headBuff[insertLabel]);
            p = p->next;   
        }
        return minusNode->next;
    }
};
