/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> m;
        queue<Node*> q;
        m[node->val] = new Node(node->val);
        q.push(node);
        while(!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            for (auto& nb: cur->neighbors)
            {
                if (m.find(nb->val) == m.end())
                {
                    m[nb->val] = new Node(nb->val);
                    q.push(nb);
                }
                m[cur->val]->neighbors.push_back(m[nb->val]);
            }
        }
        return m[1];
    }
};