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


class Compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap based on node value
    }
};
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;

        // Initialize the min-heap with the head of each list
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        // Merge the lists
        while (!minHeap.empty()) {
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            current->next = smallestNode; // Attach the smallest node
            current = current->next; // Move the pointer forward

            if (smallestNode->next) {
                minHeap.push(smallestNode->next); // Push the next node into the heap
            }
        }

        return dummy.next; // Return the merged linked list
    }
};