class DisjointSet {
private:
    vector<int> size, par;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i] = i;
    }

    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    void merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return;

        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }
    }

    bool connected(int x, int y) {
        return findPar(x) == findPar(y);
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int> (col, 0));
        
        // Mark the cells as flooded (1) based on the input cells array
        for(auto &x: cells) {
            grid[x[0] - 1][x[1] - 1] = 1;
        }   
        
        int dirs[5] = {-1, 0, 1, 0, -1}; // Directions array for easy traversal (up, right, down, left)
        int totalCells = row * col; // Total number of cells in the grid
        int rowStart = totalCells, rowEnd = totalCells + 1; // Virtual cells representing the top and bottom rows
        DisjointSet ds(totalCells + 2); // Create a disjoint-set data structure with totalCells + 2 elements (including virtual cells)

        // Iterate over the grid and establish initial connections between adjacent land cells
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                for(int k=0; k<4; k++) {
                    int ni = i + dirs[k];
                    int nj = j + dirs[k+1];

                    if(ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                        int nodeVal = i*col + j;
                        int nextVal = ni*col + nj;
                        // Merge the current node and the next node (if they are both land cells)
                        ds.merge(nodeVal, nextVal);
                    }
                }
            }
        }

        // Iterate over the flooded cells in reverse order
        for(int c=totalCells-1; c>=0; c--) {
            int i = cells[c][0] - 1;
            int j = cells[c][1] - 1;
            int nodeVal = i*col + j;
            grid[i][j] = 0; // Mark the cell as land (unflooded)

            for(int k=0; k<4; k++) {
                int ni = i + dirs[k];
                int nj = j + dirs[k+1];

                if(ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                    int nodeVal = i*col + j;
                    int nextVal = ni*col + nj;
                    // Merge the current node and the next node (if they are both land cells)
                    ds.merge(nodeVal, nextVal);
                }
            }

            // Merge the current node with the rowStart virtual node if it is in the top row
            if(i == 0)      ds.merge(rowStart, nodeVal); 
            
            // Merge the current node with the rowEnd virtual node if it is in the bottom row
            if(i == row-1)  ds.merge(rowEnd, nodeVal); 

            // Check if the rowStart virtual node and the rowEnd virtual node are connected,
            // indicating a path from top to bottom exists, then return 'c' (current day)            
            if(ds.connected(rowStart, rowEnd))  return c; 

        }
        // No path from top to bottom exists, so return '0' (first Day)
        return 0;
    }
};
