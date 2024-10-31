/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);

        // Case 1: Empty list
        if (head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }

        // Case 2: General case with at least one node in the list
        Node* curr = head;
        while (true) {
            // Find the appropriate position to insert:
            if ((curr->val <= insertVal && insertVal <= curr->next->val) || // Case 2.1: Insert in the middle of the sorted list
                (curr->val > curr->next->val && (insertVal >= curr->val || insertVal <= curr->next->val))) { // Case 2.2: Insert at boundary
                newNode->next = curr->next;
                curr->next = newNode;
                return head;
            }

            // Move to the next node
            curr = curr->next;

            // If we've gone around the whole list, insert at the end
            if (curr == head) break;
        }

        // Case 3: If all elements are the same, insert after any node
        newNode->next = head->next;
        head->next = newNode;
        return head;
    }
};