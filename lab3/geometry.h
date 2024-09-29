class Point
{
private:
    int x;
    int y;

public:
    // Constructor declaration
    Point(int xx = 0, int yy = 0);

    // Inline getter functions; these functions are simple enough to do them inside of geometry.h
    int getX() const { return x; }
    int getY() const { return y; }

    // Inline setter functions
    void setX(int xx) { x = xx; }
    void setY(int yy) { y = yy; }
};

/**
 * this class also allows dynamic resizing of an array of points
 * the size of the array should be exactly how many elements it contains
 */
class PointArray
{
    // declare all the private members
private:
    Point *points;
    int size;

public:
    // constructors

    // default constructor
    PointArray();
    // regular constructor
    PointArray(const Point points[], const int size);
    // copy constructor
    PointArray(const PointArray &pv);

    // destructor
    ~PointArray();

    // resizing operation
    void resize(int n);

    // get size
    const int getSize() const;

    // get the elements inside
    /**
     * Why do we need const and non-const versions of get?
     *
     * If we had only const accessor functions, then even in the case where we want to modify the PointerArray,
     *  we would be returning a const pointer. To allow returning a non-const
pointer in situations where we might want one, we need non-const versions of these functions, as well.
     */
    Point *get(const int position);
    const Point *get(const int position) const;

    // add to the end of array
    void push_back(const Point &p);

    // insert at a specified position
    void insert(const int position, const Point &p);

    // remove at specified position
    void remove(const int pos);

    // clear everything in this object
    void clear();
};