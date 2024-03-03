#include <iostream>

int main(void)
{
    char name[100];
    char phone[100];

    std::cout << "이름이 뭐예요? ";
    std::cin >> name;

    std::cout << "전화번호 뭐예요? ";
    std::cin >> phone;

    std::cout << "당신의 이름은 " << name << "이고, 전화번호는 " << phone << "이군요.." << std::endl;

    return 0;
}