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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *>st;
        ListNode *temp=headA;
        while(temp!=NULL){
            st.insert(temp);
            temp=temp->next;

        }

        ListNode *ans=headB;

        while(ans!=NULL){
            if(st.find(ans)!=st.end())return ans;
            ans=ans->next;
        }

        return NULL;


            }
};