#include "calculator.h"
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

int getPriority(char c)
{
    switch (c)
    {
    case '^':
        return 0;
    case '~':
        return 1;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 3;
    case '(':
        return 4;
    default:
        throw exception();
    }
}

double calculateRPN(istream& in) 
{
    stack<double> s;
    while (in.peek() != EOF && in.peek() != '\n')
    {
        char c = in.peek();
        if (isdigit(c))
        {
            double d;
            in >> d;
            s.push(d);
        }
        else
        {
            double x, y;
            in.get();
            switch (c)
            {
            case '+':
                if (s.size() < 2)
                    throw exception();
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                s.push(x + y);
                break;
            case '-':
                if (s.size() < 2)
                    throw exception();
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                s.push(x - y);
                break;
            case '*':
                if (s.size() < 2)
                    throw exception();
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                s.push(x * y);
                break;
            case '/':
                if (s.size() < 2)
                    throw exception();
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                s.push(x / y);
                break;
            case '^':
                if (s.size() < 2)
                    throw exception();
                y = s.top(); s.pop();
                x = s.top(); s.pop();
                s.push(pow(x, y));
                break;
            case '~':
                if (s.size() < 1)
                    throw exception();
                x = s.top(); s.pop();
                s.push(-x);
                break;
            case ' ':
                break;
            default:
                throw exception();
            }
        }
    }
    if (s.size() > 1)
        throw exception();
    return s.top();
}

double ConvertionToRPN(istream& in)
{
    int lastBracket = 0;
    bool state = false;
    stringstream out;
    stack<char> s;
    while (in.peek() != EOF && in.peek() != '\n')
    {
        char c = in.peek();
        if (isdigit(c))
        {
            if (state)
                throw exception();
            double d;
            in >> d;
            out << d << ' ';
            state = true;
        }
        else
        {
            in.get();
            switch (c)
            {
            case ' ':
                break;
            case '^':
            case '*':
            case '/':
            case '+':
                if (!state)
                    throw exception();
                while (!s.empty() && getPriority(s.top()) <= getPriority(c))
                {
                    out << s.top() << ' ';
                    s.pop();
                }
                s.push(c);
                state = false;
                break;
            case '(':
                if (state)
                    throw exception();
                lastBracket = in.tellg();
                s.push(c);
                break;
            case ')':
                if (!state)
                    throw exception();
                while (!s.empty() && s.top() != '(')
                {
                    out << s.top() << ' ';
                    s.pop();
                }
                if (s.empty())
                    throw exception();
                s.pop();
                break;
            case '-':
                if (!state)
                    c = '~';
                while (!s.empty() && getPriority(s.top()) <= getPriority(c))
                {
                    out << s.top() << ' ';
                    s.pop();
                }
                s.push(c);
                state = false;
                break;
            default:
                throw exception();
            }
        }
    }
    if (!state)
        throw exception();
    while (!s.empty())
    {
        if (s.top() == '(')
            throw exception();
        out << s.top() << ' ';
        s.pop();
    }
    return calculateRPN(out);
}

double calculate(string const& in)
{
    stringstream str(in);
    return ConvertionToRPN(str);
}