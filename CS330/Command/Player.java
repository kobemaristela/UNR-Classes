
public class Player {
	private Command myCommand;
	public Board myBoard;
	
	public Player() {
		char[][] board = new char[8][8];
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board[i][j] = ' ';
			}
		}
		
		myBoard = new Board(board);
	}

	
	public void movePawn(int x, int y, int tempX, int tempY) {
		Command command = new PawnCommand(myBoard);
		myCommand = command;
		command.move(x,y,tempX,tempY);
	}
	
	public void moveRook(int x, int y, int tempX, int tempY) {
		Command command = new RookCommand(myBoard);
		myCommand = command;
		command.move(x,y,tempX,tempY);
	}
	
	public void moveKnight(int x, int y, int tempX, int tempY) {
		Command command = new KnightCommand(myBoard);
		myCommand = command;
		command.move(x,y,tempX,tempY);
	}
	
	public void moveQueen(int x, int y, int tempX, int tempY) {
		Command command = new QueenCommand(myBoard);
		myCommand = command;
		command.move(x,y,tempX,tempY);
	}
	
	public void moveKing(int x, int y, int tempX, int tempY) {
		Command command = new KingCommand(myBoard);
		myCommand = command;
		command.move(x,y,tempX,tempY);
	}
	
	public void moveBishop(int x, int y, int tempX, int tempY) {
		Command command = new BishopCommand(myBoard);
		myCommand = command;
		command.move(x,y,tempX,tempY);
	}
	
	public void undo() {
		myCommand.undo();
	}
	
}
