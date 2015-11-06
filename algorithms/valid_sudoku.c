/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * http://sudoku.com.au/TheRules.aspx
 *
 * The Sudoku board could be partially filled, where empty cells 
 * are filled with the character '.'.
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. 
 * Only the filled cells need to be validated.
 *
 * https://leetcode.com/problems/valid-sudoku/
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int i,j;
	char row[9][9] = {{0}};
	char col[9][9] = {{0}};
	char box[9][9] = {{0}};
	int tmp;


	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			if(board[i][j] != '.') {
				tmp = board[i][j] - '0';
				
				if(row[i][tmp] == 1)
					return false;
				else row[i][tmp] = 1;
				
				if(col[j][tmp] == 1)
					return false;
				else col[j][tmp] = 1;

				if(box[i/3+(j/3)*3][tmp] == 1)
					return false;
				else 
					box[i/3+(j/3)*3][tmp] = 1;
			}
		}
	}

	return true;
}

int main(int argc, char **argv)
{
	bool valid = false;
	char *board[9] = {
		".87654321",
		"2........",
		"3........",
		"4........",
		"5........",
		"6........",
		"7........",
		"8........",
		"9........"
	};


	valid = isValidSudoku(board, 9,9);
	printf("is board valid?%d\n", valid);

	return 0;

}
