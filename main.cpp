#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

void findEmails(const string& text) {
    regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    sregex_iterator it(text.begin(), text.end(), emailPattern);
    sregex_iterator end;

    cout << "\nEmails found:\n";
    for (; it != end; ++it) {
        cout << it->str() << endl;
    }
}

void findDates(const string& text) {
    regex datePattern(R"(\b\d{2}/\d{2}/\d{4}\b)");
    sregex_iterator it(text.begin(), text.end(), datePattern);
    sregex_iterator end;

    cout << "\nDates found:\n";
    for (; it != end; ++it) {
        cout << it->str() << endl;
    }
}

void findPhones(const string& text) {
    regex phonePattern(R"(\+?\d{10,13})");
    sregex_iterator it(text.begin(), text.end(), phonePattern);
    sregex_iterator end;

    cout << "\nPhone numbers found:\n";
    for (; it != end; ++it) {
        cout << it->str() << endl;
    }
}

int main() {
    ifstream file("sample.txt");
    string line, text;

    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    while (getline(file, line)) {
        text += line + "\n";
    }

    file.close();

    findEmails(text);
    findDates(text);
    findPhones(text);

    return 0;
}