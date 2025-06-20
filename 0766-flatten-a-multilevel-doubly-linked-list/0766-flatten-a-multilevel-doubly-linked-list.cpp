class Solution
{
public:
    Node* resolveChildIssues(Node* node)
    {
        if(!node->child) return node;
        Node* flattenedBoy = flatten(node->child);
        node->next = flattenedBoy;
        flattenedBoy->prev = node;
        node->child = NULL;
        while(node->next != NULL) node = node->next;
        return node;
    }

    Node* flatten(Node* head)
    {
        Node* cur = head;
        while(cur)
        {
            Node* nxt = cur->next;
            Node* lastNode = resolveChildIssues(cur);
            lastNode->next = nxt;
            if(nxt) nxt->prev = lastNode;
            cur = nxt;
        }
        return head;
    }
};