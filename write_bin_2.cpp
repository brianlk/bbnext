#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
  private:
    int number;
    string name;
    float gpa;
  public:
    Student(int n, const string& s, float g) {
        number = n;
        name = s;
        gpa = g;
    };
    void save(ofstream& of);
    void load(ifstream& inf);
};


void Student::save(ofstream& of)
{
  of.write((char*)&number, sizeof(number));
}

void Student::load(ifstream& inf)
{
  inf.read((char*)&number, sizeof(number));
  cout << number <<endl;
}


int main()
{
  Student me(10001 , "12345", 2.3);
// ofstream myfile;
  ifstream myfile;
 myfile.open("silly.dat", ios::binary | ios::out);
 // me.save(myfile);
    me.load(myfile);
  myfile.close();
  return(0);
}

