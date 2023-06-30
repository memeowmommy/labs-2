#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
using namespace sf;
using namespace std;

namespace addfun
{
	int WordCounter(string start_string);
	void StringSlayer(string* wordlist, string StartString);
}
namespace ClassAnimatedText
{
	class AnimatedText
	{
	private:
		string m_cur_string = "";
		string m_my_string = "";
		int m_duration = 0;
		float m_sm_duration;
		int m_i = 0;

		void Error(int x) { exit(x); }

	public:
		AnimatedText(string my_string, int duration)
		{
			m_my_string = my_string;
			m_duration = duration;
			m_sm_duration = round((float(m_duration) / (m_my_string.length())) * 1000000000) / 1000000000;
		}
		~AnimatedText(){};

		string GetMyString() { return m_my_string; }
		int Get_I()	{return m_i;}

		string GetText()
		{
			m_cur_string += m_my_string[m_i];
			m_i += 1;
			if (m_i > m_my_string.length()) { Error(0); }
			return m_cur_string;
		}
		
		void SleepMode()	{this_thread::sleep_for(chrono::nanoseconds(int(m_sm_duration * 1000000000)));}
	};
}
