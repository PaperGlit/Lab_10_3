#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void CreateTXT(char* fname, string s, string s1, string s2)
{
	ofstream fout(fname, ios_base::app);
	fout << s << " - " << s1 << " " << "(" << s2 << ")" << endl;
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}

string ProcessTXT(char* fname, char* search)
{	
	ifstream fin(fname);
	int k = 0;
	char l[255];
	char* line = new char[255];
	char lineres[255] = "";
	char* word = NULL;
	char* next_word = NULL;
	while (fin.getline(l, sizeof(l)))
	{
		strcpy_s(line, sizeof(l), l);
		word = strtok_s(l, " ", &next_word);
		while (word != NULL)
		{
			if (strcmp(word, search) == 0)
			{
				k++;
				strcat_s(line, 255, "\n");
				strcat_s(lineres, 255, line);
			}
			word = strtok_s(NULL, " ", &next_word);
		}
	}
	if (k == 0)
	{
		return (string)"No results";
	}
	return (string)lineres;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string s, s1, s2;
	int response;
	char yorn;
	char search[100];
	char filename[100];
	cout << "Enter filename : "; cin >> filename;
	do {
		cout << "1 - Create a new route; 2 - Search; 3 - Pirnt : "; cin >> response;
		if (response == 1)
		{
			cin.get();
			cin.sync();
			cout << "Starting city name : "; getline(cin, s);
			cout << "Destination city name : "; getline(cin, s1);
			cout << "Route number : "; getline(cin, s2);
			CreateTXT(filename, s, s1, s2);
		}
		else if (response == 2)
		{
			cout << "Enter the city or number to search : "; cin >> search;
			cout << ProcessTXT(filename, search) << endl;

		}
		else if (response == 3)
			PrintTXT(filename);
		cout << "Continue? (y) : "; cin >> yorn;
	} while (yorn == 'y' || yorn == 'Y');
	return 0;
}