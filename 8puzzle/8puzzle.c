/*
	Authors:
		BASNILLO, Miles Lawrence R., 2013-12868
		JARO, Jeriel., 2013-_____

	CMSC 125 Project: 8-Puzzle Game

	** Please refer to README.md regarding editing, installing and running the program.
*/	

#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void Erase();
void EraseAll();
void PrintInstructions(int x, int y);
void RandomizeBoard();
void PrintMenu();
void PrintBoard(int x, int y);						
void PrintBorder(); 
void PrintArrow(int x, int y);								
void MovePiece(char d);

#define col 3
#define row 3

#define up 'w'
#define up2 (char)151
#define down 's'
#define down2 (char)152
#define left 'a'
#define left2 (char)150
#define right 'd'
#define right2 (char)153
#define quit 'q'
#define start 'e'
#define yes 'y'
#define no 'n'
#define enter '\n'
#define space ' '

/* Global variables */
int board[row][col];

void main(int argc, char *argv[]){
	char keypress = start;
	int ch=0;

	RandomizeBoard();

	set_graphics(VGA_320X200X256);

	PrintArrow(80, 105);

	do{	//Game loop
		PrintBorder();
		PrintMenu();
		keypress = (char)getch();

		if(keypress == quit){
			keypress = start;					//special condition so that it will not exit on Q press at menu
		}else if(keypress == up || keypress == up2){
			Erase(80, 120, 15, 15);
			PrintArrow(80, 105);
			ch = 0;
		}else if(keypress == down || keypress == down2){
			Erase(80, 100, 15, 15);
			PrintArrow(80, 125);
			ch = 1;
		}else if(keypress == enter || keypress == space){
			switch(ch){
				case 0:
						EraseAll();
						do{	//Inside-the-game loop
							PrintInstructions(180, 30);
							PrintBoard(30, 30);										//* Always prints update version of board at coordinates
							PrintBorder();														//* Always prints border
							keypress=(char)getch();
							
							if(keypress == up || keypress == up2){
								Erase(55, 175, 150, 15);
								//write_text("I pressed UP!", 55, 175, WHITE, 0);			//* Must update the values of the board after each keypress
								Erase(15, 15, 150, 170);
								MovePiece(keypress);
							}else if(keypress == left || keypress == left2){
								Erase(55, 175, 150, 15);
								//write_text("I pressed LEFT!", 55, 175, WHITE, 0);
								Erase(15, 15, 150, 170);
								MovePiece(keypress);
							}else if(keypress == right || keypress == right2){
								Erase(55, 175, 150, 15);
								//write_text("I pressed RIGHT!", 55, 175, WHITE, 0);
								Erase(15, 15, 150, 170);
								MovePiece(keypress);
							}else if(keypress == down || keypress == down2){
								Erase(55, 175, 150, 15);
								//write_text("I pressed DOWN!", 55, 175, WHITE, 0);
								Erase(15, 15, 150, 170);
								MovePiece(keypress);
							}else if(keypress == quit){
								Erase(55, 175, 150, 15);
								write_text("Are you sure? Y/N", 55, 175, WHITE, 0);
								do{
									keypress=(char)getch();
									if(keypress == yes){
										keypress = quit;
										break;
									}else if(keypress == no){
										keypress = yes;
										Erase(55, 175, 150, 15);
										break;
									}
								}while(1);
							}else{
								Erase(55, 175, 150, 15);
								write_text("Invalid button!", 55, 175, WHITE, 0);
							}
							
						}while(keypress != quit);
						EraseAll();
						PrintArrow(80, 105);
						keypress = start;
						break;
				case 1: keypress = quit;
						break;
				default: break;
			}
		}
		
	}while(keypress != quit);
	
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void PrintMenu(){
	int i, y=55, color;
	color = RED;

	write_text("8-", 20, 20, GREEN, 1);
	write_text("Puzzle", 40, 20, RED, 1);
	write_text("A game by CMSC 125 Students", 55, 35, WHITE, 0);
	for(i=15;i<305;i++) write_pixel(i, y, color);
	write_text("Start Game", 100, 100, WHITE, 1);
	write_text("Quit", 100, 120, WHITE, 1);

	write_text("ICS-OS", 250, 160, WHITE, 1);
}

void PrintBorder(){
	int i, x1=5, y1=5, x2=315, y2=195, color1, color2;
	color1 = GREEN;
	color2 = RED;

	for(i=5;i<315;i++) write_pixel(i, y1, color1);	//TOP
	for(i=5;i<315;i++) write_pixel(i, y1+2, color2);	//TOP
	for(i=5;i<315;i++) write_pixel(i, y2, color1);	//BOTTOM
	for(i=5;i<315;i++) write_pixel(i, y2+2, color2);	//BOTTOM
	for(i=5;i<195;i++) write_pixel(x1, i, color2);	//LEFT
	for(i=5;i<195;i++) write_pixel(x1+2, i, color1);	//LEFT
	for(i=5;i<195;i++) write_pixel(x2, i, color2);	//RIGHT
	for(i=5;i<195;i++) write_pixel(x2+2, i, color1);	//RIGHT
}

/*

*/
void PrintBoard(int x, int y){
	int i, j, k, l;
	k = x;
	l = y;

	char str[10];
	for(i=0; i<row; i++, l+=30){
		for(j=0; j<col; j++, k+=45){
			if(board[i][j] == 0){
				write_text(" ", k, l, WHITE, 0);
			}else{
				sprintf(str, "%d", board[i][j]);
				write_text(str, k, l, WHITE, 0);
			}
		}
		k = x;
	}

	for(i=20;i<140;i++){
		write_pixel(i, 20, WHITE);
		write_pixel(i, 50, WHITE);
		write_pixel(i, 80, WHITE);
		write_pixel(i, 110, WHITE);
	}

	for(i=20;i<110;i++){
		write_pixel(20, i, WHITE);
		write_pixel(60, i, WHITE);	
		write_pixel(100, i, WHITE);
		write_pixel(140, i, WHITE);
	}
}

/*
	Function from the lights out example
*/
void Erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

void EraseAll(){
	int i, j;
	for(i=1;i<320;i++){
		for(j=1;j<200;j++){
			write_pixel(i,j,100);
		}
	}
}

void PrintInstructions(int x, int y){
	write_text("8-Puzzle Game", x, y, GREEN, 0);
	write_text("Instructions: ", x, y+20, RED, 0);
	write_text("W - Move Up", x, y+40, WHITE, 0);
	write_text("S - Move Down", x, y+50, WHITE, 0);
	write_text("A - Move Left", x, y+60, WHITE, 0);
	write_text("D - Move Right", x, y+70, WHITE, 0);
	write_text("Q - Exit", x, y+80, WHITE, 0);
}

void PrintArrow(int x, int y){
	write_text(">>", x, y, WHITE, 0);
}


void RandomizeBoard(){
	int i, j, k=0;
	//temp hardcode
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j] = k;
			k++;
		}
	}
	//end of temp*/
	/*
	int boardCheck[9] = {0};
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			while(1){
				srand(time());
				board[i][j] = rand()%9;
				if(boardCheck[board[i][j]] == 0){
					boardCheck[board[i][j]] = 1;
					break;
				}
			}
		}
	}
	*/
}

void MovePiece(char d){
	int i, j, x, y, temp;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j] == 0){
				x = i;
				y = j;
				break;
			}
		}
	}
	if(d == up || d == up2){	
		board[x][y] = board[x+1][y];
		board[x+1][y] = 0;
	}
	if(d == down || d == down2){
		board[x][y] = board[x-1][y];
		board[x-1][y] = 0;
	}
	if(d == right || d == right2){
		board[x][y] = board[x][y-1];
		board[x][y-1] = 0;
	}
	if(d == left || d == left2){
		board[x][y] = board[x][y+1];
		board[x][y+1] = 0;
	}
}


/*
	FUNCTION FOR CHECKING INVERSIONS (TO BE USED LATER)

int CheckBoard(int board[9]){
	int i,j,inversions = 0;
	for(i=0;i<8;i++){
		for(j=i+1;j<9;j++){
			if(board[i] > board[j]){
				inversions++;
			}
		}
	}
	return inversions;
}

*/