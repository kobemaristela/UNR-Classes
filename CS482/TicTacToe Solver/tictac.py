#!/usr/bin/python3

from cmath import inf
import numpy as np
import argparse

class TicTacToe:
	def __init__(self, board=None, player=1) -> None:
		if board is None:
			self.board = self.init_board()
		else:
			self.board = board

		self.player_one = player
		self.player_two = -1 if player == 1 else 1

		print("\nInitial Board={}\n".format(self.board)) 

	def init_board(self):
		return np.array([[0,0,0],[0,0,0],[0,0,0]])

	def print_board(self):
		print (self.board)
		print()

	def eval_win(self, board) -> np.array:
		""""
		Evaluates winner of current board state (horizontal, vertical, or diagonal win states)

		Parameters:
		board: current board state

		Return: winner of current board state
		"""

		# check diagonal
		if (board[0][0] == board[1][1] == board[2][2] != 0 or 
			board[0][2] == board[1][1] == board[2][0] != 0):
			return board[1][1]

		# check horizontal
		for _, row in enumerate(board):
			if row[0] == row[1] == row[2] != 0:
				return row[0]
				
		# check vertical
		for col, _ in enumerate(board):
			if board[0][col] == board[1][col] == board[2][col] != 0:
				return board[0][col]

		return 0


	def minimax (self, board, depth, is_max, current_player) -> float:
		""""
		Decides on best move based on minmax algorithm

		Parameters:
		current_player: player making the move (1,-1)

		Returns: score of board based on minimax algo
		"""

		# Base case -> no more moves | winner is found | depth reached
		if depth == 0 or self.eval_win(board) != 0 or 0 not in board:
			return self.eval_win(board) - depth if is_max else self.eval_win(board) + depth
			
		moves = np.asarray(np.where(board == 0)).T.tolist() # grab all possible moves
		enemy = -1 if current_player == 1 else 1	# opponent sign

		score = []
		for	move in moves:
			temp_board = np.array(board)
			x, y = move[0], move[1]
			temp_board[x][y] = current_player if is_max else enemy
			score.append(self.minimax(temp_board, depth - 1, not is_max, current_player))	# append minimax score

		return max(score) - depth if is_max else min(score) + depth	# return max/min score based on current state


	def make_move(self, current_player):
		""""
		Decides on best move based on minmax algorithm

		Parameters:
		current_player: player making the move (1,-1)
		"""
		best_score = -np.inf
		best_move = (-1,-1)
		moves = np.asarray(np.where(self.board == 0)).T.tolist()	# grabs all possible moves

		for	move in moves:
			temp_board = np.array(self.board)	# creates a copy of the current board state
			x, y = move[0], move[1]

			temp_board[x][y] = current_player
			score = self.minimax(temp_board, len(moves), False, current_player)	# calls minimax algorithm

			# records score and move
			if score > best_score:
				best_score = score
				best_move = (x,y)
		
		self.board[best_move[0]][best_move[1]] = current_player	# makes the board move


	def play_game(self):
		""""
		Bot players plays with each other depending on designated player one
		"""
		while True:
			# Make Player One move
			self.make_move(self.player_one)
			if self.eval_win(self.board) != 0 or 0 not in self.board:
				break

			# Make Player Two move
			self.make_move(self.player_two)
			if self.eval_win(self.board) != 0 or 0 not in self.board:
				break
			
		return self.board, self.eval_win(self.board)


def load_board( filename ):
	return np.loadtxt( filename)

# def save_board( self, filename ):
# 	np.savetxt( filename, self.board, fmt='%d')

def main():
	parser = argparse.ArgumentParser(description='Play tic tac toe')
	parser.add_argument('-f', '--file', default=None, type=str ,help='load board from file')
	parser.add_argument('-p', '--player', default=1, type=int, choices=[1,-1] ,help='player that playes first, 1 or -1')
	args = parser.parse_args()

	board = load_board(args.file) if args.file else None
	testcase = np.array([[ 0,0,0],
                             [-1,1,0],
                             [-1,0,0]])
	
	ttt = TicTacToe(testcase, args.player)
	ttt.print_board()
	b,p = ttt.play_game()
	print("final board: \n{}".format(b))
	print("winner: player {}".format(p))

if __name__ == '__main__':
	main()