class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int m = version1.length();
        int n = version2.length();
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            string one = "";
            string two = "";
            while(i < m && version1[i] != '.') one += version1[i], i++;
            i++;
            while(j < n && version2[j] != '.') two += version2[j], j++;
            j++;
            int onee = (one == "" ? 0 : stoi(one));
            int twoo = (two == "" ? 0 : stoi(two));
            if(onee > twoo) return 1;
            else if(onee < twoo) return -1;
        }
        while(i < m)
        {
            string one = "";
            string two = "";
            while(i < m && version1[i] != '.') one += version1[i], i++;
            i++;
            int onee = (one == "" ? 0 : stoi(one));
            int twoo = (two == "" ? 0 : stoi(two));
            if(onee > twoo) return 1;
            else if(onee < twoo) return -1;
        }
        while(j < n)
        {
            string one = "";
            string two = "";
            while(j < n && version2[j] != '.') two += version2[j], j++;
            j++;
            int onee = (one == "" ? 0 : stoi(one));
            int twoo = (two == "" ? 0 : stoi(two));
            if(onee > twoo) return 1;
            else if(onee < twoo) return -1;
        }
        return 0;
    }
};