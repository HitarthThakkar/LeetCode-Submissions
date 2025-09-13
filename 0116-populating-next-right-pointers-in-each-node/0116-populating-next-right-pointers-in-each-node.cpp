class Solution
{
public:
    Node* connect(Node* root)
    {
        queue<Node*> q;
        if(root) q.push(root);

        while(!q.empty()) {
            int size = q.size();
            Node* lastPopped = NULL;

            while(size--) {
                Node* curNode = q.front();
                q.pop();
                if(curNode->left != NULL) q.push(curNode->left);
                if(curNode->right != NULL) q.push(curNode->right);
                if(lastPopped != NULL) lastPopped->next = curNode;
                lastPopped = curNode;
            }
        }

        return root;
    }
};