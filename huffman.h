#include <string>
#include <map>

struct node {
    char info;
    int freq;
    node* left, * right;
};

std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);
void encodedStr(node* root, std::string str, std::map<char, std::string>& huffmanCode);
