// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
    paragraph.push_back(line);//adds line into a paragraph
}

tuple<bool, vector<int>> Paragraph::contains(const Word& search_word) const
{
    int c = 0;//Iterating variable
    tuple<bool, vector<int>> t1;//Declaring a tuple
    bool& check = get<0>(t1);//Creating a bool variable to hold tuple bool
    vector<int>& linez = get<1>(t1);//Creating a vector to hold tuple vector

    //Checks if paragraph contains the search word
    //Then search word is then stored in a vector
    for ( int i = 0; i < paragraph.size(); i++)
    {
        for (int j = 0; j < paragraph[i].words.size(); j++)
        {
            if(paragraph[i].contains(search_word))
            {
                c++;
            }
        }

        if(paragraph[i].contains(search_word))
        {
            linez.push_back(i+1);
        }
    }

    if ( c == 0 )
    {
        check= false;
    }
    else
    {
        check = true;
    }

    return t1;
}
