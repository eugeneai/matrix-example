#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main (int __argc, char **__argv) {
  std::vector<std::string> args(__argv, __argv+__argc);
  cout << "Hello World!" << endl;
  return 0;
}
