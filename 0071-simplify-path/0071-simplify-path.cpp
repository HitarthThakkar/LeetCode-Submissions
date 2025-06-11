class Solution
{
public:
    string simplifyPath(string path)
    {
        int n = path.length();
        vector<string> vs;
        int i = 0;
        while(i < n) {
            while(i < n && path[i] == '/') i++;
            string cur = "";
            while(i < n && path[i] != '/') cur += path[i++];
            if(cur == ".") continue;
            else if(cur == "..") { if(!vs.empty()) vs.pop_back(); }
            else if(cur.length() > 0) vs.push_back(cur);
        }
        string result;
        for(auto s : vs) {
            result += '/';
            result += s;
        }
        return (result == "" ? "/" : result);
    }
};