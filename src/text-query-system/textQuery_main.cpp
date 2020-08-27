#include <iostream>
#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"

using namespace std;

int main()
{
    auto par = Paragraph{};
    string fileName = "";
    string search_word = "";

    int i = 1;

    cout << "Please enter file name: ";
    cin  >> fileName;
    cout << endl;

    while (search_word != ".")
    {
        cout << "Please enter a word to search for or '.' to quit: ";
        cin >> search_word;
        cout << endl;

        FileReader file = FileReader{fileName};
        file.readFileInto(par);
        auto[found, line_numbers] = par.contains(Word{search_word});

        if (found)
        {
            cout << "Word found: ";
            cout << "line " << line_numbers[i] << endl;
        }
        else{cout << "Word not found" << endl; return 0;}

            while ( i < line_numbers.size())
            {
                cout << "            line " << line_numbers[i] << endl;
                i++;
            }


    }

    return 0;
}
