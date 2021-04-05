#ifndef BIGNUMCALCULATOR_H_
#define BIGNUMCALCULATOR_H_
#include<string>
#include<iostream>
#include<cmath>
using std::cout;
using std::endl;

class bgCalculator
{
private:
	std::string reverse(std::string str);
	int find_dot(std::string str);
	void add_zeros(std::string& str,int amount);
public:
	bgCalculator(){}
	std::string addition(std::string num1, std::string num2);
	std::string substraction(std::string num1, std::string num2);
};

std::string bgCalculator::reverse(std::string str)
{
	int len = str.length();
	std::string new_str = "";
	for (int i = len - 1; i >= 0; i--)
	{
		new_str += str[i];
	}
	return new_str;
}

void bgCalculator::add_zeros(std::string& str, int amount) { for (int i = 0; i < amount; i++) str += "0"; }

int bgCalculator::find_dot(std::string str)
{
	int len = str.length();
	for (int i = 0; i < len; i++) if (str[i] == '.') return i;
	return -1;
}

std::string bgCalculator::addition(std::string num1, std::string num2)
{
	int neg=0;
	if (num1[0] == '-' && num2[0] == '-') neg = 1;
	else if (num1[0] == '-') return substraction(num2, num1);
	else if (num2[0] == '-') return substraction(num1, num2);
	int dot1 = find_dot(num1);
	int dot2 = find_dot(num2);
	int len1 = num1.length();
	int len2 = num2.length();
	bool is_decimal = true;
	if (dot1 > 0 && dot2 > 0)//add_zeros
	{
		int dot_len1 = len1 - dot1;
		int dot_len2 = len2 - dot2;
		if (dot_len1 > dot_len2)
		{
			add_zeros(num2, dot_len1 - dot_len2);
		}
		else
		{
			add_zeros(num1, dot_len2 - dot_len1);
		}
	}
	else if (dot1 > 0 && dot2 < 0)
	{
		num2 += ".";
		add_zeros(num2, len1 - dot1  -1);
		dot2 = len2; 
	}
	else if (dot1 < 0 && dot2>0)
	{
		num1 += ".";
		add_zeros(num1, len2 - dot2 -1);
		dot1 = len1;
	}
	else is_decimal = false;
	std::string decimal_result = is_decimal ? addition(num1.substr(dot1+1), num2.substr(dot2+1)) : "";
	num2 = num2.substr(0, dot2);
	num1 = num1.substr(0, dot1);
	int small_len = len1 < len2 ? len1 : len2;
	int areas = small_len / 9 + 1;
	std::string result = "";
	int i;
	int add_num = 0;
	if(is_decimal)
	{
		if (decimal_result.length() > num1.length() - dot1-1)
		{
			decimal_result = "." + decimal_result.substr(1);
			add_num = 1;
		}
		else decimal_result = "." + decimal_result;
	}
	num1 = reverse(num1);
	num2 = reverse(num2);
	for (i = 0; i < areas; i++)
	{
		int area_num1 = atoi(reverse(num1.substr(i * 9, 9)).c_str());
		int area_num2 = atoi(reverse(num2.substr(i * 9, 9)).c_str());
		int area_result = area_num1 + area_num2 + add_num;
		int n = pow(10, 9);
		add_num = area_result / n;
		area_result %= n;
		result += reverse(std::to_string(area_result));
	}
	if(neg) result += "-";
	return reverse(result)+decimal_result;
}
std::string bgCalculator::substraction(std::string num1, std::string num2)
{
	return "";
}
#endif