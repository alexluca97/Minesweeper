#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<iomanip>


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

int main(int argc, char* argv[])
{
	char red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
	char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
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
}

