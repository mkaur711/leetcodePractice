/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    stack<Node*> s;

    Node* treeToDoublyList(Node* root) {

        if(root == NULL) return root;

        pushNode(root);

        Node* head = new Node(0);
        Node* prev = head;
        Node* current;

        while(!s.empty()){
            current = s.top();
            s.pop();

            pushNode(current->right);

            //head->right point to the first node (in-order traversal) of the tree
            prev->right = current;  
            current->left = prev;
            prev = current;
        }

        head->right->left = current;
        current->right = head->right;

        return head->right;
    }

private:

    void pushNode(Node* node){
        while(node != NULL){
            s.push(node);
            node = node->left;
        }
    }

};