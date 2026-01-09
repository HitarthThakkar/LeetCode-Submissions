class Solution
{
public:

    /*
        this dfs returns a pair of {TreeNode*, int}.
        let's say I call this dfs function on a node named "node-A".
        then the dfs(node-A) = {some_node_B_with_some_special_property, depth-D}
        here 'depth-D' is the depth of the subtree rooted at 'node-A'.
        now this node-B has a special property and it is that;
        node-B is the LCA of the deepest leaves in the subtree rooted at 'node-A'.
        it is not neccesary that node-B = node-A in general.
        however if node-A is a leaf node then node-A = node-B for sure.
    */

    pair<TreeNode*, int> dfs(TreeNode* node)
    {
        if(!node) return {nullptr, 0};

        // here node-A = node's left child
        // and thus
        // left.first = LCA of the deepest leaves in subtree rooted at node->left
        // left.second = depth of the subtree rooted at node->left
        auto left = dfs(node->left);

        // here node-A = node's right child
        // and thus
        // right.first = LCA of the deepest leaves in subtree rooted at node->right
        // right.second = depth of the subtree rooted at node->right
        auto right = dfs(node->right);

        // so basically we got the answers of {LCA, depth} for left child and right child of this 'node'
        // now depending on depths of left and right childs, we calculate answer for this 'node'

        // left is deeper, this means answer would have the same LCA left child had and depth will increase by 1 level
        if(left.second > right.second) return {left.first, left.second + 1};

        // right is deeper, this means answer would have the same LCA right child had and depth will increase by 1 level
        if(right.second > left.second) return {right.first, right.second + 1};

        // both are same depth, means 'node' would be the LCA of both (think perfect binary tree) and depth increase by 1 level
        return {node, left.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        return dfs(root).first;
    }
};