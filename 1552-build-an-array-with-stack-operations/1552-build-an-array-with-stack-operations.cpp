class Solution
{
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> answer;
        unordered_set<int> exists;
        for(auto ele : target) exists.insert(ele);
        for(int i = 1; i <= n; i++)
        {
            answer.push_back("Push");
            if(exists.find(i) == exists.end())
                answer.push_back("Pop");
            if(target.back() == i) return answer;
        }
        return answer;
    }
};