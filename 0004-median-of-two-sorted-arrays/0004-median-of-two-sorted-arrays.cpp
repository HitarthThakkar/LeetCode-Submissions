class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int toTake = (m + n) / 2;

        int lo = 0;
        int hi = min(m, toTake);

        while(lo <= hi)
        {
            int takenFromA = (lo + hi) / 2;
            int takenFromB = toTake - takenFromA;

            if(takenFromB > n)
            {
                lo = takenFromA + 1;
                continue;
            }

            int lastA = (takenFromA > 0 ? nums1[takenFromA - 1] : -1e8);
            int lastB = (takenFromB > 0 ? nums2[takenFromB - 1] : -1e8);

            if(takenFromB < n && lastA > nums2[takenFromB])
            {
                hi = takenFromA - 1;
                continue;
            }

            if(takenFromA < m && lastB > nums1[takenFromA])
            {
                lo = takenFromA + 1;
                continue;
            }

            if((m + n) & 1)
            {
                double result = 1e9;
                if(takenFromB < n) result = min(result, 1.0 * nums2[takenFromB]);
                if(takenFromA < m) result = min(result, 1.0 * nums1[takenFromA]);
                return result;
            }
            else
            {
                double one = -1e8, two = 1e8;
                if(takenFromB > 0) one = max(one, 1.0 * nums2[takenFromB - 1]);
                if(takenFromA > 0) one = max(one, 1.0 * nums1[takenFromA - 1]);
                if(takenFromB < n) two = min(two, 1.0 * nums2[takenFromB]);
                if(takenFromA < m) two = min(two, 1.0 * nums1[takenFromA]);
                return ((one + two) / 2.0);
            }
        }

        return 0;
    }
};