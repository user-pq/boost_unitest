#include "alarm_list.h"

void sort_timer_lst::add_timer(util_timer* timer)
{
    if(!timer)
    {
        std::cout << "timer is null" << std::endl;
        return ;
    }
    if(!head)
    {
        std::cout << "head is nullptr, timer is first elem" << std::endl;
        head = timer;
        tail = timer;
        return ;
    }

    // 如果插进来的超时时间小于头节点的，则当头节点
    if(timer->expire < head->expire)
    {
        timer->next = head;
        head->prev = timer;
        head = timer;
        return;
    }

    //否则函数重载
    add_timer(timer, head);
}

void sort_timer_lst::add_timer(util_timer* timer, util_timer* head)
{
    //找到第一个比要插入的数据的到期时间大的，然后插在其前面
    util_timer* tmp = head;
    while (tmp)
    {
        if(tmp->expire > timer->expire)
        {
            tmp->prev->next = timer;
            timer->next = tmp;
            tmp->prev = timer;
            break;
        }
        tmp = tmp->next;
    }
    //如果遍历完了任未找到 则是最大的 放到最后面
    tail->next = timer;
    timer->next = nullptr;
    timer->prev = tail;
    tail = timer;
}

void sort_timer_lst::adjust_timer(util_timer* timer)
{
    if(!timer)
    {
        return;
    }
    util_timer* tmp = timer->next;
    // 如果被调整的目标定时器是链表尾部 或者该定时器新的超时值任然小于其下一个定时器的超时值，则不用进行调整
    if(!tmp || timer->expire < tmp->expire)
    {
        return;
    }
    //如果是头节点 取出来重新插入
    if(timer == head)
    {
        head = head->next;
        head->prev = nullptr;
        timer->next = nullptr;
        add_timer(timer, head);
    }
    else 
    {
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        add_timer(timer, timer->next);
    }
}

void sort_timer_lst::clear()
{
    util_timer* temp = head;
    while(temp)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    head = tail = nullptr;
}