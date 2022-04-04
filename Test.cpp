#include "doctest.h"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

TEST_CASE("GOOD INPUT")
{
    SUBCASE("ADDITION")
    {
        vector<double> identity4 = {1,0,0,0,
                                    0,1,0,0,
                                    0,0,1,0,
                                    0,0,0,1};
        Matrix identity4x4_1{identity4, 4, 4};
        
        for (int i = 1; i <= 20; i++)
        {
            vector<double> identityI = {(double)i,0,0,0, 
                                        0,(double)i,0,0,
                                        0,0,(double)i,0,
                                        0,0,0,(double)i};
            Matrix identityIxI{identityI,4,4};
            CHECK(identityIxI == identity4x4_1);
            if(i%2 == 0)
            {
                identity4x4_1++;
            }
            else
            {
                ++identity4x4_1;
            }
        }
        
        Matrix identity4x4_2{identity4, 4, 4};
        for (int i = 0; i < 100; i++)
        {
            if (i%2 == 0)
            {
                CHECK_NOTHROW(identity4x4_2 + i);
            }
            else
            {
                CHECK_NOTHROW(i + identity4x4_2);
            }
        }
        
        vector<double> x4 = {1.33, 0, 0, 1.33,
                             0, 1.33, 1.33, 0,
                             0, 1.33, 1.33, 0,
                             1.33, 0, 0, 1.33};
        Matrix x4_1{identity4, 4, 4};
        Matrix x4_2{identity4, 4, 4}; 
        for (int i = 0; i < 50; i++)
        {
            if(i%2 == 0)
            {
                CHECK_NOTHROW(x4_1 + x4_2);
            }
            else
            {
                CHECK_NOTHROW(x4_2 + x4_1);
            }
        }

        vector<double> const2x2 = {3.14, 2.71,
                                   1.41, 1.61};
        Matrix constants2x2{const2x2, 2, 2};
        
        CHECK(constants2x2 == +constants2x2);
    }

    SUBCASE("SUBSTRACTION")
    {
         vector<double> identity4 = {1,0,0,0,
                                    0,1,0,0,
                                    0,0,1,0,
                                    0,0,0,1};
        Matrix identity4x4_1{identity4, 4, 4};
        
        for (int i = 1; i <= 20; i++)
        {
            vector<double> identityI = {(double)i,0,0,0, 
                                        0,(double)i,0,0,
                                        0,0,(double)i,0,
                                        0,0,0,(double)i};
            Matrix identityIxI{identityI,4,4};
            CHECK(identityIxI == identity4x4_1);
            if(i%2 == 0)
            {
                identity4x4_1++;
            }
            else
            {
                ++identity4x4_1;
            }
        }
        
        Matrix identity4x4_2{identity4, 4, 4};
        for (int i = 0; i < 100; i++)
        {
            if (i%2 == 0)
            {
                CHECK_NOTHROW(identity4x4_2 + i);
            }
            else
            {
                CHECK_NOTHROW(i + identity4x4_2);
            }
        }
        
        vector<double> x4 = {1.33, 0, 0, 1.33,
                             0, 1.33, 1.33, 0,
                             0, 1.33, 1.33, 0,
                             1.33, 0, 0, 1.33};
        Matrix x4_1{identity4, 4, 4};
        Matrix x4_2{identity4, 4, 4}; 
        for (int i = 0; i < 50; i++)
        {
            if(i%2 == 0)
            {
                CHECK_NOTHROW(x4_1 + x4_2);
            }
            else
            {
                CHECK_NOTHROW(x4_2 + x4_1);
            }
        }
        
        vector<double> const2x2 = {3.14, 2.71,
                                   1.41, 1.61};
        vector<double> minusConst2x2 = {-3.14, -2.71,
                                        -1.41, -1.61};
        Matrix constants2x2{const2x2, 2, 2};
        Matrix minusConstants2x2{minusConst2x2, 2, 2};
        
        CHECK(constants2x2 == -constants2x2);
    }
    SUBCASE("MULTIPLICATION")
    {

    }
    SUBCASE("DIVISION")
    {

    }
}

TEST_CASE("BAD INPUT")
{
    SUBCASE("SUBCASE")
    {
        
    }
}