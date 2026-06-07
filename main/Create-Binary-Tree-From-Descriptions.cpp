1class Solution {
2public:
3    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
4        unordered_map<int, TreeNode*> nodes;
5        unordered_set<int> children;
6        
7        for (const auto& desc : descriptions) {
8            int parentVal = desc[0];
9            int childVal = desc[1];
10            int isLeft = desc[2];
11            
12            if (nodes.find(parentVal) == nodes.end()) {
13                nodes[parentVal] = new TreeNode(parentVal);
14            }
15            if (nodes.find(childVal) == nodes.end()) {
16                nodes[childVal] = new TreeNode(childVal);
17            }
18            
19            if (isLeft == 1) {
20                nodes[parentVal]->left = nodes[childVal];
21            } else {
22                nodes[parentVal]->right = nodes[childVal];
23            }
24            
25            children.insert(childVal);
26        }
27        
28        for (const auto& pair : nodes) {
29            if (children.find(pair.first) == children.end()) {
30                return pair.second;
31            }
32        }
33        
34        return nullptr;
35    }
36};