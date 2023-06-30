#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include "class2.h"
using namespace sf;
using namespace std;

namespace addfun
{
	int WordCounter(string start_string)
	{
		char buk = 'w';
		int i = 0;
		int count = 1;

		while (buk != '\0')
		{
			buk = start_string[i];
			i += 1;
			if (buk == ' ') { count += 1; }
		}
		return count;
	};


	void StringSlayer(string* wordlist, string StartString)
	{
		string wordy = "";
		char buk = 'w';
		int i = 0;
		int n = 0;
		while (buk != '\0')
		{
			buk = StartString[i];
			if (buk != ' ') { wordy = wordy + buk; }
			if (buk == ' ')
			{
				wordlist[n] = wordy;
				n += 1;
				wordy = "";
			}
			i += 1;
			buk = StartString[i];
		}
		wordlist[n] = wordy;

	}
}