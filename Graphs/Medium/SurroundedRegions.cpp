class Solution {
private:
    void DFS(vector<vector<char>>& board,int i, int j){
        int n = board.size();
        int m = board[0].size();
        
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!='O'){
            return;
        }
        
        board[i][j]='S';
        
        DFS(board,i+1,j);
        DFS(board,i-1,j);
        DFS(board,i,j+1);
        DFS(board,i,j-1);
    }
    
    
public:

    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        
        for(int j=0; j<m; j++){
            if(board[0][j]=='O'){
                DFS(board,0,j);
            }
            
            if(board[n-1][j]=='O'){
                DFS(board,n-1,j);
            }
        }
        
        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                DFS(board,i,0);
            } 
            
            if(board[i][m-1]=='O'){
                DFS(board,i,m-1);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='S'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};