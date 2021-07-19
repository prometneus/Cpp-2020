#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

class MainCharacter {
private:
    int wallet, farms;
    std::mutex mut;
public:
    MainCharacter() {
        wallet = 0;
        farms = 0;
    }

    void change(bool TF) { // Функция изменения состояния
        mut.lock(); // Блокируем поток
        if (TF) { // Если true, то есть заработана монетка, она добавляется
            this->wallet++; // Увеличиваем количество денег в кошельке
            std::cout << "+MONEY" << std::endl;
        } else { // Если же false, то есть монеток уже 15, то заработка не происходит, а начинается строительство фермы
            this->wallet -= 15; // Производим списание
            std::cout << "Buying a farm" << std::endl;
        }
        mut.unlock();
    }

    void earn() { // Для монеток
        while (true) { // Это бесконечный цикл для заработка монеток. Он реально бесконечный. Останавливается фермами.
            std::this_thread::sleep_for(std::chrono::seconds(3)); // Монетка зарабатывается раз в три секунды
            std::cout << "Money earned, now in wallet: " << wallet + 1<< std::endl;
            this->change(true); // Забрасываем информацию в функцию изменения состояния
        }
    }

    void building() { // Строительство
        while (this->farms < 5) { // Пока не будет построено 5 ферм. Этот же цикл остановит бесконечный цикл в earn
            if (this->farms < 5 and this->wallet >= 15) { // Если ферм меньше 5 и больше или равно 15 монеток
                std::cout << "Building a farm" << std::endl;
                this->change(false); // Обращаемся к функции изменения, которая спишет деньги за ферму
                std::this_thread::sleep_for(std::chrono::seconds(60)); // Время строительства фермы -- минута
                this->farms++; // Увеличиваем количество ферм
                std::cout << "Construction completed" << std::endl;
                if (farms == 1) std::cout << "Now you have " << farms << " farm" << std::endl;
                if (farms > 1) std::cout << "Now you have " << farms << " farms" << std::endl;
            }
        }
    }
};

int main() {
    MainCharacter persona;
    std::thread thread4money([&]() { persona.earn(); });
    thread4money.detach();
    std::thread thread4farms([&]() { persona.building(); });
    thread4farms.join();
}
