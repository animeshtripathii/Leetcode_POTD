1class Solution {
2public:
3    int pairSum(ListNode* head) {
4        ListNode* slow = head;
5        ListNode* fast = head;
6        
7        while (fast != nullptr && fast->next != nullptr) {
8            slow = slow->next;
9            fast = fast->next->next;
10        }
11        
12        ListNode* prev = nullptr;
13        ListNode* curr = slow;
14        while (curr != nullptr) {
15            ListNode* nextNode = curr->next;
16            curr->next = prev;
17            prev = curr;
18            curr = nextNode;
19        }
20        
21        int max_sum = 0;
22        ListNode* first_half = head;
23        ListNode* second_half = prev;
24        
25        while (second_half != nullptr) {
26            int current_pair_sum = first_half->val + second_half->val;
27            max_sum = max(max_sum, current_pair_sum);
28            
29            first_half = first_half->next;
30            second_half = second_half->next;
31        }
32        
33        return max_sum;
34    }
35};