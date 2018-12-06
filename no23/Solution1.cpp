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
        int len = lists.size();
        if(len == 0)
            return NULL;
        return merge(lists,0,len - 1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int low, int hight) {
        if(low == hight)
            return lists[low];
        ListNode* left = merge(lists,low,(low + hight)/2);
        ListNode* right = merge(lists,(low + hight)/2 + 1, hight);
        ListNode* p = left;
        ListNode* q = right;
        ListNode* result = new ListNode(0);
        ListNode* r = result;
        while(p && q) {
            if(p->val <= q->val) {
                r->next = p;
                p = p->next;
            } else {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }
        while(p) {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        while(q) {
            r->next = q;
            q = q->next;
            r = r->next;
        }
        r->next = NULL;
        return result->next;
    }
};
