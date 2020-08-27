// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size()
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size()
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}
//Exercise 2.1


//Exercise 2:Predicting the output

/*Line 4 will output the vector's size, which is the total number of elements that is currently on vec, meaning all the elements pushed on vec. Therefore since on the lines before line 4 there is no element on vec it will output vec: Size: 0.
Line 5 will output the currently allowed storage, since there is no element and it is known that the capacity can be equal or greater than the vector size, this extra space it to allow growth of the vector without the need to reallocate on each insertion which means since the size is 0 , the capcity can be 0 or greater by 3 or 2 numbers
therefore the output may be  capacity: 0.*/

//EX2:The difference between vector's size and its capacity

/*Vector's size is the total number of elements that is currently on the declared vector which is vec.
While the vector's capacity is the total amount of space that a vector is currently using or memory space occupied by the vector. It can be equal or greater than the vector's size to avoid reallotions on each insertions.
capacity() it returns the size of allocate storage, expressed in terms of elements.*/

//EX2:Why the capacity grows as it does

/*Capacity returns the size of storage space which is reserve for elements of the vector
Usually the capacity size increases by the factor of 2 or 1.5 each time depending on the compiler,
It can be equal or greater than the vector size, when the size of the vector increases, the capacity assumes more than one element may be added.
The more elements are in the vector, there more it assumes you need space and it usually grows exponentially or by a factor of 2 or less
*/
