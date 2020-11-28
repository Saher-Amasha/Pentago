/*
 * Pentago.cpp
 *
 *  Created on: 23 Apr 2020
 *      Author: saher
 */


#include"Pentago.h"

		Pentago::Pentago()
		{

			DeafultBoard(1);
			DeafultBoard(2);
			DeafultBoard(3);
			DeafultBoard(4);

			this->startingPlayer='W';
			this->turnNum=0;
		}


		void	Pentago::DeafultBoard(int BoardNUM)
		{


		switch (BoardNUM)
		{
			case 1:
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						this->board1[i][j]='-';
				break;

			case 2:
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						this->board2[i][j]='~';
				break;

			case 3:
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						this->board3[i][j]='~';
				break;
			case 4:
				for(int i=0;i<3;i++)
					for(int j=0;j<3;j++)
						this->board4[i][j]='-';
				break;

			 default:
				 	 break;
		}





	}
		bool	Pentago::setValueonBoard(string input,char player)
		{

			 if(input.length()>3)
				{
						   cerr<<"Invalid placement move; the game awaits a valid move"<<endl;
						   	   	   	   return false;
				}

			char *arr=new char[input.length()+1];
			for (int i = 0; i < (int)input.length(); i++)
			        arr[i] = input[i];

			    if(!isalpha(arr[0])&&!isdigit(arr[1]))
			    {
			    	 cerr<<"Invalid placement move; the game awaits a valid move"<<endl;
			    							  return false;
			    }
			    int j;
			    if(isupper(arr[0]))
			    	j=arr[0]-'A';
			    	else
			    j=arr[0]+('A'-'a')-'A';
			    int i=arr[1]-'0';
			    if((j<0)||(j>5)||i<1||i>6)
			    {
			    	 cerr<<"Invalid placement move; the game awaits a valid move"<<endl;
			    							  	 return false;
			    }
			   if(isEmpty(6-i,j)==false)
			   {
				   cerr<<"Invalid placement move; the game awaits a valid move"<<endl;
				  						  return false;
			   }
			   setValueAt(6-i,j,player);

			   delete[]arr;

			   return true;


		}
		void	Pentago::printAt(int i,int j)
		{

							if(i<=2&&j<=2)
							{
								cout<<this->board1[i%3][j%3];
							}
							if(i<=2&&j>2)
							{
								cout<<this->board2[i%3][j%3];
							}
							if(i>2&&j<=2)
							{
							 	cout<<this->board3[i%3][j%3];
							}
							if(i>2&&j>2)
							{
								cout<<this->board4[i%3][j%3];
							}
		}
		bool Pentago::isEmpty(int i,int j)
		{
			char temp=getValue(i,j);
			if(temp=='~'||temp=='-')
				return true;

						return false;


		}
		void	Pentago::setValueAt(int i,int j,char val)
		{
				if(i<=2&&j<=2)
				{
						this->board1[i%3][j%3]=val;
				}
				if(i<=2&&j>2)
				{
					this->board2[i%3][j%3]=val;
				}
				if(i>2&&j<=2)
				{
				 	this->board3[i%3][j%3]=val;
				}
				if(i>2&&j>2)
				{
					this->board4[i%3][j%3]=val;
				}
		}
		void	Pentago::play()
		{
			int x=-1;

			string input;


			int n=0;
			if(this->startingPlayer=='B')
				n=1;
			while(1)
			{

				this->printBoards();

				switch((n+this->turnNum)%2)
				{
				case 0:
				cout<<"White's placement move:"<<endl;
				while(1)
				{

					std::getline(std::cin, input);
					bool temp1=setValueonBoard(input,'W');
					if(temp1==true)
						break;
				}

				x=gameOver();


					if(x==1)
					{

						this->printBoards();
						cout<<"Black wins!"<<endl;

							return;

							break;
					}
					if(x==2)
					{

					this->printBoards();
					cout<<"White wins!"<<endl;

					return;
					break;
					}

				input="";

				this->printBoards2();

				cout<<"White's rotation move:"<<endl;

				while(1)
				{

				std::getline(std::cin, input);
				bool temp2=this->rotateBoard(input);

				if(temp2==true)
					break;
				}

				break;

				case 1:

					cout<<"Black's placement move:"<<endl;

					while(1)
					{

					std::getline(std::cin, input);
					bool temp3=setValueonBoard(input,'B');
					if(temp3==true)
							break;
					}


					input="";

					x=gameOver();


					if(x==1)
					{
						this->printBoards();
							cout<<"Black wins!"<<endl;

							return;
							break;
					}
					if(x==2)
					{
						this->printBoards();
						cout<<"White wins!"<<endl;

						return;
						break;
					}
					this->printBoards2();
				cout<<"Black's rotation move:"<<endl;
				while(1)
				{

					std::getline(std::cin, input);
					bool temp4=this->rotateBoard(input);
					if(temp4==true)
						break;

				}

					break;

				}


				x=-1;
				x=gameOver();

				if(x==0)
				{
					this->printBoards();
					cout<<"It's a draw!"<<endl;

						break;
				}
				if(x==1)
				{
					this->printBoards();
					cout<<"Black wins!"<<endl;

					break;
				}
				if(x==2)
				{
					this->printBoards();
					cout<<"White wins!"<<endl;

					break;
				}
				this->turnNum++;

			}
		}

		bool	Pentago::rotateBoard	 (string input)
		{
			char *arr=new char[input.length()+1];
			for (int i = 0; i <(int)input.length(); i++)
			{
						        arr[i] = input[i];
			}
			 int i=arr[0]-'0';
			char left_or_right=arr[1];
			 if(input.length()>3||(!isalpha(arr[1])||!isdigit(arr[0])))
				{
						 cerr<<"Invalid rotation move; the game awaits a valid move"<<endl;


						 return false;

				}



			    if(!isupper(arr[1])&&!isdigit(arr[0]))
			    {
			    	cerr<<"Invalid rotation move; the game awaits a valid move"<<endl;
			    							 return false;
			    }



			    if(left_or_right=='L'||left_or_right=='l')
			    {
			    	switch(i)
			    	{
			    	case 1:
			    		rotate90Left(this->board1);
			    		break;


			    	case 2:
			    		rotate90Left(this->board2);
			    		break;


			    	case 3:
			    		rotate90Left(this->board3);
			    		break;


			    	case 4:
			    		rotate90Left(this->board4);
			    		break;

			    	default:
			    		cerr<<"Invalid rotation move; the game awaits a valid move"<<endl;
			    				 return false;

			    					    break;
			    	}



			    }
			    else if(left_or_right=='R'||left_or_right=='r')
			   	{
			    	switch(i)
			    	{
			    		case 1:
			    			rotate90right(this->board1);
			    			break;


			    		case 2:
			    			 rotate90right(this->board2);
			    			 break;


			    		case 3:
			    			  rotate90right(this->board3);
			    			  break;


			    		case 4:
			    			rotate90right(this->board4);
			    		break;

			    		default:
			    			cerr<<"Invalid rotation move; the game awaits a valid move"<<endl;
			    					  return false;
			    	}
			   }
				else
				{

					cerr<<"Invalid rotation move; the game awaits a valid move"<<endl;
											 return false;
				}

			    delete[]arr;

			    return true;


		}
		void Pentago::rotate90Left(char board[N][N])
		{

		    for (int x = 0; x < N / 2; x++) {

		        for (int y = x; y < N - x - 1; y++) {

		            char temp = board[x][y];

		            board[x][y] = board[y][N - 1 - x];

		            board[y][N - 1 - x] = board[N - 1 - x][N - 1 - y];

		            board[N - 1 - x][N - 1 - y] = board[N - 1 - y][x];
		            board[N - 1 - y][x] = temp;
		        }
		    }
		}
		void Pentago::rotate90right(char a[N][N])
		{




		    for (int i = 0; i < N / 2; i++) {
		        for (int j = i; j < N - i - 1; j++) {


		            int temp = a[i][j];
		            a[i][j] = a[N - 1 - j][i];
		            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
		            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
		            a[j][N - 1 - i] = temp;
		        }
		    }
		}
		int	Pentago::gameOver()
		{

			bool blackwon=false;
			bool whitewon=false;

			//check for draw
			char looking_for;
			int counter1=0;
		for(int let=0;let<2;let++)
		{
				if(let==0)
				{
					looking_for='W';
				}

				if(let==1)
				{
				looking_for='B';
				}




		for(int y=0;y<2;y++)
		{
			for(int x=0;x<2;x++)
			{



				for(int j=0;j<5;j++)
				{
					if(getValue(x+j,y+j)==looking_for)
					{
							counter1++;
					}

							if(counter1==5)
							{
								if(looking_for=='W')
								{
									whitewon=true;
								}
									//return 2;
								if(looking_for=='B')
								{
									blackwon=true;
								}
									//return 1;
							}
				}

				counter1 =0;
			}
		}

		}
		counter1=0;


for(int let=0;let<2;let++)
{



	if(let==0)
	{
		looking_for='W';
	}

	if(let==1)
	{
		looking_for='B';
	}

for(int y=4;y<6;y++)
{
  for(int x=0;x<2;x++)
	{

		for(int j=0;j<5;j++)
		{
			if(getValue(x+j,y-j)==looking_for)
			{
					counter1++;
			}

			if(counter1==5)
			{
				if(looking_for=='W')
				{
					whitewon=true;
				}
					//return 2;
				if(looking_for=='B')
				{
					blackwon=true;
				}
					//return 1;
			}
		}

	counter1=0;
	}
}
}
			for(int let=0;let<2;let++)
			{
				if(let==0)
				{
					looking_for='W';
				}

				if(let==1)
				{
					looking_for='B';
				}
				int counter;

			for(int i=0;i<6;i++)
			{

				for (int k=0;k<2;k++)
				{
					for (int j=0;j<5;j++)
					{
						if(getValue(i,k+j)==looking_for)
						{
							counter++;
						}
						if(counter==5)
						{
							if(looking_for=='W')
							{
								whitewon=true;
							}
								//return 2;
							if(looking_for=='B')
							{
								blackwon=true;
							}

								//return 1;
						}

					}

					counter=0;


				}


			}


			}
			



			for(int let=0;let<2;let++)
				{
					if(let==0)
					{
						looking_for='W';
					}

					if(let==1)
					{
						looking_for='B';
					}

					int counter=0;

				for(int i=0;i<6;i++)
				{

					for (int k=0;k<2;k++)
					{
						for (int j=0;j<5;j++)
						{
							if(getValue(j+k,i)==looking_for)
							{
								counter++;
							}
							if(counter==5)
							{
								if(looking_for=='W')
								{
									whitewon=true;
								}
									//return 2;
								if(looking_for=='B')
								{
									blackwon=true;
								}
									//return 1;
							}

						}

						counter=0;


					}


				}


				}







			bool fullboard=true;
				for(int i=0;i<6;i++)
				for(int j=0;j<6;j++)
				if(isEmpty(i,j)==true)
					fullboard=false;

				if(whitewon==true&&blackwon==true)
				{
					return 0;
				}
				if(whitewon==true)
				{
					return 2;
				}
				if(blackwon==true)
				{
					return 1;
				}


				if(fullboard==true)
				{
					return 0;
				}

				return -1;




		}
		char Pentago::getValue(int i,int j)
		{
			if(i<=2&&j<=2)
			{
				return this->board1[i%3][j%3];
			}
			if(i<=2&&j>2)
			{
				return this->board2[i%3][j%3];
			}
			if(i>2&&j<=2)
			{
				return this->board3[i%3][j%3];
			}
			if(i>2&&j>2)
			{
				return this->board4[i%3][j%3];
			}

			return -1;
		}
		void	Pentago::printBoards()
		{

			for(int i=0;i<6;i++)
			{
				cout<<6-i<<" ";
				for(int j=0;j<6;j++)
				{
					printAt(i,j);
					if(j!=5)
						cout<<" ";
				}

				cout<<endl;

			}
			cout<<"  ";
			char temp='A';
			for(int i=0;i<5;i++)
			{

				cout<<temp<<" ";


				temp+=1;
			}

			cout<<temp<<endl;


			cout<<endl;
		}
		void	Pentago::printBoards2()
		{



			for(int i=0;i<6;i++)
					{


						if(i==1)
						cout<<i<<" ";
						else if(i==4)
							cout<<i-1<<" ";
						else
						cout<<"  ";




						if(i!=6)
						for(int j=0;j<7;j++)
						{

							if(j<6)
							{

								printAt(i,j);
								if(j!=5)
								cout<<" ";
							}
							if(j==6)
							{
							if(i==1)
								cout<<" "<<i+1;
							else if(i==4)
								cout<<" "<<i;
							}

						}

						cout<<endl;

					}

			cout<<endl;
		}

