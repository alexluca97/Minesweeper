#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <time.h>
using namespace std;
int a[100][100];
char b[100][100];
int arrow()
{
	int i;
	i=getch();
	if (i == 224)i=getch();
	switch (i)
	{
	case 13:
		return 1;
	case 80://down
		return 2;
	case 72://up
		return 3;
	case 75://left
		return 4;
	case 77://right
		return 5;
	case 102://f
		return 6;
	default:
		return 0;
	}
	return 0;
}
int n;
void bmbselect(int i,int j)
{
	if (a[i][j]==-1);
	else
	{
		if (i + 1 < n && a[i + 1][j] == -1)a[i][j]++;
		if (i > 0 && a[i - 1][j] == -1)a[i][j]++;
		if (j + 1 < n && a[i][j + 1] == -1)a[i][j]++;
		if (j > 0 && a[i][j - 1] == -1)a[i][j]++;
		if (i + 1 < n && j + 1 < n && a[i + 1][j + 1] == -1)a[i][j]++;
		if (i + 1 < n && j > 0 && a[i + 1][j - 1] == -1)a[i][j]++;
		if (i > 0 && j + 1 < n && a[i-1][j + 1] == -1)a[i][j]++;
		if (i > 0 && j > 0 && a[i - 1][j - 1] == -1)a[i][j]++;
	}
}
void lee(int i, int j)
{
	if (a[i][j] == -1 || b[i][j]!='O' || j<0 || i<0 || j>=n || i>=n);
	else
	{
		if (a[i][j] == 0)
		{
			b[i][j] = ' ';
			lee(i + 1, j);
			lee(i - 1, j);
			lee(i, j + 1);
			lee(i, j - 1);
			lee(i + 1, j + 1);
			lee(i + 1, j - 1);
			lee(i - 1, j + 1);
			lee(i - 1, j - 1);
		}
		else
			b[i][j] = (char)(a[i][j]+48);
	}
}
int Menu()
{
    string Menu[2] = {"Start Game", "Exit"};
	int pointer = 0;

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Menu\n\n";

		for (int i = 0; i < 2; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] << endl;
			}
		}

		while(true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 2)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
					case 0:
					{
					    return 1;
                    }break;
					case 1:
					{
					    return 0;

					} break;
				}break;
			}
		}

		Sleep(150);
	}
}
int Again()
{
    string Again[2] = {"Yes", "No"};
	int pointer = 0;

	while(true)
	{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Again?\n\n";

		for (int i = 0; i < 2; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Menu[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Menu[i] << endl;
			}
		}

		while(true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 1;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 2)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
					case 0:
					{
					    return 1;
                    }break;
					case 1:
					{
					    return 0;

					} break;
				}break;
			}
		}

		Sleep(150);
	}
}


int main(int argc, char* argv[])
{
    srand(time(NULL));
    int x=Menu();
    while(x==1)
        {
            cout<<endl;
            cout<<"\n\nCat de mare vrei sa fie terenul tau minat?";
            cin>>n;
            cout<<"Deci va fi de "<< n <<"x"<<n;
            cout<<endl;
            Sleep(1000);
            while(n<4)
                {
                    cout<<"Prea mic, incearca din nou\n";
                    cin>>n;
                }
            if(n<8)
                {
                    cout<<"Prea usor...";
                    Sleep(1000);
                }
            if(n>7 && n<15)
                {
                    cout<<"Impresionant...";
                    Sleep(1000);
                }
            if(n>14)
                {
                    cout<<"Succes!";
                    Sleep(1000);
                }
            system("cls");
            char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
            char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };


            int i, j;
            int q, r;
            for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                b[i][j] = 'O';
            int bmb = n * 2;
            for (i = 0; i < bmb;i++)
                {
                    q = rand() % n;
                    r = rand() % n;
                    while (a[q][r] != 0)
                        {
                            q = rand() % n;
                            r = rand() % n;
                        }
                    a[q][r] = -1;
                }
            for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                bmbselect(i, j);
            system("cls");
            int ok = 0;
            i = 0; j = 0;
            int p, k;
            int flags = 0, correctflags = 0;
            while (!ok)
                {
                    system("cls");
                    if (flags == correctflags && flags == bmb)
                        {
                            ok = 1;
                            for (p = 0; p < n; p++)
                            for (k = 0; k < n; k++)
                                if (b[p][k] == 'O')
                                    {
                                        ok = 0;
                                    }
                                if (ok)
                                    {
                                        cout << "Wow! Ai castigat!" << '\n';
                                    }
                        }
                    for (p = 0; p < n; p++)
                        {
                            for (k = 0; k < n; k++)
                                {
                                    if (p == i && k == j)
                                        cout << "|";
                                    else
                                        cout << ' ';
                                    cout << b[p][k] << " ";
                                }
                            cout << '\n';
                        }
                    int q = arrow();
                    switch (q)
                        {
                            case 1:
                                break;
                            case 2:
                                i++;
                                break;
                            case 3:
                                i--;
                                break;
                            case 4:
                                j--;
                                break;
                            case 5:
                                j++;
                                break;
                            case 6:
                                break;
                        }
                    if (i == n)
                        i = n - 1;
                    if (j == n)
                        j = n - 1;
                    if (j < 0)
                        j = 0;
                    if (i < 0)
                        i = 0;
                    if (q == 1 && a[i][j] == -1 && b[i][j] == 'O')
                        {
                            system("cls");
                            cout << "Haha! Ai murit!" << '\n';
                            b[i][j] = '*';
                            for (p = 0; p < n; p++)
                                {
                                    for (k = 0; k < n; k++)
                                        if (a[p][k] == -1)
                                            {
                                                cout <<red<< "  B" << normal;
                                            }
                                        else if (a[p][k] == 0)
                                            cout << "   ";
                                        else if (a[p][k] > 0)
                                            cout << "  " << a[p][k];
                                        else
                                            cout << "  " << b[p][k];
                                        cout << '\n';
                                }
                                Sleep(10000);
                                return 0;
                        }
                    if (q == 1 && b[i][j]!='?')
                    lee(i, j);
                    if (q == 6)
                        {
                            if (b[i][j] == '?')
                                {
                                    if (a[i][j]==-1)
                                        {
                                            correctflags--;
                                        }
                                    b[i][j] = 'O';
                                    flags--;
                                }
                            else
                                {
                                    if (a[i][j] == -1)
                                        {
                                            correctflags++;
                                        }
                                    b[i][j] = 'B';
                                    flags++;
                                }
                        }

                }
        }
    return 0;
}


