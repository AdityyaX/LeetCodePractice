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
            return NULL;
        unordered_map<Node*, Node*> mpp;
        queue<Node*> q;
        mpp[node] = new Node(node->val, {});
        q.push(node);
        while (!q.empty()) {
            Node* firstNode = q.front();
            q.pop();
            for (auto neighbor : firstNode->neighbors) {
                if (mpp.find(neighbor) == mpp.end()) {
                    Node* secondNode = new Node(neighbor->val, {});
                    mpp[neighbor] = secondNode;
                    q.push(neighbor);
                }
                mpp[firstNode]->neighbors.push_back(mpp[neighbor]);
            }
        }
        return mpp[node];
    }
};