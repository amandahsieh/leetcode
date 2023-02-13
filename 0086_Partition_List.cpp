/*-----------------------Author: Hsin-Yu Hsieh----------------------*/
/*First Trial: check >= x, add to the tail  T:3 95.90%  M:10.6 5.71%*/

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
void order(ListNode* head, int x){
	vector<int> tail(205, -105);
    int tmp = 0;
	while(head->next && head){
		if(head->next->val>=x){
			tail[tmp++] = head->next->val;
			head->next = head->next->next;
        }
        else    head = head->next;
	}
    for(int i=0; i<tmp; i++){
        ListNode* t = new ListNode;
        t->val = tail[i];
        head->next = t;
        head = head->next;
    }
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode* first = new ListNode;
		first->val = x;
		first->next = head;
        order(first, x);
        return first->next;
    }
};
