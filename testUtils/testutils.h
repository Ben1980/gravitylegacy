#ifndef TESTUTILS_H
#define TESTUTILS_H

namespace TestUtils
{
    const double EPSILON = 1e-15;
    const double GRAVITATIONAL_CONSTANT = 6.67408e-11;

    template<typename T>
    bool resultIsValid(T expected, T result, T epsilon)
    {
        return fabs(result/expected - 1) <= epsilon;
    }
};

#endif // TESTUTILS_H
