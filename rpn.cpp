#include "rpn.h"
#include <stack>
#include <cmath>
using namespace std;

bool isznak(char a) { return a == '+' || a == '-' || a == '*' || a == '/' || a == '^'; }

double calculateRPN(const string& s) {
	stack<double> a;
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			if (!isznak(s[i]))
				a.push(s[i] - '0');
			else
			{
				double z;
				double x = a.top(); a.pop();
				double y = a.top(); a.pop();
				switch (s[i])
				{
				case '+':
					z = x + y;
					break;
				case '-':
					z = y - x;
					break;
				case '*':
					z = x * y;
					break;
				case '/':
					z = y / x;
					break;
				case '^':
					z = pow(y, x);
					break;
				}
				a.push(z);
			}
		}
		i++;
	}
	return a.top();
}
