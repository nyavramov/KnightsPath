#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <cstdlib>

using namespace std;

//Assignment compiler uses C++ 98, which has no to_string function
//like C++ 11 does
std::string to_string2( const int &x ) {
    int length = snprintf( NULL, 0, "%d", x );
    assert( length >= 0 );
    char* buf = new char[length + 1];
    snprintf( buf, length + 1, "%d", x );
    std::string str( buf );
    delete[] buf;
    return str;
}


class KnightsPath{
    
    public:
    
        //----------------------------------------------------------------------//
        //Every move the Knight can make
        int possibleMoves[8][2] = {
            
            { 1 ,  2}, { 1 , -2}, {-1 ,  2}, {-1 , -2},
            { 2 ,  1}, { 2 , -1}, {-2 ,  1}, {-2 , -1}
            
        };
    
        //Current # of squares filled on chessboard
        int pathCounter = 1;
    
        //----------------------------------------------------------------------//
        //Checks whether Knight's next move is valid
        bool validMove(int (&board)[8][8], int x, int y){
            
            //Checks if next move is out of bounds
            if( (x < 0 || x > 7) || (y < 0 || y > 7)){
                
                return false;

            //Checks if next move lands on occupied space
            } else if (board[x][y] > 0 && board[x][y] < 65){
                
                return false;
            
            //If next move's space is unoccupied & in-bounds returns true
            } else {
                
                return true;
                
            }
        
        }
    
        //----------------------------------------------------------------------//
        //Recursive, returns true if calling itself for next move is true
        //Backtracks if all moves at current position are invalid
        bool moveKnight(int (&board)[8][8], int x, int y, int pathCounter){
            
            //If all squares are visited, we are done
            if(pathCounter == 64){
                
                printBoard(board);
                
                exit(0);
            }
            
            //Tries each move at current position
            for(int move = 0; move <= 7; move++){
                
                //x-coordinate of our next move
                int movX = possibleMoves[move][0] + x;
                
                //y-coordinate of our next move
                int movY = possibleMoves[move][1] + y;
                
                if(validMove(board, movX, movY) == true){
                    
                    board[movX][movY] = pathCounter;
                    
                    //Recursive, checks next move
                    if(moveKnight(board, movX, movY, pathCounter + 1) == true){
                        
                        return true;
                        
                    } else {
                        
                        //Backtracks if Knight's next move is unsuccessful
                        board[movX][movY] = 0;
                        
                    }
                    
                }
                
            }
            
            return false;
        
        }
    
        //----------------------------------------------------------------------//
        void printBoard(int (&board)[8][8]){
        
            for(int i = 0; i < 8; i++){
            
                for(int j = 0; j < 8; j++){
                    
                    //Straightens columns of chessboard out. Looks nicer.
                    if(to_string2(board[j][i]+1).length() == 1){
                   
                        cout << " " <<board[j][i]+1 << "  ";
                        
                    } else {
                        
                        cout << " " << board[j][i]+1 << " ";
                    }
                
                }
                
                cout << endl;
            
            }
        
            cout << endl;
        
        }
        //----------------------------------------------------------------------//
    
};


int main() {
    
    //Chessboard columns are x-values & rows are y-values
    int chessboard[8][8] = {
        
        //--- x-axis ----
        {0,0,0,0,0,0,0,0} , //|
        {0,0,0,0,0,0,0,0} , //|
        {0,0,0,0,0,0,0,0} , //|
        {0,0,0,0,0,0,0,0} , //|
        {0,0,0,0,0,0,0,0} , //| y-axis
        {0,0,0,0,0,0,0,0} , //|
        {0,0,0,0,0,0,0,0} , //|
        {0,0,0,0,0,0,0,0} , //|
        
    };
    
    //Start Knight at bottom-left corner of chessboard
    int initialPosX = 7;
    int initialPosY = 0;
    
    KnightsPath Knight;
    
    Knight.moveKnight(chessboard, initialPosX, initialPosY, 1);
    
    return 0;
}
