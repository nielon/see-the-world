#include "properties.h"
#include <fstream>
#include <iostream>
using namespace std;

bool IsCommentChar(char c)
{
    switch(c) {
    case COMMENT_CHAR:
        return true;
    default:
        return false;
    }
}

bool AnalyseLine(const string & cline, string & key, string & value)
{
    string line = cline;
    if (line.empty())
        return false;
    string::size_type pos;
    pos = line.find(COMMENT_CHAR);
    //去掉前置空白字符，去掉 # 及其后面的内容
    string::size_type uns = line.find_first_not_of(" \t");
    line = line.substr(uns, pos);
    //去掉尾部的空白字符
    line.erase(line.find_last_not_of(" ") + 1);
    
    if ((pos = line.find('=')) == string::npos)
        return false;  // 没有=号
        
    key = line.substr(0, pos);
    //去掉尾部的空白字符
    key.erase(key.find_last_not_of(" ") + 1);
    value = line.substr(pos + 1);
    //去掉前面的空白字符
    value.erase(0, value.find_first_not_of(" "));
    
    return true;
}

bool property::ReadConfig(const string & filename, map<string, string> & m)
{
    m.clear();
    ifstream infile(filename.c_str());
    if (!infile) {
        cerr << "file open error" << endl;
        return false;
    }
    string line, key, value;
    while (getline(infile, line)) {
        if (AnalyseLine(line, key, value)) {
            m[key] = value;
        }
    }
    infile.close();
    return true;
}

void property::PrintConfig(const map<string, string> & m)
{
    map<string, string>::const_iterator mite = m.begin();
    for (; mite != m.end(); ++mite) {
        cout << mite->first << "=" << mite->second << endl;
    }

}
