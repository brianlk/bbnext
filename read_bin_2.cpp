#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
  int x;
  streampos pos;
  ifstream infile;
  infile.open("silly.dat", ios::binary | ios::in);
  infile.seekp(243, ios::beg); // move 243 bytes into the file
  infile.read(&x, sizeof(x));
  pos = infile.tellg();
  cout << "The file pointer is now at location " << pos << endl;
  infile.seekp(0,ios::end); // seek to the end of the file
  infile.seekp(-10, ios::cur); // back up 10 bytes
  infile.close();
}
