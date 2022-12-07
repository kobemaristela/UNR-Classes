
public class PawnCommand implements Command{
	Board myBoard;
	int tempX, tempY;
	char tempPos;
	
	public PawnCommand(Board board) {
		this.myBoard = board;
	}
	
	public void move(int x, int y, int newX, int newY){
		char pos = myBoard.getPiece(x, y);
		if (pos != 'p' && pos != 'P') {
			System.out.println("Wrong Piece");
			return;
		}
		
		if(newY != y + 1) {
			System.out.println("Invalid Move");
			return;
		}
		
		tempX = x;
		tempY = y;
		tempPos = pos;
		
		myBoard.setPiece(' ', x, y); // Set location empty
		
		y += 1;
		
		System.out.println(String.format("Pawn moved to %c%d", ((char)'a' + x), y));
		myBoard.setPiece(pos, x, y);
	}
	
	
	public void undo() {
		System.out.println(String.format("UNDO: Pawn back to %c%d", ((char)'a' + tempX), tempY));
		myBoard.setPiece(tempPos, tempX, tempY);
		
		tempY =+ 1;
		myBoard.setPiece(' ', tempX, tempY);
		
		tempX = -1;
		tempY = -1;
	}
}
