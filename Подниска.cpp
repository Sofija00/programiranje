#include <iostream>
#include <string>

using namespace std;

int main() {
  string n, m;
  cin >> n >> m;
  size_t poz = n.find(m);

  if (poz != string::npos)
    cout << poz << endl;
  else
    cout << -1 << endl;

  return 0;}
