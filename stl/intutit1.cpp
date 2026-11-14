#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int operations_count = 0;


int dfs(int u, int p, int h, const vector<vector<int>>& adj) {
    int max_subtree_height = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        
        int child_height = dfs(v, u, h, adj);
        
     
        if (child_height + 1 > h) {
            operations_count++;
        } else {
        
            max_subtree_height = max(max_subtree_height, child_height + 1);
        }
    }
    return max_subtree_height;
}

bool isPossible(int h, int max_ops, int n, const vector<vector<int>>& adj) {
   
    if (h == 0) return n <= 1;
    
    operations_count = 0;
    
    dfs(1, -1, h, adj);
    
    return operations_count <= max_ops;
}

int getMinimumHeight(int tree_nodes, vector<int> tree_from, vector<int> tree_to, int max_operations) {
    vector<vector<int>> adj(tree_nodes + 1);
    for (int i = 0; i < tree_from.size(); i++) {
        adj[tree_from[i]].push_back(tree_to[i]);
        adj[tree_to[i]].push_back(tree_from[i]);
    }

    int low = 1, high = tree_nodes;
    int ans = tree_nodes;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, max_operations, tree_nodes, adj)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
  
    int nodes = 4;
    vector<int> from = {3,1,2};
    vector<int> to = {2,3,4}; 
    int max_ops = 2;

    cout << "Minimum Height: " << getMinimumHeight(nodes, from, to, max_ops) << endl;

    return 0;
}