class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // ===== 1. Find middle =====
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ===== 2. Reverse second half =====
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        slow->next = nullptr;

        while (curr != nullptr) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        // prev = head of reversed second half

        // ===== 3. Merge =====
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};