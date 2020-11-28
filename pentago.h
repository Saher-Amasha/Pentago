/*
 * Pentago.h
 *
 *  Created on: 23 Apr 2020
 *      Author: saher
 */

#ifndef PENTAGO_H_
#define PENTAGO_H_
#include<iostream>
#include <string.h>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;
#define	N 3 //size of board ((length and width))
class Pentago
{
	private:
		char board1[3][3];
		char board2[3][3];
		char board3[3][3];
		char board4[3][3];
		int turnNum;
		char startingPlayer;
	public:
		Pentago();
		//constructor
		//sets turnNUM to zero
		//starting player to white
		//fills board 1 with -
		//fills board 2 with ~
		//fills board 3 with ~
		//fills board 4 with -


		void	DeafultBoard(int BoardNUM);
		//it sets all values in a board to their default

		//for example defaultboard(board1)->		- - -
		//		 									- - -
		//											- - -

		void	play();
		//it starts the game and alternates
		//turns between the players
		//and it stops the game when there is a win draw

		bool 	rotateBoard	 (string input);
		//it takes a string and rotates the board according to that stringg
		//for example rotateboard(1l)
		//rotates board1 to the left


		bool	setValueonBoard(string input,char player);
		//takes a string input   the input is a location on the board
		//and sets the value in that position equal to player


		int		gameOver();
		/*
			checks if one of the players have won or if there is a draw
			and retu2 if white won
			and one if black won
			and 0 if it is a draw!!!!!
		 *
		 */
		bool	isEmpty(int i,int j);

		//returns true if the board is empty at that location([i][j])


		/*
			it takes int i and j -> (0<=i<6)(0<=j<6)
			according to the values i and j it checks at what board
			these values are ,for example (i,j)=(5,5)-> it is in board4[2][2]
			(i,j)=(0,0)-> it is in board1[0][0]
			void	setValueAt(int i,int j,char value);
		*/



		void	printAt(int i,int j);

		//prints board in location [i][j]


		/*
		it takes int i and j -> (0<=i<6)(0<=j<6)
		according to the values i and j it checks at what board
		these values are ,for example (i,j)=(5,5)-> it is in board4[2][2]
		(i,j)=(0,0)-> it is in board1[0][0]
		void	setValueAt(int i,int j,char value);
		*/
		void	printBoards();
		/*
		 * prints the board in this format ->
		 * 	6 - - - ~ ~ ~
			5 - - - ~ ~ ~
			4 - - - ~ ~ ~
			3 ~ ~ ~ - - -
			2 ~ ~ ~ - - -
			1 ~ ~ ~ - - -
  	  	  	  A B C D E F
		 *
		 * */


		void	printBoards2();

		/*
		 * prints the board in this format ->
		 *    - - - ~ ~ ~
			1 - - - ~ ~ ~ 2
  	  	  	  - - - ~ ~ ~
  	  	  	  ~ ~ ~ - - -
			3 ~ ~ ~ - - - 4
  	  	  	  ~ ~ ~ - - -
		 *

		 * */


		void	rotate90right(char a[N][N]);

		//rotates a board 90 degrees right
		void	rotate90Left(char mat[N][N]);

		//rotates a board 90 degrees left

		char	getValue(int i,int j);

		//returns  the value at board[i][j]

		/*
		it takes int i and j -> (0<=i<6)(0<=j<6)
		according to the values i and j it checks at what board
		these values are ,for example (i,j)=(5,5)-> it is in board4[2][2]
		(i,j)=(0,0)-> it is in board1[0][0]
		*/
		void	setValueAt(int i,int j,char value);

};




#endif /* PENTAGO_H_ */
