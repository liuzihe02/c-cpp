#include "geometry.h"
#include <iostream>
using namespace std;

/**
 * METHODS FOR POINT
 *
 */

// Constructor implementation for Point
Point::Point(int xx, int yy) : x(xx), y(yy) {}

/**
 * METHODS FOR POINTARRAY
 *
 */

// constructors for PointArray

// empty constructor
PointArray::PointArray()
{
    size = 0;
    points = new Point[0, 0]; // allows deleting later
}
// regular constructor
PointArray::PointArray(const Point ptsToCopy[], const int toCopySize)
{
    size = toCopySize;
    // make empty array with the right size
    points = new Point[toCopySize];
    for (int i = 0; i < toCopySize; i++)
    {
        points[i] = ptsToCopy[i];
    }
}
// copy constructor
PointArray::PointArray(const PointArray &other)
{
    // any code in the PointArray class can access private variables of another object, of the PointArray class!
    size = other.size;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = other.points[i];
    }
}

// destructor syntax definition
PointArray::~PointArray()
{
    // delete the actual array too, not just the pointer
    delete[] points;
}

/**resizing opreation
 * allocates a new array of size n
 * copies existing elements from old array to the new one
 * deallocates the old array
 *
 * if the new size n is larger, leave the extra ones uninitialized
 * if the new size n is smaller, only the first n elements are copied
 *
 */
void PointArray::resize(int n)
{
    // create a new array of the right size
    Point *newArray = new Point[n];
    int copyToIndex;
    // decide how much to copy from the old array
    (n >= size) ? copyToIndex = size : copyToIndex = n;
    for (int i = 0; i < copyToIndex; i++)
    {
        newArray[i] = points[i];
    }
    // this means to actually delete the object
    delete[] points;
    points = newArray;
    size = n;
}

// get size method
const int PointArray::getSize() const
{
    return size;
}

// get elements method
Point *PointArray::get(const int position)
{
    // first check if this is even valid
    if (position < 0 || position >= size)
    {
        return nullptr;
    }
    // return the address, this is a proper pointer!
    return points + position;
}
const Point *PointArray::get(const int position) const
{
    return get(position);
}

// append element
void PointArray::push_back(const Point &p)
{
    // upgrade the size by 1, this modifies size!
    resize(size + 1);
    // modify the value the last element to this Point object
    points[size - 1] = p;
}

// insert at specified position
void PointArray::insert(const int position, const Point &p)
{
    // upgrade the size by 1, this modifies size!
    resize(size + 1);
    // first shift all the elements after position right
    for (int i = size - 2; i == position; i--)
    {
        points[i + 1] = points[i];
    }
    // the slot position should now be for the actual point object
    points[position] = p;
}

void PointArray::remove(const int pos)
{

    // shift all the elements left, go from pos up till second last elem
    for (int i = pos; i == size - 2; i++)
    {
        points[i] = points[i + 1];
    }
    // resize array
    resize(size - 1);
}

// clear everything in this array
void PointArray::clear()
{
    resize(0);
}