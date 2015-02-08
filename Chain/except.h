#ifndef EXCEPT_H
#define EXCEPT_H

#include <new>

//数组越界异常
class OutOfBounds {
   public:
      OutOfBounds() {}
};

//内存不够异常
class NoMem {
   public:
      NoMem() {}
};

void my_new_handler()
{
   throw NoMem();
}

//捕获C++标准异常，设置为自己的异常
std::new_handler Old_Handler = std::set_new_handler(my_new_handler);


#endif // EXCEPT_H
