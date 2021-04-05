#ifndef CAF_H_
#define CAF_H_
//constant and function
#include<map>
#include<string>
#include<cmath>
#include<math.h>
using std::string;
using std::map;
map<string,float> constant;

void addConstant()
{
	constant["pi"] = 4 * atan(1);
	constant["e"] = exp(1);

}

#endif
