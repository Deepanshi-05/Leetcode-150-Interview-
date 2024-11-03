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
        if (!node) return nullptr;

        // Map to store cloned nodes
        std::unordered_map<Node*, Node*> clonedNodes;
        // Queue for BFS
        std::queue<Node*> q;

        // Clone the root node and add it to the map and queue
        Node* cloneRoot = new Node(node->val);
        clonedNodes[node] = cloneRoot;
        q.push(node);

        // BFS traversal
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Iterate over each neighbor
            for (Node* neighbor : curr->neighbors) {
                // If neighbor is not cloned, clone it and add to queue
                if (clonedNodes.find(neighbor) == clonedNodes.end()) {
                    clonedNodes[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Connect cloned current node with cloned neighbor
                clonedNodes[curr]->neighbors.push_back(clonedNodes[neighbor]);
            }
        }

        return cloneRoot;
    }
};