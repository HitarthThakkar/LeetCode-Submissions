class Solution
{
private:
    long long sumSubarrayMaxs(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> pseq(n, -1), nseq(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] < arr[i])
            {
                pseq[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] <= arr[i])
            {
                nseq[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        long long answer = 0;
        for(int i = 0; i < n; i++)
        {
            long long l = i - (pseq[i] + 1);
            long long r = (nseq[i] - 1) - i;
            long long contribution = 0;
            if(l >= 0 && r >= 0)
            {
                contribution++;
                contribution += l;
                contribution += r;
                contribution += (l * r);
            }
            answer += (1LL * contribution * arr[i]);
        }
        return answer;
    }
    long long sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> pseq(n, -1), nseq(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                pseq[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                nseq[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        long long answer = 0;
        for(int i = 0; i < n; i++)
        {
            long long l = i - (pseq[i] + 1);
            long long r = (nseq[i] - 1) - i;
            long long contribution = 0;
            if(l >= 0 && r >= 0)
            {
                contribution++;
                contribution += l;
                contribution += r;
                contribution += (l * r);
            }
            answer += (1LL * contribution * arr[i]);
        }
        return answer;
    }
public:
    long long subArrayRanges(vector<int>& nums)
    {
        long long minssum = sumSubarrayMins(nums);
        long long maxssum = sumSubarrayMaxs(nums);
        return (maxssum - minssum);
    }
};