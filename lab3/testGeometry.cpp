#include <iostream>
#include "geometry.h"

#define MAX_TESTS 50
#define ASSERT(condition)                                                                      \
    do                                                                                         \
    {                                                                                          \
        if (!(condition))                                                                      \
        {                                                                                      \
            std::cout << "Assertion failed: " #condition " at line " << __LINE__ << std::endl; \
            return false;                                                                      \
        }                                                                                      \
    } while (0)

typedef bool (*TestFunction)();
struct Test
{
    const char *name;
    TestFunction function;
};

Test tests[MAX_TESTS];
int test_count = 0;

#define REGISTER_TEST(test_function)                                                    \
    do                                                                                  \
    {                                                                                   \
        if (test_count < MAX_TESTS)                                                     \
        {                                                                               \
            tests[test_count].name = #test_function;                                    \
            tests[test_count].function = test_function;                                 \
            test_count++;                                                               \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            std::cout << "Too many tests registered. Increase MAX_TESTS." << std::endl; \
        }                                                                               \
    } while (0)

bool testPointDefaultConstructor()
{
    Point p;
    ASSERT(p.getX() == 0);
    ASSERT(p.getY() == 0);
    return true;
}

bool testPointParameterizedConstructor()
{
    Point p(3, 4);
    ASSERT(p.getX() == 3);
    ASSERT(p.getY() == 4);
    return true;
}

bool testPointGetterSetter()
{
    Point p(1, 2);
    ASSERT(p.getX() == 1);
    ASSERT(p.getY() == 2);

    p.setX(5);
    p.setY(6);
    ASSERT(p.getX() == 5);
    ASSERT(p.getY() == 6);
    return true;
}

bool testPointArrayDefaultConstructor()
{
    PointArray pa;
    ASSERT(pa.getSize() == 0);
    return true;
}

bool testPointArrayConstructorWithArray()
{
    Point points[3] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    PointArray pa(points, 3);
    ASSERT(pa.getSize() == 3);
    ASSERT(pa.get(0)->getX() == 1);
    ASSERT(pa.get(0)->getY() == 2);
    ASSERT(pa.get(2)->getX() == 5);
    ASSERT(pa.get(2)->getY() == 6);
    return true;
}

bool testPointArrayCopyConstructor()
{
    Point points[2] = {Point(1, 2), Point(3, 4)};
    PointArray pa1(points, 2);
    PointArray pa2(pa1);
    ASSERT(pa2.getSize() == 2);
    ASSERT(pa2.get(0)->getX() == 1);
    ASSERT(pa2.get(0)->getY() == 2);
    ASSERT(pa2.get(1)->getX() == 3);
    ASSERT(pa2.get(1)->getY() == 4);
    return true;
}

bool testPointArrayPushBack()
{
    PointArray pa;
    pa.push_back(Point(1, 2));
    ASSERT(pa.getSize() == 1);
    ASSERT(pa.get(0)->getX() == 1);
    ASSERT(pa.get(0)->getY() == 2);

    pa.push_back(Point(3, 4));
    ASSERT(pa.getSize() == 2);
    ASSERT(pa.get(1)->getX() == 3);
    ASSERT(pa.get(1)->getY() == 4);
    return true;
}

bool testPointArrayInsert()
{
    PointArray pa;
    pa.push_back(Point(1, 2));
    pa.push_back(Point(5, 6));
    pa.insert(1, Point(3, 4));
    ASSERT(pa.getSize() == 3);
    ASSERT(pa.get(0)->getX() == 1);
    ASSERT(pa.get(0)->getY() == 2);
    ASSERT(pa.get(1)->getX() == 3);
    ASSERT(pa.get(1)->getY() == 4);
    ASSERT(pa.get(2)->getX() == 5);
    ASSERT(pa.get(2)->getY() == 6);
    return true;
}

bool testPointArrayRemove()
{
    Point points[3] = {Point(1, 2), Point(3, 4), Point(5, 6)};
    PointArray pa(points, 3);
    pa.remove(1);
    ASSERT(pa.getSize() == 2);
    ASSERT(pa.get(0)->getX() == 1);
    ASSERT(pa.get(0)->getY() == 2);
    ASSERT(pa.get(1)->getX() == 5);
    ASSERT(pa.get(1)->getY() == 6);
    return true;
}

bool testPointArrayClear()
{
    Point points[2] = {Point(1, 2), Point(3, 4)};
    PointArray pa(points, 2);
    pa.clear();
    ASSERT(pa.getSize() == 0);
    ASSERT(pa.get(0) == 0); // Assuming get() returns 0 (null) for invalid index
    return true;
}

bool testPointArrayGetInvalidIndex()
{
    PointArray pa;
    ASSERT(pa.get(0) == 0); // Assuming get() returns 0 (null) for invalid index
    ASSERT(pa.get(100) == 0);
    return true;
}

int main()
{
    REGISTER_TEST(testPointDefaultConstructor);
    REGISTER_TEST(testPointParameterizedConstructor);
    REGISTER_TEST(testPointGetterSetter);
    REGISTER_TEST(testPointArrayDefaultConstructor);
    REGISTER_TEST(testPointArrayConstructorWithArray);
    REGISTER_TEST(testPointArrayCopyConstructor);
    REGISTER_TEST(testPointArrayPushBack);
    REGISTER_TEST(testPointArrayInsert);
    REGISTER_TEST(testPointArrayRemove);
    REGISTER_TEST(testPointArrayClear);
    REGISTER_TEST(testPointArrayGetInvalidIndex);

    int passed = 0;
    int failed = 0;

    for (int i = 0; i < test_count; i++)
    {
        std::cout << "Running test: " << tests[i].name << "... ";
        if (tests[i].function())
        {
            std::cout << "PASSED" << std::endl;
            passed++;
        }
        else
        {
            std::cout << "FAILED" << std::endl;
            failed++;
        }
    }

    std::cout << "\nTest results:" << std::endl;
    std::cout << "Passed: " << passed << std::endl;
    std::cout << "Failed: " << failed << std::endl;

    return failed;
}