class BSTIterator {
public:
    stack<TreeNode*> st;

    void leftPush(TreeNode* node) {
        st.push(node);
        while(node->left) {
            st.push(node->left);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        leftPush(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        if(node->right) leftPush(node->right);
        return (node->val);
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};