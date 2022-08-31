int dx[] = {1,0,-1,0};
int dy[] = {0, 1, 0, -1};

class Solution {
  public:
    int n, m;
  vector < vector < int >> pReach, aReach, grid;

  bool check(int r, int c) {
    if (r >= 0 && r < n && c >= 0 && c < m) {
      return 1;
    }
    return 0;
  }
// dfs for pacific ocean 
  void pdfs(int r, int c) {
    pReach[r][c] = 1;
    for (int i = 0; i < 4; i++) {
      int cr = r + dx[i], cc = c + dy[i];
      if (check(cr, cc)) {
        if (grid[cr][cc] >= grid[r][c] && !pReach[cr][cc])
          pdfs(cr, cc);
      }
    }
  }
// dfs for atlantic ocean 
  void adfs(int r, int c) {
    aReach[r][c] = 1;
    for (int i = 0; i < 4; i++) {
      int cr = r + dx[i], cc = c + dy[i];
      if (check(cr, cc)) {
        if (grid[cr][cc] >= grid[r][c] && !aReach[cr][cc])
          adfs(cr, cc);
      }
    }
  }

  vector < vector < int >> pacificAtlantic(vector < vector < int >> & heights) {
    // setting up global variables from input given
    grid = heights;
    n = heights.size();
    m = heights[0].size();
    // setting up visited grid
    pReach.resize(n);
    aReach.resize(n);
    for (int i = 0; i < n; i++) {
      pReach[i].resize(m);
      aReach[i].resize(m);
      for (int j = 0; j < m; j++) {
        pReach[i][j] = 0;
        aReach[i][j] = 0;
      }
    }
    // traversing from ends of pacific ocean to all islands.. 
    for (int j = 0; j < m; j++) {
      if (pReach[0][j] == 0) {
        pdfs(0, j);
      }
    }
    for (int i = 0; i < n; i++) {
      if (!pReach[i][0]) {
        pdfs(i, 0);
      }
    }
    // traversing from ends of atlantic ocean to all islands.. 
    
    for (int j = 0; j < m; j++) {
      if (!aReach[n - 1][j]) {
        adfs(n - 1, j);
      }
    }
    
    for (int i = 0; i < n; i++) {
      if (!aReach[i][m - 1]) {
        adfs(i, m - 1);
      }
    }
    
    vector < vector < int >> ans;
    vector < int > temp;

    //Normal check as described in logic
     for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (aReach[i][j] && pReach[i][j]) {
          temp.clear();
          temp.push_back(i);
          temp.push_back(j);
          ans.push_back(temp);
        }
      }
    }

    return ans;
  }
};