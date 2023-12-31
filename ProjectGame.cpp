#include <iostream>
#include <string>
#include <Windows.h>
#include <playsoundapi.h>
#include <dsound.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
int winPlayer1 = 0;
int winPlayer2 = 0;
int draw = 0;
int rounds = 1;
string player1choise;
string player2choise;
enum choices {
	paper = 1,
	stone = 2,
	sciessor = 3
};

void showChoices() {
	cout << "\tYour choice : " << "[1]" << '[' << "paper" << ']' << "\t[2]" << '[' << "stone" << ']' << "\t[3]" << '[' << "sciessor" << "] ?" << endl;
}

int takeChoiseP1()
{
	int num;
	do
	{
		cout << "Enter number between[1,2,3]" << endl;
		cin >> num;
	} while (num > 3 || num < 1);
	return num;
}
int takeChoiseP2()
{
	return rand() % 3 + 1;
}
int winner(int c1, int c2)
{
	if ((c1 == choices::paper && c2 == choices::paper) || (c1 == choices::sciessor && c2 == choices::sciessor) || (c1 == choices::stone && c2 == choices::stone))
	{
		if (c1 == 1)
		{
			player1choise = "paper";
			player2choise = "paper";
			return 0;
		}
		else if (c1 == 2)
		{
			player1choise = "stone";
			player2choise = "stone";
			return 0;
		}
		else
		{
			player1choise = "sciessor";
			player2choise = "sciessor";
			return 0;
		}
	}
	else if ((c1 == choices::paper && c2 == choices::stone))
	{
		player1choise = "paper";
		player2choise = "stone";

		return 1;
	}
	else if ((c1 == choices::paper && c2 == choices::sciessor))
	{
		player1choise = "paper";
		player2choise = "sciessor";

		return 2;
	}
	else if ((c1 == choices::stone && c2 == choices::sciessor))
	{
		player1choise = "stone";
		player2choise = "sciessor";

		return 1;
	}
	else if ((c1 == choices::stone && c2 == choices::paper))
	{
		player1choise = "stone";
		player2choise = "paper";
		return 2;
	}
	else if ((c1 == choices::sciessor && c2 == choices::paper))
	{
		player1choise = "sciessor";
		player2choise = "paper";

		return 1;
	}
	else if ((c1 == choices::sciessor && c2 == choices::stone))
	{
		player1choise = "sciessor";
		player2choise = "stone";

		return 2;
	}
}

void scoorCount(int num)
{
	if (num == 1)
	{
		winPlayer1++;
	}
	else if (num == 2)
	{
		winPlayer2++;
	}
	else
	{
		draw++;
	}
}

void showCurrentState(int roundCount, int c1, int c2)
{
	cout << "_____________________Round " << '[' << roundCount << ']' << "_______________________" << endl;
	int win = winner(c1, c2);
	cout << "Player1 choice: " << player1choise << endl;
	cout << "Player2 choice: " << player2choise << endl;
	cout << "Round Winner: ";

	if (win == 1)
	{
		cout << "Player1" << endl;
		system("Color 20");
		PlaySound(L"1.wav", 0, 0);

		//PlaySound(TEXT("C:\\Users\\hosam\\OneDrive - Delta Technological University\\Desktop\\I_O sound\\1.wav"), NULL, SND_SYNC);
		//PlaySound(L"C:\\Users\\hosam\\OneDrive - Delta Technological University\\Desktop\\1.mp3", 0, 0);
	}
	else if (win == 2)
	{
		cout << "Computer" << endl;
		system("Color 40");
		PlaySound(L"2.wav", 0, 0);
	}
	else
	{
		cout << "Draw" << endl;
		system("Color 60");
	}
	cout << "_______________________________________________________________________________" << endl;
}
void endResult()
{
	cout << "\n\t\t______________________________________________________________________________________" << endl
		<< "\t\t\t\t\t\t" << "+++ Game Over+++" << endl
		<< "\t\t______________________________________________________________________________________\n" << endl
		<< "\t\t________________________________[Game Result]_________________________________________" << endl
		<< "\t\tGame Rounds        :" << rounds << endl
		<< "\t\tPlayer1 won times  :" << winPlayer1 << endl
		<< "\t\tPlayer2 won times  :" << winPlayer2 << endl
		<< "\t\tDraw times         :" << draw << endl
		<< "\t\tFinal winner       :";
	if (winPlayer1 == winPlayer2)
	{
		cout << "no winner" << endl
			<< "_________________________________________________________________________________________" << endl;
	}
	else if (winPlayer1 > winPlayer2)
	{
		cout << "Player1 win" << endl
			<< "_________________________________________________________________________________________" << endl;
	}
	else if (winPlayer1 > winPlayer2)
	{
		cout << "Computer win" << endl
			<< "_________________________________________________________________________________________" << endl;
	}
}
bool takeChar()
{
	char c;
	do
	{
		cout << "\nDo you want play again ? [Y:y] or [N:n]to exit " << endl;
		cin >> c;
		if (c == 'n' || c == 'N')
		{
			return 0;
		}
		else if (c == 'y' || c == 'Y')
		{
			return 1;
		}
	} while (c != 'Y' || c != 'y');
}

int main()
{
	char flag = 'Y';
	do
	{
		system("cls");
		system("Color 04");
		srand(unsigned(time(NULL)));
		cout << "How many times do you want ? : ";
		int times;
		cin >> times; rounds = times;
		int rcnt = 0;
		while (times--)
		{
			cout << "Round " << '[' << ++rcnt << ']' << " begins:\n" << endl;
			showChoices();
			int p1 = takeChoiseP1();
			int p2 = takeChoiseP2();
			int win = winner(p1, p2);
			scoorCount(win);
			showCurrentState(rcnt, p1, p2);
		}
		endResult();
		if (takeChar())
		{
			flag = 'Y';
		}
		else
		{
			flag = 'n';
		}
	} while (flag == 'Y' || flag == 'y');
}
