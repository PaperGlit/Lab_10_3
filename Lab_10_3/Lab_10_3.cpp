#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void CreateTXT(char* fname)
{
	ofstream fout(fname, ios_base::app);
	string s, s1, s2;
	cin.get();
	cin.sync();
	cout << "Starting city name : "; getline(cin, s);
	fout << s << " - ";
	cout << "Destination city name : "; getline(cin, s1);
	fout << s1 << " ";
	cout << "Route number : "; getline(cin, s2);
	fout << "(" << s2 << ")" << endl;
}

void ProcessTXT(char* fname, char* search)
{	
	ifstream fin(fname);
	int k = 0;
	char l[255];
	char* line = new char[255];
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
				cout << line << endl;
			}
			word = strtok_s(NULL, " ", &next_word);
		}
	}
	if (k == 0)
		cout << "No results" << endl;
}

int main()
{
	int response;
	char yorn;
	char search[100];
	char filename[11] = "Routes.txt";
	do {
		cout << "1 - Create a new route; 2 - Search : "; cin >> response;
		if (response == 1)
			CreateTXT(filename);
		else if (response == 2)
		{
			cout << "Enter the city or number to search : "; cin >> search;
			ProcessTXT(filename, search);
		}
		cout << "Continue? (y) : "; cin >> yorn;
	} while (yorn == 'y' || yorn == 'Y');
	return 0;
}