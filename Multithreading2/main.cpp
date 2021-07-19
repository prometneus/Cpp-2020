#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>

std::mutex writing_mutex; // Объявление мьютекса для блокировки записи
void write (std::string str); // Прототип функции записи

// Я совершенно не понимаю смысла разбиения считываемой строки на слова. Какая разница, как печатать,
// если для сохранения порядка текста (чтобы слова из одного и другого документа не перемешивались)
// при печати, поток занимает мьютекс и не позволяет второму потоку писать в файл? Мне нужно разбить
// на слова только чтобы разбить на слова (просто из-за задания)? Или есть какой-то смысл разбиения?
// С разбиением на слова цикл while внутри else выглядел бы как-то так:
//while(getline(file, buffer)) { // То есть тот же цикл
//    if (i < n) {
//        stringstream sep; // Но создаётся объект stringstream, как cin, только берёт данные из строки
//        sep << buffer;
//        string another_buffer; // Буффер для хранения отдельных слов
//        while (sep >> another_buffer) { // Кидает в буффер по словам, так как пробел уже не слово
//            result += another_buffer + " "; // Перебрасываем в итог, разделяя слова пробелами
//        }
//        result += "\n"; // Добавляем символ переноса строки
//        i++;
//    }
//    }

void read(std::string filename, int n) { // Функция считывания
    std::ifstream file(filename);
    std::string result, buffer;
    int i = 0;
    if (!file) { // Если файл не открылся
        writing_mutex.lock();
        std::cout << "Unable to open a file " << filename << std::endl;
        writing_mutex.unlock();
    } else { // Если открылся
        while(getline(file, buffer)) { // Считываем построчно
            if (i < n) { // Проверяем, удовлетворяет ли порядковый номер строки количеству строк
                result += buffer + "\n"; // Конкатенция строк + символ перехода на новую строку
                i++;
            } else break;
        }
        write(result); // Вызов функции записи в файл
    }
    file.close(); // Закрытие файла
}

 void write(const std::string str) { // Функция записи в файл
    std::ofstream file;
    std::cout << "Writing started" << std::endl;
    writing_mutex.lock(); // Блокируем мьютекс, чтобы несколько потоков не писали одновременно
    file.open("Answer.txt", std::ios::app); // Связываем поток вывода и название файла
    file << str; // std::ios::app позволяет открыть файл на ДОзапись, а не запись с нуля
    file.close(); // Закрываем файл
    std::cout<< "Writing finished" << std::endl;
    writing_mutex.unlock(); // Разблокируем мьютекс
}

int main() {
    int n, m = 0;
    std::cout << "Enter amount of files: ";
    std::cin >> n;
    std::string* filenames = new std::string[n];
    std::cout << "Enter the paths to all " << n << " files" << std::endl;
    for (int i = 0; i < n; i++) { // Здесь осуществляется ввод путей к файлам
        std::cin >> filenames[i];
    }
    std::cout << "Enter amount of strings to read: ";
    std::cin >> m;
    std::thread* thread_arr = new std::thread[n];
    for (int i = 0; i < n; i++) { // Здесь создаются потоки для каждого из файлов3
        std::cout << filenames[i] << std::endl;
        thread_arr[i] = std::thread([&filenames, i, m]() {read(filenames[i], m); });
    }
    thread_arr[i].join();
    delete[] thread_arr; // Использовался new, значит нужно дополнительно очистить память
}
