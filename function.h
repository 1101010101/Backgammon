# Backgammon
Backgammon PVE PVP

#include<iostream>
#include<stdlib.h>
#include"graphics.h"
#include<conio.h>

const int ROW = 20;
const int COL = 20;

int ChessBoard[ROW][COL];
int	F_S;
int save_1, save_2;
int save_3, save_4;
int save_5, save_6;
char regret;

bool flag = true;
int flag_1, flag_2;
int first_menu();
void star_select();
int game_instruction();
void first_switch();
void star_switch();
void Chessboard();
void PVE();
void PVP();
void Chess();
int Check();
void Regret();




int first_menu()
{
	system("CLS");
	using namespace std;
	cout << "=========================================================================\n";
	cout << "=                                                                       =\n";
	cout << "=                                                                       =\n";
	cout << "=                            五子棋游戏                                 =\n";
	cout << "=                                                                       =\n";
	cout << "=                      1.     开始游戏                                  =\n";
	cout << "=                                                                       =\n";
	cout << "=                      2.     游戏说明                                  =\n";
	cout << "=                                                                       =\n";
	cout << "=                      3.     退出游戏 (任意值)                         =\n";
	cout << "=                                                                       =\n";
	cout << "=========================================================================\n";

	cout << "请输入您的选择： ";
	cin >> flag_1;
	return flag_1;
}




void first_switch()	
{
	switch (flag_1)
	{
	case 1: {star_select(); break; }
	case 2: {game_instruction(); break; }
	default:flag = false;
		break;
	}
}




void star_select()
{
	system("CLS");
	using namespace std;
	cout << "=========================================================================\n";
	cout << "=                                                                       =\n";
	cout << "=                                                                       =\n";
	cout << "=                             开始游戏                                  =\n";
	cout << "=                                                                       =\n";
	cout << "=                      1.     人机对战                                  =\n";
	cout << "=                                                                       =\n";
	cout << "=                      2.     玩家对战                                  =\n";
	cout << "=                                                                       =\n";
	cout << "=                      3.     返回菜单 (任意值)                         =\n";
	cout << "=                                                                       =\n";
	cout << "=========================================================================\n";

	cout << "请输入您的选择： ";
	cin >> flag_2;
	star_switch();

}

int game_instruction()
{
	system("CLS");
	using namespace std;
	cout << "五子棋是一种两人对弈的纯策略型棋类游戏，通常双方分别使用黑白两色的棋子，\n下在棋盘直线与横线的交叉点上，先形成5子连线者获胜。\n\n\n";
	cout << "输入任意值返回开始菜单\n";
	system("pause>nul 2>nul");
	return first_menu();
}

void Chessboard()
{
	system("CLS");
	using namespace std;
	for (int j = 0; j<20; j++)
	{
		ChessBoard[0][j] = j;
		printf("%3d", ChessBoard[0][j]);
	}
	printf("\n");
	for (int i = 1; i<20; i++)
	{
		for (int j = 0; j<20; j++)
		{

			if (j == 0)
			{
				ChessBoard[i][0] = i;
				printf("%3d", ChessBoard[i][0]);
			}
			else if (i>0 && j>0)
			{
				if (ChessBoard[i][j] == 0)
				{
					printf("  *");
				}
				if (ChessBoard[i][j] == 21)
				{
					printf(" ○");
				}
				if (ChessBoard[i][j] == 22)
				{
					printf(" ●");
				}
			}
		}
		printf("\n");
	}
}

void PVE()
{
	system("CLS");
	using namespace std;
	cout << "请问您先想先手（0）还是后手（1）:";
	for (;;)
	{
		cin >> F_S;
		if (F_S == 0 || F_S == 1)
			break;
	}
	memset(ChessBoard, 0, sizeof(ChessBoard));
	while (Check())
	{
		Chessboard();
		Chess();
	}
	int a;
	cin >> a;
}

