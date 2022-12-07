
public class Board {
	char[][] board = new char[8][8];
	
	public Board(char[][] data) {
		this.board = data;
	}
	
	public char getPiece(int x, int y) {
		return this.board[x][y];
	}
	
	public void setPiece(char piece, int x, int y) {
		this.board[x][y] = piece;
	}

}
