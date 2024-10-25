/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* p_copy=p;
        Node* q_copy=q;
        while(q_copy!=p_copy){
            p_copy =(p_copy==nullptr)?q:p_copy->parent;
                        q_copy =(q_copy==nullptr)?p:q_copy->parent;

        }
        return p_copy;
    }
};