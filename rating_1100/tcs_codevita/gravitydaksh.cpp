



pair<int, int> moveUp(int i, int j, vector<vector<int>> &v) 
{ 
    int steps = 0; 
    for (int k = i - 1; k >= 0; k--) 
    { 
        steps++; 
        if (v[k][j] == 2) 
        { 
            i = k; 
            break; 
        } 
    } 
    return {steps, i}; 
}
int solve(vector<vector<int>> &v, int i, int j, int n, int m, int totn, int totm, vector<vector<int>> &vis) 
{ 
    int a = v[i][j]; 
 
    // cout << i << " " << j << endl; 
    if (i == n && j == m) 
        return 0; 
 
    if (i < 0  i >= totn  j < 0  j >= totm  vis[i][j] == 3 || v[i][j] == 1) 
        return 1e9; 
 
    int steps = 0; 
    if (v[i][j] != 2) 
    { 
        for (int k = i + 1; k < totn; k++) 
        { 
            steps++; 
            if (v[k][j] == 2) 
            { 
                i = k; 
                break; 
            } 
        } 
    } 
 
    vis[i][j] = 3; 
    int up = 1e9, left = 1e9, right = 1e9; 
 
    left = 1 + solve(v, i, j - 1, n, m, totn, totm, vis); 
    right = 1 + solve(v, i, j + 1, n, m, totn, totm, vis); 
    if (i - 1 >= 0 && v[i - 1][j] == 1) 
    { 
        auto it = moveUp(i, j, v); 
        up = it.first + solve(v, it.second, j, n, m, totn, totm, vis); 
    } 
 
    vis[i][j] = a; 
    return min(up, min(left, right)) + steps; 
}


