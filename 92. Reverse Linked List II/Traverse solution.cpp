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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n || !head)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* preNode = dummy;
        ListNode* currNode = head;
        ListNode* temp, *firstNode, *secondNode;

        int cnt = 1;
        while(cnt<m){
            preNode = currNode;
            currNode = currNode->next;
            ++cnt;
        }
        firstNode = preNode;
        secondNode = currNode;

        preNode = currNode;
        currNode = currNode->next;

        while(cnt<n){
            temp = currNode->next;
            currNode->next = preNode;
            preNode = currNode;
            currNode = temp;
            ++cnt;
        }
        firstNode->next = preNode;
        secondNode->next = temp;
        return dummy->next;
    }
};
