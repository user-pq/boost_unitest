#include "alarm_list.h"

#include <list>

int main()
{
    sort_timer_lst timer_lst;
    util_timer *timer1 = new util_timer();
    timer1->expire = time(nullptr) + 10;
    timer_lst.add_timer(timer1);
    timer_lst.clear();
    return 0;
}