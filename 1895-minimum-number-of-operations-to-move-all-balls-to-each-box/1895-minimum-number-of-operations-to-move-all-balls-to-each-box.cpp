class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.length();
        vector<int> pfx(n, 0), sfx(n, 0), ans;
        int otn = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > 0) pfx[i] = otn + pfx[i - 1]; if(boxes[i] == '1') otn++;
        }
        otn = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(i < n - 1) sfx[i] = otn + sfx[i + 1]; if(boxes[i] == '1') otn++;
        }
        for(int i = 0; i < n; i++) ans.push_back(pfx[i] + sfx[i]);
        return ans;
    }
};