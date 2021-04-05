#ifndef STRINGRECOGNITION_H_
#define STRINGRECOGNITION_H_
//字符串识别大师
#include<string>
#include<map>
#include"linkStack.hpp"
#define SYMBOL_AMOUNT 6
#define NUM 1
#define LETTER 2
#define SYMBOL 3
#define DOT 4
#define SPACE 5
#define NONE_TYPE 0
using std::string;
using std::map;

namespace calculator{
	const char symbols[SYMBOL_AMOUNT] = { '(',')','+','-','*','/' };
	const char first_priority[2] = "^";
	const char second_priority[3] = "*/";
	const char third_priority[3] = "+-";
	bool isFirstPriority(const char c)
	{
		for (int i = 0; first_priority[i] != '\0'; i++)
			if (c == first_priority[i]) return true;
		return false;
	}
	bool isSecondPriority(const char c)
	{
		for (int i = 0; second_priority[i] != '\0'; i++)
			if (c == second_priority[i]) return true;
		return false;
	}
	bool isThirdPriority(const char c)
	{
		for (int i = 0; third_priority[i] != '\0'; i++)
			if (c == third_priority[i]) return true;
		return false;
	}
	int arithmeticPriority(const char c)
	{
		if (isThirdPriority(c)) return 3;
		else if (isSecondPriority(c)) return 2;
		else if (isFirstPriority(c)) return 1;
		return 0;
	}
	bool isNum(const char c) { return c >= '0' && c <= '9' ? true : false; }
	bool isNum(string str) { return isNum(str[str.length() - 1]); }

	bool isDot(const char c) { return c == '.'; }
	bool isLetter(const char c)
	{
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? true : false;
	}
	bool isSymbol(const char c)
	{
		for (int i = 0; i < SYMBOL_AMOUNT; i++)
		{
			if (c == symbols[i])return true;
		}
		return false;
	}
	bool isBracket(const char c) { return c == '(' || c == ')'; }
	bool isSpace(const char c) { return c == ' '; }
	void checkType(const char c, int& t)
	{
		if (isNum(c)) t = NUM;
		else if (isLetter(c)) t = LETTER;
		else if (isSymbol(c)) t = SYMBOL;
		else if (isDot(c)) t = DOT;
		else if (isSpace(c))t = SPACE;
		else t = NONE_TYPE;
	}

	bool checkLetter(string str, map<string, float> constant)
	{
		if (constant.find(str) != constant.end()) return true;
		return false;
	}

	bool changeLetter(string& str, map<string, float> constant)
	{
		if (checkLetter(str, constant))
		{
			str = std::to_string(constant[str]);
			return true;
		}
		return false;
	}

	bool checkExpresstion(string* strs, int& count)
	{
		for (int i = count - 1; i > 0; i--)
		{
			char c = strs[i][0];
			char next_c = strs[i - 1][0];
			if (isNum(c))
			{
				if (isNum(next_c) || next_c==')') return false;
				if (next_c == '-')
				{
					strs[i].insert(0, "-");
					strs[i - 1] = "+";
				}
			}
			else if (isSymbol(c))
			{
				if (!isBracket(c))
				{
					if (i == count - 1) return false;
					if (!isBracket(next_c) && isSymbol(next_c)) return false;
				}
				else if (next_c == '(') return false;
			}
		}
		return true;
	}

	bool split(string s, string* strs, int& count, map<string, float> constant)
	{
		int len = s.length();
		int t = SPACE;
		count = 0;
		int have_dot = 0;
		string str = "";
		for (int i = 0; i < len; i++)
		{
			int t0;
			checkType(s[i], t0);
			if (t0 == NONE_TYPE) return false;
			else if (t0 == SPACE)
			{
				if (t == DOT) return false;
				else if (t != SPACE)
				{
					if (str != "")
					{
						if (t == LETTER)
							if (!changeLetter(str, constant)) return false;
						strs[count] = str;
						count++;
						have_dot = 0;
						str = "";
					}
				}
			}
			else if (t0 == NUM)
			{
				if (t == NUM || t == DOT || t == SPACE || t == SYMBOL) str += s[i];
				else return false;
			}
			else if (t0 == LETTER)
			{
				if (t == LETTER || t == SYMBOL || t == SPACE) str += s[i];
				else return false;
			}
			else if (t0 == SYMBOL)
			{
				if (str != "")
				{
					if (t == LETTER)
						if (!changeLetter(str, constant)) return false;
					strs[count] = str;
					count++;
				}
				string s0 = "a";
				s0[0] = s[i];
				strs[count] = s0;
				count++;
				have_dot = 0;
				str = "";
			}
			else if (t0 == DOT)
			{
				if (have_dot || t != NUM) return false;
				else
				{
					str += s[i];
					have_dot = 1;
				}
			}
			t = t0;
		}
		if (str != "") {
			if (t == LETTER)
				if (!changeLetter(str, constant)) return false;
			strs[count] = str;
			count++;
		}
		return true;
	}
}

#endif
