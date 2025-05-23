class Codec
{
public:
    string serialize(TreeNode* root)
    {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curNode = q.front();
            q.pop();

            if(curNode == NULL) s.append("#,");
            else s.append(to_string(curNode->val) + ',');

            if(curNode != NULL)
            {
                // Not checking if left is null or right is null, we need 'em.
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data)
    {
        if(data.empty()) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');

            if(str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if(str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};