void PVP()
{
	system("CLS");
	using namespace std;
	//cout << "请问您先执黑棋（0）还是执白棋（1）:";
	//for (;;)
	//{
	//	cin >> F_S;
	//	if (F_S == 0 || F_S == 1)
	//		break;
	//}
	memset(ChessBoard, 0, sizeof(ChessBoard));
	using namespace std;
	while (true)
	{
		if (!F_S)
		{
			Chessboard();
			cout << "请执黑下棋" << endl;
			Chess();

			if (!Check())
			{
				cout << "如若需要悔棋可以输入Y，不需要的话输入任意键：";
				cin >> regret;
				if (regret == 'Y' || regret == 'y')
				{
					Regret();
					continue;
				}
				break;
			}
			save_5 = save_3;
			save_6 = save_4;
			save_3 = save_1;
			save_4 = save_2;
		}
		else
		{
			Chessboard();
			cout << "请执白下棋" << endl;
			Chess();
			if (!Check())
			{
				cout << "如若需要悔棋可以输入Y，不需要的话输入任意键：";
				cin >> regret;
				if (regret == 'Y' || regret == 'y')
				{
					Regret();
					continue;
				}
				break;
			}
			save_5 = save_3;
			save_6 = save_4;
			save_3 = save_1;
			save_4 = save_2;
		}
		F_S = !F_S;
	}
	system("pause>nul 2>nul");
}

void Chess()
{
	using namespace std;
	cout << "请输入落子位置：";
	int i, j;
	cin >> i >> j;
	if (ChessBoard[i][j] != 0||i>=20||i<=0||j>=20||j<=0)
	{	
		for (;;)
		{
			cout << "此位置非法，你不能下在此处，请换个位置\n";
			cin >> i >> j;
			Chessboard();
			if (ChessBoard[i][j] == 0&& !(i >= 20 || i <= 0 || j >= 20 || j <= 0))
				break;
		}
			
	}
	save_1 = i;
	save_2 = j;
	if (F_S == 0)
		ChessBoard[i][j] = 21;
	else
		ChessBoard[i][j] = 22;
}


void star_switch()
{
	system("CLS");
	using namespace std;
	switch (flag_2)
	{
	case 1:PVE(); break;
	case 2:PVP(); break;
	default:exit;
		break;
	}
}



int Check()
{
	for (int i = 1; i<20; i++)
	{
		for (int j = 1; j<20; j++)
		{
			if (ChessBoard[i][j] == 21 && ChessBoard[i][j + 1] == 21 && ChessBoard[i][j + 2] == 21 && ChessBoard[i][j + 3] == 21 && ChessBoard[i][j + 4] == 21)
			{
				printf("黑子胜\n");
				return 0;
			}
			if (ChessBoard[i][j] == 22 && ChessBoard[i][j + 1] == 22 && ChessBoard[i][j + 2] == 22 && ChessBoard[i][j + 3] == 22 && ChessBoard[i][j + 4] == 22)
			{
				printf("白子胜\n");
				return 0;
			}
			if (ChessBoard[i][j] == 21 && ChessBoard[i + 1][j] == 21 && ChessBoard[i + 2][j] == 21 && ChessBoard[i + 3][j] == 21 && ChessBoard[i + 4][j] == 21)
			{
				printf("黑子胜\n");
				return 0;
			}
			if (ChessBoard[i][j] == 22 && ChessBoard[i + 1][j] == 22 && ChessBoard[i + 2][j] == 22 && ChessBoard[i + 3][j] == 22 && ChessBoard[i + 4][j] == 22)
			{
				printf("白子胜\n");
				return 0;
			}
			if (ChessBoard[i][j] == 21 && ChessBoard[i + 1][j + 1] == 21 && ChessBoard[i + 2][j + 2] == 21 && ChessBoard[i + 3][j + 3] == 21 && ChessBoard[i + 4][j + 4] == 21)
			{
				printf("黑子胜\n");
				return 0;
			}
			if (ChessBoard[i][j] == 22 && ChessBoard[i + 1][j - 1] == 22 && ChessBoard[i + 2][j - 2] == 22 && ChessBoard[i + 3][j - 3] == 22 && ChessBoard[i + 4][j - 4] == 22)
			{
				printf("白子胜\n");
				return 0;
			}
		}
	}
	return 1;
}

void Regret()
{
	ChessBoard[save_1][save_2] = 0;
	ChessBoard[save_3][save_4] = 0;
	ChessBoard[save_5][save_6] = 0;
	Chessboard();
}
