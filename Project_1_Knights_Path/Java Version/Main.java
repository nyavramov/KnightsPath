class KnightsPath{
	
	//----------------------------------------------------------------------//
	//Chessboard columns are x-values & rows are y-values
	int chessboard[][] = new int[][]{
		
		//--- x-axis ----
		{0,0,0,0,0,0,0,0}, //|
		{0,0,0,0,0,0,0,0}, //|
		{0,0,0,0,0,0,0,0}, //|
		{0,0,0,0,0,0,0,0}, //|
		{0,0,0,0,0,0,0,0}, //| y-axis
		{0,0,0,0,0,0,0,0}, //|
		{0,0,0,0,0,0,0,0}, //|
		{0,0,0,0,0,0,0,0}, //|
		
	};
	
    //Every move the Knight can make
	int possibleMoves[][] = new int[][]{
		{ 1 ,  2}, { 1 , -2}, {-1 ,  2}, {-1 , -2},
		{ 2 ,  1}, { 2 , -1}, {-2 ,  1}, {-2 , -1}
	};
	
	//Current # of squares filled on chessboard
	int pathCounter = 1;
	
	//Starts the recursive search
	void giddyUp(){
		
		//Start Knight at bottom-left corner of chessboard
		int initialPosX = 7;
	    int initialPosY = 0;
	    
	    moveKnight(initialPosX, initialPosY, 1);
		
	}
	
	//----------------------------------------------------------------------//
    //Checks whether Knight's next move is valid
	boolean validMove(int xPos, int yPos){
		
		//Checks if next move is out of bounds
		if((xPos < 0 || xPos > 7) || (yPos < 0 || yPos > 7)){
			
			return false;
		
		//Checks if next move lands on occupied space	
		} else if (chessboard[xPos][yPos] > 0 && chessboard[xPos][yPos] < 65){
			
			return false;
			
		//If next move's space is unoccupied & in-bounds returns true	
		} else {
			
			return true;
			
		}
		
	}
	
	//----------------------------------------------------------------------//
    //Recursive, returns true if calling itself for next move is true
    //Backtracks if all moves at current position are invalid
	boolean moveKnight(int xPos, int yPos, int pathCounter){

		//If all squares are visited, we are done
		if(pathCounter == 64){
			
			printBoard();
			
			System.exit(0);
			
		}
		
		//Tries each move at current position
		for(int move = 0; move <= 7; move++){
			
			//x-coordinate of our next move
			int movX = possibleMoves[move][0] + xPos;
			
			//y-coordinate of our next move
			int movY = possibleMoves[move][1] + yPos;
			
			//Recursive, checks next move
			if(validMove(movX, movY) == true){
				
				chessboard[movX][movY] = pathCounter;
				
				//Recursive, checks next move
				if(moveKnight(movX, movY, pathCounter + 1) == true){
					
					return true;
					
				} else {
					
					//Backtracks if Knight's next move is unsuccessful
					chessboard[movX][movY] = 0;
					
				}
				
			}
			
		}
		
		return false;
		
	}
	
	//----------------------------------------------------------------------//
	void printBoard(){
		
		for(int j = 0; j <= 7; j++){
			
			for(int i = 0; i <= 7; i++){
				
				//Straightens columns of chessboard out. Looks nicer.
				if(String.valueOf(chessboard[i][j]+1).length() == 1){
					
					System.out.print(chessboard[i][j]+1 + "  ");
					
				} else {
					
					System.out.print(chessboard[i][j]+1 + " ");
					
				}
				
			}
			
			System.out.print("\n");
			
		}
		
	}
	
}

class Main{
	
	public static void main(String[] args){
		
		KnightsPath Knight = new KnightsPath();
		
		Knight.giddyUp();

	}
	
}