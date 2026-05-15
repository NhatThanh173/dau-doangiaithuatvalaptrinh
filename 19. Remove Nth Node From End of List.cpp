class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // fast đi trước n+1 bước
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // cùng di chuyển
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // xóa node
        slow->next = slow->next->next;

        return dummy->next;
    }
};