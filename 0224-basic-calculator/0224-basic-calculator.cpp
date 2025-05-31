class Solution
{
public:
    int calculate(string s)
    {
        stack<string> st;

        for(auto c : s)
        {
            if(c == ' ') continue;

            if(c == ')')
            {
                vector<string> v;
                while(st.top() != "(")
                {
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();

                reverse(v.begin(), v.end());
                // for(auto e : v) cout << e; cout << endl;

                int sum = 0;
                string op = "+";
                for(auto e : v)
                {
                    if(e == "+" || e == "-") op = e;
                    else {
                        if(op == "+") sum += stoi(e);
                        else sum -= stoi(e);
                    }
                }
                // cout << sum << endl;

                if(sum < 0)
                {
                    if(!st.empty())
                    {
                        if(st.top() == "-")
                        {
                            st.pop();
                            st.push("+");
                            sum *= -1;
                            st.push(to_string(sum));
                        }
                        else
                        {
                            st.pop();
                            sum *= -1;
                            st.push("-");
                            st.push(to_string(sum));
                        }
                    }
                    else
                    {
                        st.push("-");
                        sum *= -1;
                        st.push(to_string(sum));
                    }
                }
                else
                {
                    st.push(to_string(sum));
                }
            }
            else
            {
                if(!st.empty() && c >= '0' && c <= '9')
                {
                    if(st.top() != "(" && st.top() != "+" && st.top() != "-")
                    {
                        string str = st.top();
                        if(!st.empty()) st.pop();
                        str += c;
                        st.push(str);
                    }
                    else
                    {
                        string ctr = "a"; ctr += c;
                        reverse(ctr.begin(), ctr.end());
                        ctr.pop_back();
                        // cout << ctr << endl;
                        st.push(ctr);
                    }
                }
                else
                {
                    string cc = ""; cc += c;
                    // cout << cc << endl;
                    st.push(cc);
                }
            }
        }

        vector<string> v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());
        // cout << " *****" << endl;
        // for(auto e : v) cout << e; cout << endl;

        int sum = 0;
        string op = "+";
        for(auto e : v)
        {
            if(e == "+" || e == "-") op = e;
            else {
                if(op == "+") sum += stoi(e);
                else sum -= stoi(e);
            }
        }
        // cout << sum << endl;

        return sum;
    }
};