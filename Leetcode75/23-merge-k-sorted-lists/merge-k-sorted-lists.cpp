/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */#include <vector>
#include <queue>



class Solution {
public:
    // Compare function to be used by priority queue (min-heap)
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // Compare based on value to maintain min-heap property
        }
    };

    // Main function to merge k sorted linked-lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority Queue to get the smallest element from the k lists
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push the first element of each list into the min-heap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode *head = new ListNode(0); // Dummy node to simplify the result list creation
        ListNode *current = head;

        // While there are elements in the min-heap
        while (!minHeap.empty()) {
            // Get the smallest element from the heap
            ListNode* node = minHeap.top();
            minHeap.pop();

            // Add this element to the merged list
            current->next = node;
            current = current->next;

            // If the current list has more elements, push the next one to the heap
            if (node->next) {
                minHeap.push(node->next);
            }
        }

        // Return the merged list, skipping the dummy head node
        return head->next;
    }};