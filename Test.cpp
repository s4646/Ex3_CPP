#include "doctest.h"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

TEST_CASE("GOOD INPUT")
{
    SUBCASE("ADDITION")
    {
        vector<double> all4 = {1,1,1,1,
                               1,1,1,1,
                               1,1,1,1,
                               1,1,1,1};
        Matrix all4x4_1{all4, 4, 4};
        
        for (int i = 1; i <= 20; i++)
        {
            vector<double> allI = {(double)i,(double)i,(double)i,(double)i, 
                                   (double)i,(double)i,(double)i,(double)i,
                                   (double)i,(double)i,(double)i,(double)i,
                                   (double)i,(double)i,(double)i,(double)i};
            Matrix allIxI{allI,4,4};
            CHECK(allIxI == all4x4_1);
            if(i%2 == 0)
            {
                all4x4_1 = all4x4_1++;
            }
            else
            {
                ++all4x4_1;
            }
        }
        
        Matrix all4x4_2{all4, 4, 4};
        for (int i = 0; i < 100; i++)
        {
            if (i%2 == 0)
            {
                CHECK_NOTHROW(all4x4_2 + i);
            }
            else
            {
                CHECK_NOTHROW(i + all4x4_2);
            }
        }
        
        vector<double> x4 = {1.33, 0, 0, 1.33,
                             0, 1.33, 1.33, 0,
                             0, 1.33, 1.33, 0,
                             1.33, 0, 0, 1.33};
        Matrix x4_1{x4, 4, 4};
        Matrix x4_2{x4, 4, 4}; 
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
        
        constants2x2+=5;
        CHECK(constants2x2 == Matrix{vector<double>{8.14,7.71,6.41,6.61}, 2, 2});
    }

    SUBCASE("SUBSTRACTION")
    {
        vector<double> all4 = {1,1,1,1,
                               1,1,1,1,
                               1,1,1,1,
                               1,1,1,1};
        Matrix all4x4_1{all4, 4, 4};
        
        for (int i = 1; i > 20; i--)
        {
             vector<double> allI = {(double)i,(double)i,(double)i,(double)i, 
                                   (double)i,(double)i,(double)i,(double)i,
                                   (double)i,(double)i,(double)i,(double)i,
                                   (double)i,(double)i,(double)i,(double)i};
            Matrix allIxI{allI,4,4};
            CHECK(allIxI == all4x4_1);
            if(i%2 == 0)
            {
                 all4x4_1 = all4x4_1--;
            }
            else
            {
                --all4x4_1;
            }
        }
        
        Matrix all4x4_2{all4, 4, 4};
        for (int i = 0; i < 100; i++)
        {
            if (i%2 == 0)
            {
                CHECK_NOTHROW(all4x4_2 + i);
            }
            else
            {
                CHECK_NOTHROW(i + all4x4_2);
            }
        }
        
        vector<double> x4 = {1.33, 0, 0, 1.33,
                             0, 1.33, 1.33, 0,
                             0, 1.33, 1.33, 0,
                             1.33, 0, 0, 1.33};
        Matrix x4_1{x4, 4, 4};
        Matrix x4_2{x4, 4, 4}; 
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

        constants2x2-=5;
        CHECK(constants2x2 == Matrix{vector<double>{-2.14,-3.71,-4.41,-4.61}, 2, 2});
    }
    // SUBCASE("MULTIPLICATION")
    // {
    //     vector<double> identity =  {1,0,0,0, 
    //                                 0,1,0,0,
    //                                 0,0,1,0,
    //                                 0,0,0,1};
    //     for (int i = 1; i <= 20; i++)
    //     {
    //         vector<double> identityI = {(double)i,0,0,0, 
    //                                     0,(double)i,0,0,
    //                                     0,0,(double)i,0,
    //                                     0,0,0,(double)i};
    //         Matrix identityIxI{identity,4,4};
    //         if(i%2 == 0)
    //         {
    //             identityIxI*i;
    //         }
    //         else
    //         {
    //             i*identityIxI;
    //         }
    //         CHECK(identityIxI == Matrix{identityI,4,4});
    //     }

    //      vector<double> x4 = {1.33, 0, 0, 1.33,
    //                           0, 1.33, 1.33, 0,
    //                           0, 1.33, 1.33, 0,
    //                           1.33, 0, 0, 1.33};
    //     Matrix x4_1{x4, 4, 4};
    //     Matrix x4_2{x4, 4, 4};
    //     for (int i = 0; i < 15; i++)
    //     {
    //         if(i%2 == 0)
    //         {
    //             CHECK_NOTHROW(x4_1 * x4_2);
    //         }
    //         else
    //         {
    //             CHECK_NOTHROW(x4_2 * x4_1);
    //         }
    //     }
    // }
    // SUBCASE("DIVISION")
    // {
    //     vector<double> identity =  {1,0,0,0, 
    //                                 0,1,0,0,
    //                                 0,0,1,0,
    //                                 0,0,0,1};
    //     for (int i = 1; i <= 20; i++)
    //     {
    //         vector<double> identityI = {(double)i,0,0,0, 
    //                                     0,(double)i,0,0,
    //                                     0,0,(double)i,0,
    //                                     0,0,0,(double)i};
    //         Matrix identityIxI{identity,4,4};
    //         if(i%2 == 0)
    //         {
    //             identityIxI/i;
    //         }
    //         else
    //         {
    //             i/identityIxI;
    //         }
    //         CHECK(identityIxI == Matrix{identityI,4,4});
    //     }
    // }
}

TEST_CASE("BAD INPUT")
{
    vector<double> identity4 = {1,0,0,0, 
                                0,1,0,0,
                                0,0,1,0,
                                0,0,0,1};
    Matrix identity4x4{identity4, 4, 4};
        
    vector<double> identity3 = {1,0,0, 
                                0,1,0,
                                0,0,1};
    Matrix identity3x3{identity3, 3, 3};
    SUBCASE("ADDITION")
    {   
        CHECK_THROWS(identity3x3 + identity4x4);
        CHECK_THROWS(identity4x4 + identity3x3);
    }
    SUBCASE("SUBSTRACTION")
    {
        CHECK_THROWS(identity3x3 - identity4x4);
        CHECK_THROWS(identity4x4 - identity3x3);
        
    }
    SUBCASE("MULTIPLICATION")
    {
        CHECK_THROWS(identity3x3 * identity4x4);
        CHECK_THROWS(identity4x4 * identity3x3);
    }
    SUBCASE("DIVISION")
    {
        CHECK_THROWS(identity3x3/0);
        CHECK_THROWS(0/identity4x4);
    }
}