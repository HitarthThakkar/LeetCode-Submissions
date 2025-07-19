class Solution
{
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        sort(folder.begin(), folder.end());
        unordered_set<string> past;
        vector<string> res;

        for(auto path : folder) {
            int notTake = false;
            string str = "";
            for(int i = 0; i < path.length(); i++) {
                if(i > 0 && path[i] == '/' && past.find(str) != past.end()) notTake = true;
                str += path[i];
            }
            past.insert(path);
            if(!notTake) res.push_back(path);
        }
        return res;
    }
};