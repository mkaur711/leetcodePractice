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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     // Create a dummy node pointing to the head for easier edge case handling
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers, both starting from dummy node
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move `fast` pointer `n+1` steps ahead to maintain a gap of `n` nodes with `slow`
        for (int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }
        
        // Move both `fast` and `slow` pointers until `fast` reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // `slow->next` is the node to be removed; skip it
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free the memory of the removed node

        // Return the modified list starting from `dummy->next`
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node memory
        return newHead;
    }
};