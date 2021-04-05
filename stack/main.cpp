#include<iostream>
#include<map>
#include"sqStack.hpp"
#include"linkStack.hpp"
#include"bigNumCalculator.hpp"
#include"stringRecognition.hpp"
#include"CAF.hpp"
#define STRS_LENGTH 100
using std::cout;
using std::endl;
using namespace calculator;

bgCalculator cal;
//std::map<string,float> constant;
string strs[STRS_LENGTH];

void print(string* s);

bool transform(string* strs,const int count,string *suffix_expression, int &suffix_count)
{
	linkStack<string>* transform_stack = new linkStack<string>;
	int priority = 4;
	//string s = "";
	//transform_stack->getTopStack(s);
	//cout << s << endl;
	//print(strs);
	//cout << count<<endl;
	for (int i = 0; i < count; i++)
	{
		if (isNum(strs[i]))
		{
			suffix_expression[suffix_count] = strs[i];
			suffix_count++;
		}
		else if (isBracket(strs[i][0]))
		{
			if (strs[i][0] == ')')
			{
				while (true)
				{
					string s = "";
					transform_stack->getTopStack(s);
					//cout << s << endl;
					if (transform_stack->pop(s))
					{
						if (s == "(") {
							transform_stack->pop(s);
							priority = atoi(s.c_str());
							break;
						}
						else
						{
							suffix_expression[suffix_count] = s;
							suffix_count++;
						}
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				transform_stack->push(std::to_string(priority));
				transform_stack->push(strs[i]);
				priority = 4;
				//cout << i << endl;
			}
		}
		else if (isSymbol(strs[i][0]))
		{
			//cout << strs[i] << endl;
			int p = arithmeticPriority(strs[i][0]);
			if (p <= priority)
			{
				transform_stack->push(strs[i]);
				priority = p;
			}
			else
			{
				string s = "";
				transform_stack->pop(s);
				suffix_expression[suffix_count] = s;
				suffix_count++;
				transform_stack->push(strs[i]);
			}
		}
	}
	while (true)
	{
		string s = "";
		if (transform_stack->pop(s))
		{
			suffix_expression[suffix_count] = s;
			suffix_count++;
		}
		else break;
	}
	return true;
}

void getTwoNum(linkStack<string> &result,float &ss1, float &ss2)
{
	string s1, s2;
	result.pop(s1);
	result.pop(s2);
	ss1 = atof(s1.c_str());
	ss2 = atof(s2.c_str());
}

void plus(linkStack<string> &result)
{
	if (result.length() == 1) return;
	float ss1, ss2;
	getTwoNum(result,ss1, ss2);
	result.push(std::to_string(ss1 + ss2));
}
void substract(linkStack<string> &result)
{
	float ss1, ss2;
	getTwoNum(result, ss1, ss2);
	result.push(std::to_string(ss1 - ss2));
}
void product(linkStack<string>& result)
{
	float ss1, ss2;
	getTwoNum(result, ss1, ss2);
	result.push(std::to_string(ss1 * ss2));
}
void division(linkStack<string>&result)
{
	float ss1, ss2;
	getTwoNum(result, ss1, ss2);
	if (ss1 == 0)
	{
		result.push("不能除以0");
		return;
	}
	result.push(std::to_string(ss2 / ss1));
}

string calculate(string* strs,const int count)
{
	linkStack<string> result_stack;
	for (int i = 0; i < count; i++)
	{
		if (isNum(strs[i])) result_stack.push(strs[i]);
		else
		{
			if (strs[i] == "+") plus(result_stack);
			else if (strs[i] == "-")substract(result_stack);
			else if (strs[i] == "*")product(result_stack);
			else if (strs[i] == "/") division(result_stack);
		}
	}
	string result="";
	result_stack.pop(result);
	return result;
}

void print(string* s)
{
	for (int n = 0; n < 20; n++)
	{
		cout << s[n] <<endl;
	}
}

int main()
{	
	addConstant();
	do {
		string str = "";
		int count = 0;
		cout << "-> ";
		std::getline(std::cin, str);
		if (!split(str, strs, count, constant))
		{
			cout << "输入错误！！！" << endl;
			continue;
		}
		if (!checkExpresstion(strs, count))
		{
			cout << "错误" << endl;
			continue;
		}
		string suffix_expression[STRS_LENGTH];
		int suffix_count = 0;
		transform(strs, count, suffix_expression, suffix_count);
		//print(suffix_expression);
		cout << calculate(suffix_expression, suffix_count)<<endl;

	} while (true);
	return 0;
}