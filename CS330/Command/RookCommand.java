
public class RookCommand implements Command {
	private Board myBoard;
	private int lastX, lastY;
	private int newX, newY;
	private char piece;

	public RookCommand(Board board) {
		this.myBoard = board;
	}

	public void move(int x, int y, int newX, int newY) {
		char pos = this.myBoard.getPiece(x, y);
		if (pos != 'r' && pos != 'R') {
			System.out.println("Wrong Piece");
			return;
		}
		
		if(!(newY == y ^ newX == x)) {
			System.out.println("Invalid Move");
			return;
		}
		
		lastX = x;
		lastY = y;
		this.newX = newX;
		this.newY = newY;
		piece = pos;
		
		myBoard.setPiece(' ', x, y);
		myBoard.setPiece(pos, newX, newY);
		
		System.out.println(String.format("Rook moved to %c%d", ((char)'a' + newX), newY));
	}

	public void undo() {
		System.out.println(String.format("UNDO: Rook back to %c%d", ((char)'a' + lastX), lastY));
		myBoard.setPiece(piece, lastX, lastY);
		myBoard.setPiece(' ', newX, newY);
	}
}
