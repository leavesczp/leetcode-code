class Solution {
public:
    int findSubstringInWraproundString(string p) {
        ListNode index[26](-1);
        int count = 0;
        ListNode* temp;
        int psize = p.size();
        for(int i = psize - 1; i >= 0;i--) {
            temp = new ListNode(i);
            temp->next = index[p[i]-97].next;
            index[p[i]-97].next = temp;
        }
        for(int i = 0; i < 26; i++) {
            int max = 0;
            ListNode *r = nullptr;
            ListNode *q = index[i].next;
            for(;q;q = q-> next) {
                if(r && r->val + max > q->val)
                    continue;
                int pos = q->val;
                while(pos + 1 < psize && (p[pos] + 1 -97) % 26 == p[pos + 1] - 97)
                    pos++;
                max = (pos - q->val + 1) > max ? (pos - q->val + 1) : max;
            }
            count+=max;
        }
        return count;
    }
};
