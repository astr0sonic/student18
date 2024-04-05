#include "bracket.h"
#include <stack>

using namespace std;

bool checkBrackets(const std::string& s) {
    stringstream str(s);
    return task5(str);
}

bool task5(istream& f)
{
    stack<char> q; char x;
    while (!f.eof())
    {
        x = f.get();
        switch (x)
        {
        case '(':
        case '{':
        case '<':
        case '[':
            q.push(x);
            break;
        case ')':
            if (q.empty() || q.top() != '(')
                return false;
            q.pop();
            break;
        case '}':
            if (q.empty() || q.top() != '{')
                return false;
            q.pop();
            break;
        case ']':
            if (q.empty() || q.top() != '[')
                return false;
            q.pop();
            break;
        case '>':
            if (q.empty() || q.top() != '<')
                return false;
            q.pop();
            break;
        }
    }
    return q.empty();
}