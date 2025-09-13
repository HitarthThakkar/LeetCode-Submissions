class Solution
{
public:

    void recur(Node* node)
    {
        if(!node || !node->left || !node->right) return;
        if(node->left) node->left->next = node->right;
        if(node->next) node->right->next = node->next->left;
        if(node->left) recur(node->left);
        if(node->right) recur(node->right);
    }

    Node* connect(Node* root)
    {
        recur(root);
        return root;
    }
};