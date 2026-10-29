class Solution {
public:

    int r;
    int c;

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};

    bool valid(int i , int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();

        queue<pair<int,int>>q;

        // First Row
        for(int j = 0; j< c;j++)
        {
            if(board[0][j] == 'O')
            {
                q.push(make_pair(0,j));
                board[0][j] = 'T';
            }
        }

        //First column
        for(int i = 1;i < r;i++)
        {
            if(board[i][0] == 'O')
            {
                q.push(make_pair(i,0));
                board[i][0] = 'T';
            }
        }

        //last Row
        for(int j = 1; j < c; j++)
        {
            if(board[r-1][j] == 'O')
            {
                q.push(make_pair(r-1,j));
                board[r-1][j] = 'T';
            }
        }

        //last Column
        for(int i = 1;i < r-1; i++)
        {
            if(board[i][c-1] == 'O')
            {
                q.push(make_pair(i,c-1));
                board[i][c-1] = 'T';
            }
        }

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                if(valid(i+row[k],j+col[k]) && board[i+row[k]][j+col[k]] == 'O')
                {
                    board[i+row[k]][j+col[k]] = 'T';
                    q.push(make_pair(i+row[k],j+col[k]));
                }
            }
        }

        for(int i = 0;i < r; i++)
        {
            for(int j = 0;j < c; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};