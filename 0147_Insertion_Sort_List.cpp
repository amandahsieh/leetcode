/*-----------------Author: Hsin-Yu Hsieh-----------------*/
/*First Trial: Preserve head   T:8 99.21%    M:9.7 20.88%*/

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
    ListNode* insertionSortList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        //cin.tie(0);
        if(!head || !head->next)    return head;
        ListNode *cur=head->next;
        ListNode *prev=head;
        ListNode *start=new ListNode(INT_MIN);
        ListNode *tmp;
        start->next = head;
        while(cur){
            int v=cur->val;
            if(v<prev->val){
                tmp = start;
                while(tmp->next->val<v) tmp = tmp->next;
                prev->next = prev->next->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = prev->next;
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return start->next;
    }
};