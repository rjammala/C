#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <regex>

using namespace std;

int main()
{
  map<string, int> mp;
  ifstream in("input.txt");
  if (in == NULL) {
    cerr << "Error reading file\n";
    exit(-1);
  }
  regex r{R"(\w+)"};
  string s;
  while (in >> s) {
    smatch matches;
    if (regex_search(s, matches, r))
    	mp[matches[0]]++;
  }
  for (map<string, int>::const_iterator it = mp.begin(); it != mp.end(); ++it)
    cout << it->first << " " << it->second << "\n";
  return 0;
}
