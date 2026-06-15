1class Solution {
2public:
3    ListNode* deleteMiddle(ListNode* head) {
4        if (head == NULL || head->next == NULL) {
5            return NULL;
6        }
7        
8        ListNode* slow = head;
9        ListNode* pre = nullptr;
10        ListNode* fast = head;
11
12        while (fast != NULL && fast->next != nullptr) {
13            fast = fast->next->next;
14            pre = slow;
15            slow = slow->next;
16        }
17
18        if (pre != nullptr) {
19            pre->next = slow->next;
20        }
21
22        delete slow;
23        return head;
24    }
25};