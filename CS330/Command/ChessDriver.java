
public class ChessDriver {

	public static void main(String[] args) {
		Player p1 = new Player();
		
		
		// Pawn Test
		System.out.println("\n-----TESTING PAWN-----");
		p1.myBoard.setPiece('p', 3, 3); // Set Pawn on board
		
		p1.movePawn(3, 3, 3, 4); // Correct Move
		p1.undo();				 // Undo Move
		p1.movePawn(3, 3, 3, 1); // Incorrect Move
		
		// Bishop Test
		System.out.println("\n-----TESTING BISHOP-----");
		p1.myBoard.setPiece('b', 3, 3); // Set Bishop on board
		
		p1.moveBishop(3, 3, 4, 4); // Correct Move
		p1.undo();				 // Undo Move
		p1.moveBishop(3, 3, 3, 1); // Incorrect Move
		
		// Rook Test
		System.out.println("\n-----TESTING ROOK-----");
		p1.myBoard.setPiece('r', 3, 3); // Set Rook on board
		
		p1.moveRook(3, 3, 3, 6); // Correct Move
		p1.undo();				 // Undo Move
		p1.moveRook(3, 3, 2, 1); // Incorrect Move
		
		// Knight Test
		System.out.println("\n-----TESTING KNIGHT-----");
		p1.myBoard.setPiece('k', 3, 3); // Set Knight on board
		
		p1.moveKnight(3, 3, 2, 5); // Correct Move
		p1.undo();				 // Undo Move
		p1.moveKnight(3, 3, 0, 0); // Incorrect Move
		
		// Queen Test
		System.out.println("\n-----TESTING QUEEN-----");
		p1.myBoard.setPiece('q', 3, 3); // Set Queen on board
		
		p1.moveQueen(3, 3, 3, 0); // Correct Move
		p1.undo();				 // Undo Move
		p1.moveQueen(3, 3, 0, 4); // Incorrect Move
		
		// King Test
		System.out.println("\n-----TESTING KING-----");
		p1.myBoard.setPiece('k', 3, 3); // Set King on board
		
		p1.moveKing(3, 3, 4, 3); // Correct Move
		p1.undo();				 // Undo Move
		p1.moveKing(3, 3, 3, 1); // Incorrect Move
		
	}

}
