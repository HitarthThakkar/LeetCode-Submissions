class Solution {
public:

    bool isCouponValid(string code, string business, bool active)
    {
        if(!active || code.length() == 0) return false;

        if(business == "electronics" || business == "grocery" ||
            business == "pharmacy" || business == "restaurant")
        {
            for(auto c : code)
            {
                if(('a' <= c  && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || (c == '_'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }

            return true;
        }

        return false;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>> list;
        int n = code.size();
        
        for(int i = 0; i < n; i++)
        {
            if(isCouponValid(code[i], businessLine[i], isActive[i]))
            {
                list.push_back({businessLine[i], code[i]});
            }
        }

        sort(list.begin(), list.end());

        vector<string> res;

        for(auto e : list)
        {
            res.push_back(e.second);
        }

        return res;
    }
};