#include <iostream>

int main(void)
{
    int num;

    std::cout << "구구단을 외자 구구단을 외자. 몇 단? ";
    std::cin >> num;

    for (int i = 1; i <= 9; i++)
    {
        std::cout << num << "*" << i << "=" << num * i << std::endl;
    }

    return 0;
}