#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    // ifstream data_file;
    // data_file.open("\\file"); // insert file link
    // string input_line;
    // while(getline(data_file, input_line)) {
    //     cout << input_line << endl;
    // }

    // istringstream strm;
    // strm.str("December 19, 2023");
    // string month;
    // int day;
    // string comma;
    // int year;
    // strm >> month >> day >> comma >> year;
    // cout << strm.str() << endl;

    // ostringstream strm;
    // string month = "December";
    // int day = 19;
    // int year = 2023;
    // strm << month << " " << day << ", " << year;
    // cout << strm.str() << endl;

    char ch = 'x';
    cout.put(ch);

    fstream myFile("abc.txt", ios::out);
    myFile.write((char*)&ch, sizeof(ch));
    myFile.close();

    fstream myFile2("abc.txt", ios::in);
    myFile2.read((char*)&ch, sizeof(ch));
    myFile2.close();

    return 0;
}

int main(int argc, char* argv[]) {
    int key = 3;
    int file_count = 0;
    ifstream in_file;
    ofstream out_file;
}