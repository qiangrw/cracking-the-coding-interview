/**
  * Definition for undirected graph.
  * struct UndirectedGraphNode {
  *     int label;
  *     vector<UndirectedGraphNode *> neighbors;
  *     UndirectedGraphNode(int x) : label(x) {};
  * };
  */
class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(node == nullptr) return node;
            unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nmap;
            queue<UndirectedGraphNode*> q;
            q.push(node);
            while (!q.empty()) {
                UndirectedGraphNode *p = q.front();
                q.pop();
                if (nmap.find(p) != nmap.end()) continue;

                nmap[p] = new UndirectedGraphNode(p->label);
                for (auto neighbor: p->neighbors) {
                    if (nmap.find(neighbor) == nmap.end()) q.push(neighbor);
                }
            }
            for (auto it = nmap.begin(); it != nmap.end(); ++it) {
                for (auto neighbor: it->first->neighbors) {
                    nmap[it->first]->neighbors.push_back(nmap[neighbor]);
                }
            }
            return nmap[node];
        }
};
