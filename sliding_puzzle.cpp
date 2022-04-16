#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


const int n = 4;

void wypelnienie_tablicy(int[][n]);
void wypelnienie_losowe(int[][n]);
void znajdz_zero(int[][n], int &, int &);
bool sprawdzenie(int[][n], int);
int losowanie(int[][n]);
void rysowanie_tablicy(int [][n]);
void sterowanie(int[][n], int &, int &);
void zakonczenie(int[][n]);
void gora();
void dol();


int main()
{
	int tab[n][n];
	int x_zero, y_zero;

	srand(time(NULL));

	wypelnienie_tablicy(tab);
	wypelnienie_losowe(tab);
	znajdz_zero(tab, x_zero, y_zero);
	rysowanie_tablicy(tab);
	while (1)
	{
		rysowanie_tablicy(tab);
		sterowanie(tab, x_zero, y_zero);
		zakonczenie(tab);
	}

	return 0;
}
void wypelnienie_tablicy(int tab[][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = -1;
		}
	}
}
void wypelnienie_losowe(int tab[][n])
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = losowanie(tab);
		}
	}

}
int losowanie(int tab[][n])
{
	int liczba = rand() % (n * n);

	if (sprawdzenie(tab, liczba))
		return liczba;
	else
		{
			losowanie(tab);
		}
}
bool sprawdzenie(int tab[][n], int wylosowana_liczba)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] == wylosowana_liczba)
			{
				return false;
			}
		}
	}
	return true;
}
void znajdz_zero(int tab[][n], int &x_zero, int &y_zero)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] == 0)
			{
				x_zero = i;
				y_zero = j;
			}
		}
	}
}
void rysowanie_tablicy(int tab[][n])
{	
	cout << '\n';
	system("clear");

	for (int i = 0; i < n; i++)
	{
		gora();
		cout << '\n';

		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] <= 9 && tab[i][j] > 0)
			{
				cout << "|  " << tab[i][j] << " |";
			}
			else if (tab[i][j] == 0)
			{
				cout << "|    |";
			}
			else
			{
				cout << "| " << tab[i][j] << " |";
			}
			
		}
		cout << '\n';
		dol();
		cout << '\n';
	}
	for (int i = 0; i < n; i++)
	{
		cout << "======";
	}
	cout << '\n';
	cout << "Znak: ";

}
void gora()
{
	for (int i = 0; i < n; i++)
	{
		cout << "======";
	}
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		cout << "|    |";
	}
}
void dol()
{
	for (int i = 0; i < n; i++)
	{
		cout << "|    |";
	}
}
void sterowanie(int tab[][n], int &x_zero, int &y_zero)
{
	switch (getchar())
	{
	case 'w':
		{
			if (x_zero + 1 <= n - 1)
			{
				tab[x_zero][y_zero] = tab[x_zero + 1][y_zero];
				x_zero += 1;
				tab[x_zero][y_zero] = 0;
			}
			break;

		}
	case 's':
		{	
			if (x_zero - 1 >= 0)
			{
				tab[x_zero][y_zero] = tab[x_zero - 1][y_zero];
				x_zero -= 1;
				tab[x_zero][y_zero] = 0;
			}
			break;
		}
	case 'd':
		{
			if (y_zero - 1 >= 0)
			{
				tab[x_zero][y_zero] = tab[x_zero][y_zero - 1];
				y_zero -= 1;
				tab[x_zero][y_zero] = 0;
			}
			break;
		}
	case 'a':
		{
			if (y_zero + 1 <= n - 1)
			{
				tab[x_zero][y_zero] = tab[x_zero][y_zero + 1];
				y_zero += 1;
				tab[x_zero][y_zero] = 0;
			}
			break;
		}
		case 'q':
		{
			exit(0);
		}
	}
}
void zakonczenie(int tab[][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != n - 1 && j != n - 1)
			{
				if (tab[i][j] != (i * n) + j + 1)
					return;
			}
		}
	}
	cout << '\n' << "KONIEC GRY" << '\n';
	exit(0);
}