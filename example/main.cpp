#include <idpool/idpool.hpp>

#include <iostream>

auto main() -> int
{
    idp::idpool_t pool;

    std::cout << pool.next() << std::endl; // 0
    std::cout << pool.next() << std::endl; // 1

    pool.release(1);
    std::cout << pool.next() << std::endl; // 1
    std::cout << pool.next() << std::endl; // 2

    pool.release(0);
    std::cout << pool.next() << std::endl; // 0
    std::cout << pool.next() << std::endl; // 3

    pool.reset();

    return 0;
}
