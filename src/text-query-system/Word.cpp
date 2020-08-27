// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string& word): word_{word}
{
    int c = 0;//counter variable used to check if word_ contains special characters only
    word_size = word_.size();
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	for (int i = 0; i < word_size; i++)
    {
        if (isblank(word_[i])) throw WordContainsSpace{};//Throws the exception if word_ has a blank space
        if (!isalnum(word_[i])){c++;}//Checks if word_[i] is a special character
    }

	if (word_.empty() || c == word_size) throw WordContainsNoLetters{};//Checks if word_ contains letters

	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows two Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    for( int i = 0 ; i < word_size; i++)
    {
        //Checks if the words being compared contain any special characters
        //and if case is ignored
        if (isalnum(word_[i]) && isalnum(rhs.word_[i]) && word_[i] != tolower(rhs.word_[i]))
		{
		   return false;
		}
    }
    return true;
}

bool Word::isQueryable() const
{
    //checks if the length of the word is atleast 3
    if ( word_size >= min_size ){return true;}
	return false;
}

