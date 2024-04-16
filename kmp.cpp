#include "kmp.h"
#include <vector>
#include <string>
using namespace std;

vector<int> getIndices(const string& temp, const string& s) {
	vector<int> ans;
	vector<int> prefix(temp.size());
	prefix[0] = 0; int k = 0;
	for (int i = 1; i < temp.size(); ++i)
	{
		while ((k > 0) && (temp[i] != temp[k]))
			k = prefix[k - 1];
		if (temp[i] == temp[k])
			k++;
		prefix[i] = k;
	}
	k = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		while ((k > 0) && (temp[k] != s[i]))
			k = prefix[k - 1];
		if (temp[k] == s[i])
			k++;
		if (k == temp.size())
			ans.push_back(i - temp.size() + 1);
	}
    return ans;
}
