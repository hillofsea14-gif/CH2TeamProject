// Main.cpp

#include <iostream>
#include <string>

#include "Character.h"
#include "Monster.h"
#include "LevelComponent.h"
#include "Slime.h"

bool IsPlayerFast(Character& character, Monster& monster);   // [한길] 속도를 비교하여 선공 정하기.

void PAttack(Character& character, Monster& monster);    // [한길] 플레이어가 공격을 할 때

void MAttack(Character& character, Monster& monster);    // [한길] 몬스터가 공격할 때

void Battle(Character& character, Monster& monster);




bool IsPlayerFast(Character& character, Monster& monster)   // [한길] 속도를 비교하여 선공 정하기.
{
    int A = character.GetSpd();
    int B = monster.GetSpd();

    if (A > B)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// [한길] 만들다보니 attack() 함수에서 마지막에 상대편의 takeDamage()함수를 호출하는것이 더 좋아보여서 빼버림.

void PAttack(Character& character, Monster& monster)    // [한길] 플레이어가 공격을 할 때
{
    character.attack(character, monster);
    //monster.takeDamage(character);
}

void MAttack(Character& character, Monster& monster)    // [한길] 몬스터가 공격할 때
{
    monster.attack(character, monster);
    //character.takeDamage(monster);
}



void Battle(Character& character, Monster& monster)
{
    bool isplayerfast = IsPlayerFast(character, monster);

    std::cout << "몬스터 " << monster.GetName() << "와(과) 조우했습니다.\n\n";
    std::cout << "전투에 돌입합니다!!!" << std::endl;

    character.printcurrentstatus();
    monster.printcurrentstatus();

    if (isplayerfast == false)
    {
        std::cout << "상대가 더 빠릅니다. 공격권이 상대에게 넘어갑니다." << std::endl;
        MAttack(character, monster);
    }

    //[성윤] while (character.GetHP() > 0 && monster.GetHP() > 0) 이건 어떨까요
  // while (character.GetHP() != 0 && monster.GetHP() != 0) [한길] 수정완료!!!
    while (character.GetHP() > 0 && monster.GetHP() > 0)
    {
        std::cout << "당신의 행동을 선택하세요." << std::endl;
        std::cout << "1. 공격." << std::endl;
        std::cout << "2. 도망간다." << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            PAttack(character, monster);
        }
        else if (choice == 2)
        {
            std::cout << "당신은 도망쳤습니다..." << std::endl;
            break;
        }
        else
        {
            std::cout << "잘못된 입력입니다." << std::endl;
            continue;
        }

        std::cout << "상대가 공격합니다." << std::endl;
        MAttack(character, monster);

    }
    /* [한길] 레벨 시스템 변경으로 수정 필요.
    // [한길] 캐릭터 사망/  몬스터 사망시 경험치얻는 로직 레벨업 함수 추가.
    if (character.GetHP() == 0)
    {
        std::cout << "캐릭터가 사망하였습니다." << std::endl;
    }
    if (monster.GetHP() == 0)
    {
        std::cout << "몬스터가 사망하였습니다." << std::endl;
        std::cout << "전투 승리!!" << std::endl;
        std::cout << "경험치를 " << monster.GetGivingExp() << " 만큼 획득하였습니다." << std::endl;
        character.EarnExp(monster);   // 한길) 경험치 획득 추가.
        character.LevelUp();
    }
    */
}


//[성윤] 메인함수제작
int main() {
    std::string name;
    int menu = 0;

    LevelComponent* MyLevel = new LevelComponent(); //[상진]

    std::cout << "이름을 입력하세요: ";
    std::cin >> name;
    std::cout << "환영합니다, " << name << "님!" << std::endl;

    Character player(name);

    while (true) {
        std::cout << "\n========= 메뉴 =========" << std::endl;
        std::cout << "1. 전투 입장" << std::endl;
        std::cout << "2. 스텟창" << std::endl;
        std::cout << "3. 미정" << std::endl;
        std::cout << "4. 미정" << std::endl;
        std::cout << "5. 게임 종료" << std::endl;
        std::cout << "선택: ";
        std::cin >> menu;

        switch (menu) {
        case 1:
        {
            std::cout << "전투에 입장합니다." << std::endl;

            Slime monster;

            Battle(player, monster);

            break;
        }

        case 2:
        {
            std::cout << "스텟창을 엽니다." << std::endl;
            player.printcurrentstatus();
            break;
        }

        case 3:
        {
            std::cout << "미정입니다." << std::endl;
            break;
        }

        case 4:
        {
            std::cout << "미정입니다." << std::endl;
            break;
        }

        case 5:
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
    }
};





/* [한길] 3.26 Battle()의 if문과 while문 내용을 if-else if- else로수정.
if (0 < choice && choice < 3)
{
    switch (choice)    // if-else if-else 문으로 바꿔야하나...
    {
    case 1:
        PAttack(character, monster);
        break;
    case 2:
        std::cout << "당신은 도망쳤습니다..." << std::endl;
        break;
    }
}
*/
