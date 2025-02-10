class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        stack<TreeNode *> st;

        TreeNode *curNode = root;

        while (true)
        {
            if (curNode != NULL)
            {
                /*
                    We are here, means the "curNode" is NOT NULL.
                    and thus, there is a possibility of existance of left [and/or] right of this "curNode". (note that I said possibility, NOT guarentee)
                    Posibility 1) if there would be a left, then we would have to print it first, so we cannot print "curNode".
                    Posibility 2) but if left would be NULL then we have to print "curNode".
                    !!!!!!! so what's the soln? !!!!!!!

                    Scenario of Posibility 2) If left is NULL, and we push this curnode in stack and if we go then in next iteration we will go to
                    -- the else condition. then at that time we will know that the node is null and that would be the left of current one and we
                    -- have to print curr and also go to curr right.

                    Scenario of Posibility 1) It says push the "curNode" on top of stack and then make curNode = curNode->left
                    -- This will ensure that curNode is not lost and anyhow when left things will get over means at some time left
                    would be null and at that time we will not come to this condition and move to else condition.

                    // so no matter which possibility it is, we go to left and push this one in stack.
                */

                st.push(curNode);
                curNode = curNode->left;
            }
            else
            {
                if (st.empty())
                {
                    // this actually says that there is NO parent whose left we came into.
                    // which will be the case when root's right is printed and root was already printed cause it's inorder.
                    // so break out of infinite loop.
                    break;
                }
                else
                {
                    /*
                        This can be achieved by 2 means:
                        1) someone was pushed into stack and we came into it's left and now we know that left was actually null.
                        -- in this scenario, we have to print whatever is on top of stack cause left is exhausted and top is root.
                        -- then after printing root we go to the right.

                        2) another thing canbe a case of leaf node in which the left was null and we visited this in just the previous
                        -- iteration and what we did in that iteration was to exhause left, also print root and pop the top, and moved to right
                        -- to that root, BUT right was also and thus we know that we have exhausted left, root, right and still
                        -- we have something on stack's top.
                        -- what could be that thing on top of stack?
                        -- we only push in the curnode!=NULL step means that the top must be some ancestor of ours and we would be the left of that ancestor
                        -- now as we have fully exhausted (left + root + right)
                        -- what about our ancstor?
                        -- it's left was me, which is done.
                        -- now we have to print him and move to it's right.
                        -- which is the exact same step which we would do on the case 1) thing.
                        -- this is not coincidence, but recursion (recursive nature of inorder traversal)

                        // so no matter what reason is but we print top and then go to its right, while popping it.
                    */

                    v.push_back(st.top()->val);
                    curNode = st.top()->right;
                    st.pop();
                }
            }
        }
        return v;
    }
};