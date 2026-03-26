#include <iostream>
#include <string>

int main() {
    std::string nickname;
    int menu = 0;

    std::cout << "이름을 입력하세요: ";
    std::cin >> nickname;
    std::cout << "환영합니다, " << nickname << "님!" << std::endl;

    while (true) {
        std::cout << "\n========= 메뉴 =========" << std::endl;
        std::cout << "1. 전투 입장" << std::endl;
        std::cout << "2. 스텟창" << std::endl;
        std::cout << "3. 게임 종료" << std::endl;
        std::cout << "선택: ";
        std::cin >> menu;

        switch (menu) {
        case 1:
        {
            std::cout << "전투에 입장합니다." << std::endl;
            break;
        }

        case 2:
        {
            std::cout << "스텟창을 엽니다." << std::endl;
            break;
        }

        case 3:
        {
            std::cout << "게임을 종료합니다." << std::endl;
            return 0;
        }

        default:
        {
            std::cout << "잘못된 입력입니다." << std::endl;
            break;
        }
        }
    };
}