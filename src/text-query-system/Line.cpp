// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include<iostream>

Line::Line(const string& line)
{
    //Temporary manipulation variables
    string line_ = "";
    string word1 = "";

    line_ = line;
    int i = 0;//Iterating variable

    while(i < line_.size())
    {
        //Extracts words from line and store them into a vector
        if (!isalnum(line_[i]))
        {
            word1 = line_.substr(0,i);
            words.push_back(word1);

            //Removes special case characters
            while(!isalnum(line_[i+1]) && i<line_.size())
            {
                if (!isalnum(line_[i+1]))
                {
                    line_.erase(0,1);
                }
            }

            line_.erase(0,i+1);
            i = 0;
        }
        i++;
    }

    //For one word lines
    if(!line_.empty())
    {
        words.push_back(line_);
    }
    // Hint: some of string's member functions might come in handy here
    // for extracting words.
}

bool Line::contains(const Word& search_word) const
{
    int c = 0;//Iterarting counter variable
    int len = search_word.word_.size();
    //Temporary variables for manipulation
    string word2 = "";
    string word3 = "";
    vector<string> n;
    string word4 = search_word.word_;

    //Checks whether search word is queryable
    if (len < 3)
    {
        return false;
    }

    //Chages all the words to lowercase
    //I could have created a function responsible for this functionality
    //or make the words vector a Word type, since Word also has this functionality
    for (int i = 0; i < words.size(); i++)
    {
        for (int y = 0; y < word4.size(); y++)
        {
            word2.resize(y,char(tolower(word4[y])));
            word3.resize(y, char(tolower(words[i][y])));
        }

        n.push_back(word3);

        //Checks if line contains the search word
        if (word2 == n[i])
        {
            c++;
        }
    }

    //If the search word is not found in line c = 0
    if (c == 0)
    {
        return false;
    }
    return true;
}

