class Solution {
private:
    void DFS(vector<vector<int>>& grid,int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1){
            return;
        }
        
        grid[i][j]=-1;
        
        DFS(grid,i+1,j);
        DFS(grid, i-1,j);
        DFS(grid,i,j+1);
        DFS(grid,i,j-1);
        
    }  
    
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       
       for(int i=0; i<m; i++){
           DFS(grid,0,i);
           DFS(grid,n-1,i);
       } 
       
       for(int j=0; j<n; j++){
           DFS(grid,j,0);
           DFS(grid,j,m-1);
       }
       
       int count = 0;
       
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(grid[i][j]==1){
                   count++;
               }
           }
       }
       return count;
    }
};