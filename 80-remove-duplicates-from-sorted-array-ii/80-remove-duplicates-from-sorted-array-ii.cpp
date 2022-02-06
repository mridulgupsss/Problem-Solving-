class Solution {
public:
int removeDuplicates(vector<int>& arr) {
    int idx = 0;
    for (int val : arr)
        if (idx < 2 || val > arr[idx-2])
            arr[idx++] = val;
    return idx;
}
};