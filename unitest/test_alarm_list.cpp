#define BOOST_TEST_MODULE SortTimerListTestSuite

#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>

#define private public
#include "alarm_list.h"
#undef private

// bool init_unit_test()
// {
// 	return true;
// }

BOOST_AUTO_TEST_SUITE(SortTimerListTestSuite)

BOOST_AUTO_TEST_CASE(test_add_timer)
{
    sort_timer_lst timer_lst;
    BOOST_ASSERT(timer_lst.head == nullptr);
    BOOST_ASSERT(timer_lst.tail == nullptr);
    util_timer* timer1 = new util_timer();
    BOOST_ASSERT(timer1->prev == nullptr);
    BOOST_ASSERT(timer1->next == nullptr);
    timer1->expire = time(nullptr) + 10;
    timer_lst.add_timer(timer1);
    BOOST_CHECK_EQUAL(timer_lst.tail, timer1);
    BOOST_CHECK_EQUAL(timer_lst.head, timer1);

    util_timer* timer2 = new util_timer();
    timer2->expire = time(nullptr) + 20;
    timer_lst.add_timer(timer2);
    BOOST_CHECK_EQUAL(timer_lst.head, timer1);
    BOOST_CHECK_EQUAL(timer_lst.tail, timer2);
    BOOST_CHECK_EQUAL(timer1->next, timer2);
    BOOST_CHECK_EQUAL(timer2->prev, timer1);

    util_timer* timer3 = new util_timer();
    timer3->expire = time(nullptr) + 5;
    timer_lst.add_timer(timer3);
    BOOST_CHECK_EQUAL(timer_lst.head, timer3);
    BOOST_CHECK_EQUAL(timer_lst.tail, timer2);
    BOOST_CHECK_EQUAL(timer3->next, timer1);
    BOOST_CHECK_EQUAL(timer1->prev, timer3);
}

BOOST_AUTO_TEST_SUITE_END()