#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <windows.h>

// #define NRM  "\x1B[0m"					// THIS SECTION IS FOR UNIX
// #define DRK  "\x1B[30m"
// #define RED  "\x1B[31m"
// #define GRN  "\x1B[32m"
// #define YEL  "\x1B[33m"
// #define BLU  "\x1B[34m"
// #define PRP  "\x1B[35m"
// #define TRQ  "\x1B[36m"

// #define DRK_ "\x1B[40m"
// #define RED_ "\x1B[41m"
// #define GRN_ "\x1B[42m"
// #define YEL_ "\x1B[43m"
// #define BLU_ "\x1B[44m"
// #define PRP_ "\x1B[45m"
// #define TRQ_ "\x1B[46m"  //turquoise
// #define WHT_ "\x1B[47m"
// #define NRM_ "\x1B[49m"

// #define BLD  "\x1B[1m"
// #define dim  "\x1B[37m" //dimmed a little
// #define DIM  "\x1B[2m"  //dimmed a lot (can be combined with 'dim')
// #define ITC  "\x1B[3m"  
// #define ULN  "\x1B[4m"  //underlined
// #define FLCK "\x1B[5m"  //flickering
// #define HLT  "\x1B[7m"  //highlighted
// #define INV  "\x1B[8m"  
// #define STRK "\x1B[9m"  //striking out

using namespace std;

const HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
/*
First argument for SetConsoleTextAttribute (HANDLE h, int i) function.
i is a binary number; additive
Text colors:
0 = black
1 = blue
2 = green
3 = green + blue
4 = red
5 = purple (r+b)
6 = yellow (r+g)
7 = dimmer white (r+g+b)
8 = gray
9 = gray + blue
14 = yellow white (gray + yellow)
15 = normal white
(fill in the blanks yourself)

Background colors:
16 = blue
32 = green
64 = red
128 = gray
240 = white
(again, you can fill in the blanks yourself)
*/




bool is_int(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
    	it++;
    return !s.empty() && it == s.end();
}


void introduction ()
{
	cout << endl;
	cout << "************************************************" << endl;
	cout << "To get a new array press RETURN.                " << endl;
	cout << "To change initial values type 'change'.         " << endl;
	cout << "To exit the programm type 'exit' or something.  " << endl;
	cout << "************************************************" << endl << endl;
}

int word_checker (string input_word)
{
	if (!input_word.length())
		return 0;
	else if (input_word == "change")
		return 1;
	else if (input_word == "exit")
		return 2;
	else if (input_word == "1")
		return 10;
	else if (input_word == "2")
		return 11;
	else
		return -1;
}

void get_num (string& sbuff, int& quantity)
{
	cout << "Set initial number of notes: ";
	getline (cin , sbuff);
	while (!is_int(sbuff))
	{
		cout << "This is not a number. Please try again: ";
		getline (cin , sbuff);
	}
	quantity = atof (sbuff.c_str());
}

void get_instrument (string& instrument_name)
{
	cout << "Choose an instrument, by typing it's number." << endl;
	cout << "Instruments available:" << endl;
	cout << "1 - flute (test)" << endl;
	cout << "2 - bass (test)" << endl;

	getline (cin, instrument_name);
	while (word_checker(instrument_name) < 10)
	{
		cout << "Unexpected input, try again:" << endl;
		getline (cin, instrument_name);
	}
}

void all_set ()
{
	cout << endl;
	cout << "Parameters are set." << endl;
	cout << "To get a set of notes press RETURN " << endl;
	cout << "To change parameters type 'change'." << endl;
	cout << endl;
}


void flute_note_format(int k)
{
	switch (k)
	{
		case -2:
		case -1:
			SetConsoleTextAttribute (h, 6);
			cout << k;
			SetConsoleTextAttribute (h, 15);
			break;
		case 0:
		case 1:
			SetConsoleTextAttribute (h, 6);
			cout << " " << k;
			SetConsoleTextAttribute (h, 15);
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			SetConsoleTextAttribute (h, 2);
			cout << " " << k;
			SetConsoleTextAttribute (h, 15);
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			SetConsoleTextAttribute (h, 1);
			cout << " " << k;
			SetConsoleTextAttribute (h, 15);
			break;
		case 10:
			SetConsoleTextAttribute (h, 1);
			cout << k;
			SetConsoleTextAttribute (h, 15);
			break;
		case 11:
		case 12:
		case 13:
			SetConsoleTextAttribute (h, 4);
			cout << k;
			SetConsoleTextAttribute (h, 15);
			break;
	}
}

void flute_sheet (int& quantity)
{
	int flute_note;
	int scale_notes = 16; // the number of notes in the scale

	srand (clock());

	for (int i = 0; i < quantity - 1; i++)
	{
		flute_note = (rand() % scale_notes) - 2;
		flute_note_format (flute_note);
		cout << " __ ";
	}
	flute_note = (rand() % scale_notes) - 2;
	flute_note_format (flute_note);

	cout << endl << endl;

	SetConsoleTextAttribute (h, 15);
}

void bass_note_format (int string_num, int fret) // work in process
{
	int coloring = 0;  // 1 = 7, 2 = 6, 3 = 128, 4 = 112, 5 = 240, 6 = 224, 7 = 96

	switch (fret)
	{
		case -1:
			cout << "__";
			break;
		case 0:

	}

	switch
}

void bass_sheet (int& quantity) // work in process
{
	int bass_note;
	int string_num;
	int base_fret = rand() % 20;
	vector <vector<int>> bass_sheet (4, vector<int>(quantity, -1));

	for (auto& row : bass_sheet)
	{
		for (auto& col : row)
			cout << col;
		cout << endl;
	}

	SetConsoleTextAttribute (h, 240);
	cout << "Base fret = " << base_fret << endl;
	SetConsoleTextAttribute (h, 15);

	for (int i = 0; i < quantity; i++)
	{
		bass_note = base_fret + rand() % 21;
		while (bass_note > 20 || bass_note < 0)
			bass_note = base_fret + rand() % 21;

		string_num = rand() % 4;

	}

}

void sheet (string instrument_name, int quantity)
{
	switch (word_checker(instrument_name))
	{
		//flute
		case 10:
			flute_sheet (quantity);
			break;	

		//bass
		case 11:
			bass_sheet(quantity);
			break;
	}
	// if (word_checker(instrument_name, "flute"))
	// {
	// 	int buff;
	// 	srand (clock());
	// 	for (int i = 0 ; i < quantity - 1 ; i++)
	// 	{
	// 		buff = (rand() % 16) - 2;
	// 		flute_note (buff);
	// 		cout << NRM << " __ ";
	// 	}
	// 	buff = (rand() % 16) - 2;
	// 	flute_note (buff);
	// 	cout << NRM << endl;
	// }
}

int main ()
{
	int quantity;
	string instrument_name, sbuff;
	pair <string , int> cht;

	introduction ();

	get_instrument(instrument_name);

	get_num(sbuff, quantity);

	all_set();

	getline(cin, sbuff);
	

	while(int i = 1)
	{
		switch (word_checker(sbuff))
		{
			case 0:
				sheet (instrument_name, quantity);
				getline(cin, sbuff);
				break;
			case 1:
				get_instrument(instrument_name);
			 	get_num(sbuff, quantity);
				getline(cin, sbuff);
			 	break;
			 case 2:
			 	i = 0;
			 	break;
			 default:
			 	cout << "this is not an available command, try again:" << endl;
			 	getline (cin, sbuff);
			 	break;
		}
	}


	return (0);
}