#ifndef TESTUTILS_H
#define TESTUTILS_H

namespace TestUtils
{
    constexpr static const double EPSILON = 1e-15;

    template<typename T>
    bool resultIsValid(T expected, T result, T epsilon)
    {
        if(fabs(expected) < epsilon && fabs(result) < epsilon) { // 0/0 case
            return true;
        }

        return fabs(result/expected - 1) <= epsilon;
    }
};

#endif // TESTUTILS_H
