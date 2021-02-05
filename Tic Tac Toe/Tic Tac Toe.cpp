#include <iostream>
#include <vector>
#include <array>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Main {
private:
	bool checkTurn = false;

	std::array<char, 2> playersTags;
	char board[3][3] = { 0 };

	unsigned short width, height;

	vector<string> playersNames;
	
	string edge = "-------------\n";

	void setTag() {
		cout << "Press key to choose your mark: ";
		cin>>playersTags[checkTurn];
	}

	void setNickname() {
		string buffer;
		cout << "Wright your name: ";
		cin >> buffer;
		playersNames.push_back(buffer);
	}
	void tickCell() {
		cout << "Choose cell: ";
		cin>>width;

		system("cls");
		showBoard();

		cout << "Choose cell: ";
		cout << width << " / ";
		cin>>height;

		if (width > 3 || height > 3) tickCell();
	}
public:
	void showBoard() {
		system("cls");
		cout << "Players: " << playersNames[0] << " / " << playersNames[1] <<endl << edge;
		for (int i = 0; i < 3; i++) {
			cout << "| ";
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 0) cout << "  | ";
				else cout << board[j][i] << " | ";
			}
			cout << "\b\n" << edge;
		}
	}

	void introduceYourself() {
		do {
			setNickname();
			setTag();
			if (checkTurn) checkTurn = false;
			else checkTurn = true;
		} while (checkTurn);
	}

	void markCell() {
		tickCell();
		if (board[width - 1][3 - height] == 0) {
			board[width - 1][3 - height] = playersTags[checkTurn];
			
		}
		else markCell();
	}
	void check() {
		if ((board[0][0] == playersTags[checkTurn] && board[0][1] == playersTags[checkTurn] && board[0][2] == playersTags[checkTurn]) ||
			(board[1][0] == playersTags[checkTurn] && board[1][1] == playersTags[checkTurn] && board[1][2] == playersTags[checkTurn]) ||
			(board[2][0] == playersTags[checkTurn] && board[2][1] == playersTags[checkTurn] && board[2][2] == playersTags[checkTurn]) ||
			(board[0][0] == playersTags[checkTurn] && board[1][0] == playersTags[checkTurn] && board[2][0] == playersTags[checkTurn]) ||
			(board[1][0] == playersTags[checkTurn] && board[1][1] == playersTags[checkTurn] && board[1][2] == playersTags[checkTurn]) ||
			(board[2][0] == playersTags[checkTurn] && board[2][1] == playersTags[checkTurn] && board[2][2] == playersTags[checkTurn]) ||
			(board[0][0] == playersTags[checkTurn] && board[1][1] == playersTags[checkTurn] && board[2][2] == playersTags[checkTurn]) ||
			(board[0][2] == playersTags[checkTurn] && board[1][1] == playersTags[checkTurn] && board[2][0] == playersTags[checkTurn]))
		
		{

			system("cls");
			cout << playersNames[checkTurn] << " won\nPress any key to play again";
			_getch();
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					board[i][j] = 0;
				}
			}
		}
		if (checkTurn) checkTurn = false;
		else checkTurn = true;
	}

	
};


int main() {
	Main expampleObj;

	expampleObj.introduceYourself();
	do {
		expampleObj.showBoard();
		expampleObj.markCell();
		expampleObj.check();

	} while (true);


	return 0;
}