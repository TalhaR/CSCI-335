#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int multiplication_driver(int argc, char **argv) {
  //Please place all functionality in here instead of the main.
  //Feel free to make any functions or objects you wish, as long as we only call this function.
  fstream dimesions_file{argv[1]};  

  long int a = 50 * 10;
  long int b = 10 * 40;
  long int c = 40 * 30;
  long int d = 30 * 5;
  
  cout << (50 * 10 * 40) + (40 * 30 * 5) << "\n";
}

int main(int argc, char **argv) {
    if (argc != 2) {
		cout << "Usage: " << argv[0] << "<dimensions_file>" << endl;
		return 0;
    }

    multiplication_driver(argc, argv);

    return 0;
}