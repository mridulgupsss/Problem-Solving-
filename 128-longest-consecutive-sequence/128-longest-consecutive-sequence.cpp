class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int ele: nums)
        {
            st.insert(ele);
        }
        int len=0;
        for(int ele: nums)
        {
            if(st.find(ele-1)==st.end())
            {
                int potential_len=1;
                    int temp=ele;
                while(st.find(temp+1)!=st.end())
                {
                    temp=temp+1;
                    potential_len++;
                }
                len=max(potential_len, len);
            }
        }
        return len;
    }
};