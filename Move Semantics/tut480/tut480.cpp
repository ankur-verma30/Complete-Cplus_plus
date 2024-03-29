#include <iostream>
#include "boxcontainer.h"
using namespace std;
//the code is not compiling 

void populate_box(BoxContainer<int> &box, int modifier)
{
    for (size_t i{0}; i < 20; ++i)
    {
        box.add((i + 1) * modifier);
    }
}

BoxContainer<int> make_box(int modifier)
{
    BoxContainer<int> local_int_box(20);
    populate_box(local_int_box, modifier);
    return local_int_box;
}

int main()
{

    BoxContainer<int> box_array[2];

    cout << "--------" << endl;

    for (size_t i{0}; i < 2; ++i)
    {
        box_array[i] = make_box(i + 1); // Copy assignment operator called at each iteration
                                        //  We're copying data from the temporary and
                                        //  throwing the temporary away (with data)
    }

    cout << "--------" << endl;

    return 0;
}