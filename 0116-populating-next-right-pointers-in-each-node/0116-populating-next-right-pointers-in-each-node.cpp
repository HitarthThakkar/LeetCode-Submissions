class Solution
{
public:
    Node* connect(Node* root)   // BEST SOLUTION
    {
        auto head = root;

        for(; root; root = root -> left)    // Top to bottom
        {
            // Left to right for each in top to bottom
            for(auto cur = root; cur; cur = cur -> next)
            {
                if(cur -> left) {
                    cur -> left -> next = cur -> right;
                    if(cur -> next) cur -> right -> next = cur -> next -> left;
                }
                else {
                    break;
                }
            }
        }
        
        return head;
    }
};