#ifndef LST_TIMER
#define LST_TIMER
#include <time.h>
#include <netinet/in.h>
#include <iostream>

const int BUFFER_SIZE = 64;

class util_timer;

struct client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[BUFFER_SIZE];
    util_timer* timer;
};

//定时器类
class util_timer
{
public:
    util_timer() : prev(nullptr), next(nullptr){}

public:
    void(*cb_func)(client_data*); //回调函数

public:
    client_data* user_data; // 回调函数处理的客户数据
    util_timer * prev;
    util_timer * next;
    time_t expire;          // 到期时间
};

//定时器排序类 双向链表 有一个头节点和一个尾节点
class sort_timer_lst
{
public:
    sort_timer_lst() : head(nullptr), tail(nullptr) {}
    ~sort_timer_lst() 
    {
        clear();
    }

    void clear();

    //将目标定时器添加到链表中
    void add_timer(util_timer* timer);

    //定时器调整
    void adjust_timer(util_timer* timer);

private:
    void add_timer(util_timer* timer, util_timer* head);

private:
    util_timer* head;
    util_timer* tail;
};




#endif