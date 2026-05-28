1struct TrieNode {
2    TrieNode* next[26];
3    int min_sz=INT_MAX; 
4    int best_i=-1;      
5};
6static constexpr int N=500003; 
7static TrieNode pool[N];
8static int ptr=0;   
9struct Trie {
10    TrieNode* root;
11
12    TrieNode* newNode() {
13        TrieNode* node=&pool[ptr++];
14        memset(node->next, 0, sizeof(node->next));
15        node->min_sz=INT_MAX;
16        node->best_i=-1;
17        return node;
18    }
19
20    Trie() {
21        ptr=0; 
22        root=newNode();
23    }
24
25    void insert(const string& w, int idx) {
26        int wz=w.size();
27        TrieNode* curr=root;
28        if (wz<curr->min_sz) {
29            curr->min_sz=wz;
30            curr->best_i=idx;
31        }
32        for (int i=wz-1; i>=0; i--) {
33            int c = w[i]-'a';
34            if (curr->next[c]==NULL) 
35                curr->next[c]=newNode();
36            curr=curr->next[c];
37
38            if (wz<curr->min_sz) {
39                curr->min_sz=wz;
40                curr->best_i=idx;
41            }
42        }
43    }
44
45    int find(const string& q) {
46        TrieNode* curr = root;
47        int best=root->best_i;
48        for (int i=q.size()-1; i>=0; i--) {
49            int c=q[i]-'a';
50            if (curr->next[c]==NULL) 
51                break; 
52            curr=curr->next[c];
53            best=curr->best_i;
54        }
55        return best;
56    }
57};
58
59class Solution {
60public:
61    static vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& pagesQuery) {
62        Trie trie;
63        int i=0;
64        for (auto& w : wordsContainer) 
65            trie.insert(w, i++);
66
67        vector<int> ans(pagesQuery.size());
68        i=0;
69        for (auto& q : pagesQuery) 
70            ans[i++]=trie.find(q);
71        
72        return ans;
73    }
74};
75
76auto init=[](){
77    ios::sync_with_stdio(0);
78    cin.tie(0);
79    cout.tie(0);
80    return 'c';
81}();