class Solution {
public:
   string removeDuplicateLetters(string s) {
    int count[26] = {0};
    bool visited[26] = {0};
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']--;
        if (visited[s[i] - 'a']) continue;
        while (!res.empty() && s[i] < res.back() && count[res.back() - 'a'] > 0) {
            visited[res.back() - 'a'] = 0;
            res.pop_back();
        }
        visited[s[i] - 'a'] = 1;
        res += s[i];
    }
    return res;
}
};