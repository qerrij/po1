#ifndef KVADRAT_H
#define KVADRAT_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "kvadrat.h"
}

TEST(kvadratTest, tworoots) {

    double x1,x2;
    x1 = x2 = 0;
    if(kvadrat(1,3,-4,&x1,&x2) == 0){
        if((x1 == -4 && x2 == 1) || (x1 == 1 && x2 == -4))
            SUCCEED();
        else {
            FAIL();
        }
    }
    else{
        FAIL();
    }

}

TEST(kvadratTest, oneroot)
{
    double x1,x2;
    x1 = x2 = 0;
    if(kvadrat(1,-4,4,&x1,&x2) == 2)
    {
        if(x1 == 2 && x2 == 2)
            SUCCEED();
        else {
            FAIL();
        }
    }
    else{
        FAIL();
    }
}

TEST(kvadratTest, noroot)
{
    double x1,x2;
    x1 = x2 = 0;
    ASSERT_EQ(kvadrat(1,-5,9,&x1,&x2), 1);
}

TEST(kvadratTest, rational) {
    double x1,x2;
    if(kvadrat(2,4,-3,&x1,&x2) == 0)
    {
        ASSERT_NEAR(x1,0.58,0.01);
        ASSERT_NEAR(x2,-2.58,0.01);
    }
    else {
        FAIL();
    }
}

TEST(kvadratTest, num0) {
    double x1,x2;
    ASSERT_EQ(kvadrat(0,0,0,&x1,&x2), 3);
    ASSERT_EQ(kvadrat(0,0,1,&x1,&x2), 1);
    ASSERT_EQ(kvadrat(0,1,0,&x1,&x2), 2);
    if(x1 == 0 && x2 == 0)
        SUCCEED();
    ASSERT_EQ(kvadrat(1,0,0,&x1,&x2), 2);
    if(x1 == 0 && x2 == 0)
        SUCCEED();
}
#endif // KVADRAT_H
