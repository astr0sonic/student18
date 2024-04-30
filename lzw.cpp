#include "lzw.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> compress(const string& text)
{
    map<string, int> table;
    for (int i = 0; i < 256; i++)
        table[{ char(i) }] = i;

    string current = "";
    vector<int> compressed;
    for (char c : text)
    {
        string next = current + c;
        if (table.find(next) != table.end())
            current = next;
        else
        {
            compressed.push_back(table[current]);
            table[next] = table.size();
            current = { c };
        }
    }
    if (!current.empty())
        compressed.push_back(table[current]);
    return compressed;
}

string decompress(const vector<int>& compressed)
{
    map<int, string> table;
    for (int i = 0; i < 256; i++)
        table[i] = { char(i) };

    string decompressed = "";
    string current = table[compressed[0]];
    decompressed += current;
    for (int i = 1; i < compressed.size(); i++)
    {
        string previous = current;
        int code = compressed[i];
        if (table.find(code) != table.end())
            current = table[code];
        else
            current = previous + previous[0];
        decompressed += current;
        table[table.size()] = previous + current[0];
    }
    return decompressed;
}
