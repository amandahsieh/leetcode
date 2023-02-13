/*--------------------------Author: Hsin-Yu Hsieh--------------------------*/
/*First  Trial: Check(null/carry), (a||b)       T:68 22.28%   M:71.5 53.37%*/
/*Second Trial: Check(null/carry), (a&&b a b)   T:46 54.70%   M:71.5 53.39%*/
/*Third  Trial: Check(null/carry)               T:19 99.44%   M:71   92.95%*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);
        ListNode* head = l1;
        ListNode* pre = NULL;
        int carry=0, tmp;
        while(l1&&l2){
            tmp = l1->val+l2->val+carry;
            l1->val = tmp%10;
            carry = tmp/10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(carry && l1){
            tmp = l1->val + carry;
            carry = tmp/10;
            l1->val = tmp%10;
            pre = l1;
            l1 = l1->next;
        }
        while(l2){
            tmp = l2->val + carry;
            pre->next = new ListNode(tmp%10);
            carry = tmp/10;
            pre = pre->next;
            l2 = l2->next;
        }
        if(carry)   pre->next = new ListNode(carry);
        return head;
    }
};

/*
First Trial: 
void add(ListNode* ans, ListNode* a, ListNode* b){
    while (a || b){
        int n=0;
        if (a && b){
            ans->val += (a->val + b->val);
            a = a->next;
            b = b->next;
        }
        else if (a){
            ans->val += (a->val);
            a = a->next;
        }
        else{
            ans -> val += b->val;
            b = b->next;
        }
        if (ans->val >9){
            ans->val -= 10;
            n=1;
        }
        if (n==0 && !a && !b)   return;
        ListNode* r = new ListNode;
        r->val = n;
        ans->next = r;
        ans = ans->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode;
        add(tmp, l1, l2);
        return tmp;
    }
};
*/

/*
Second Trial:
void add(ListNode* ans, ListNode* a, ListNode* b){
    int n=0;
    while (a&&b){
        ListNode* r = new ListNode;
        r->val = (ans->val + a->val + b->val)/10;
        ans->val = (ans->val + a->val + b->val)%10;
        a = a->next;
        b = b->next;
        if((!a&&!b)&&!r->val) break;
        ans->next = r;
        ans = ans->next;
    }
    while (a){
        ListNode* r = new ListNode;
        r->val = (ans->val + a->val)/10;
        ans->val = (ans->val + a->val)%10;
        a = a->next;
        if(!a&&!r->val) break;
        ans->next = r;
        ans = ans->next;
    }
    while (b){
        ListNode* r = new ListNode;
        r->val = (ans->val + b->val)/10;
        ans->val = (ans->val + b->val)%10;
        b = b->next;
        if(!b && !r->val)   break;
        ans->next = r;
        ans = ans->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode;
        add(tmp, l1, l2);
        return tmp;
    }
};
*/