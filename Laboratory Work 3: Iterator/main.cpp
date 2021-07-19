#include "Deque.h"
#include <ctime> // Чисто ради рандомчика добавил


int main() {
    Deque<double> dq;
    Deque<char> dva;
    Iterator<Deque<char>> check = dva.begin();
    cout << "Iterator empty() check with a spurious deque \"dva\" -- " << check.empty() << endl; // Через итераторы
    dva.insertfirst('a'); // Добавим символ в фальшивую деку
    check = dva.begin(); // Реинициализируем итератор
    cout << "Iterator empty() check with a spurious deque \"dva\" with added element -- " << check.empty() << endl;
    using iterator = Iterator<Deque<double>>; 
    cout << "Deque filling: " << endl;
    dq.insertlast(3); // Вставка в конец
    dq.insertfirst(2); // Вставка в начало
    dq.insertfirst(1);
    dq.insertlast(4);
    dq.insertlast(5);
    dq.insertfirst(0);
    cout << "Deque: " << endl;
    dq.show(); // Вывод на экран с помощью функции
    iterator empty = dq.begin();
    cout << "Emptiness check (iterator) -- " << empty.empty() << endl; // Через итераторы
    cout << "Emptiness check (method) -- " << dq.isempty() << endl; // Через метод
    cout << endl << endl << endl << endl;


    cout << "Creating and filling another deque (dk) for swapping" << endl;
    Deque<double> dk;
    cin >> dk; // Заполнение второй деки с помощью перегруженного оператора ввода
    cout << "Deque dq before swapping: " << endl << dq << endl; // Вывод на экран с помощью перегруженного оператора вывода
    dq.swap(&dk);
    cout << "Deque dq after swapping: " << endl;
    dq.show();
    cout << "Deque dk after swapping: " << endl << dk << endl << endl << endl;
    cout << endl << endl << endl << endl;
    
    
    iterator beginiter = dq.begin(); // После свапа я заново инициализирую итераторы на начало и конец
    iterator enditer = dq.end();
    cout << "beginiter begin: " << beginiter->data << endl; // Вывод первого элемента контейнера
    cout << "Here is the print of deque's filling with postfix ++ operator" << endl;
    for (beginiter; beginiter != NULL; beginiter++) { // Вывод всего контейнера итераторами
        cout << beginiter->data << " ";
    }
    cout << endl << "Last element using enditer: " << enditer->data << endl; // Вывод последнего элемента итератором enditer
    cout << endl << endl << endl << endl;


    cout << "Let's add and delete an element in deque (dk)" << endl;
    cout << "Deque before:" << endl;
    dk.show();
    enditer = dk.end(); // Снова реинициализирую итератор на конец, но уже из-за смены дека
    cout << "Inserting random number before the pre-last position (on the pre-pre-last exactly) using prefix -- on enditer iterator " << endl;
    srand(time(0)); // Для вставки случайного числа
    dk.insert(--enditer, rand()); // Элемент вставится перед итератором, поэтому, если я хочу вставить на пред-предпоследнюю позицию,
    cout << "Deque after:" << endl; // нужно установить итератор на предпоследнюю позицию
    dk.show();
    cout << "Now erasing newly added element" << endl; // Теперь удаление этого добавленного элемента
    cout << "What to erase: " << (--enditer)->data << endl; // Вывод, что именно за элемент будет удалён
    dk.erase(enditer); // Само удаление
    cout << "Deque after:" << endl;
    dk.show(); // Вывод дека, чтобы показать, что всё прошло успешно
    cout << endl << endl << endl << endl;


    cout << "Now let's erase everything but first and last element in deque dq" << endl; // Оставим первый и последний элементы в деке
    beginiter = dq.begin();
    enditer = dq.end();
    cout << "Deque before:" << endl << dq << endl;
    dk.erase(++beginiter, enditer); // Будет почищено от первого элемента до последнего (не включая)
    cout << "Deque after:" << endl;
    dq.show();
    cout << endl << endl;
    
    cout << "Erasing all items except the last one in deque dk" << endl;
    cout << "Deque before:" << endl << dk << endl;
    dk.erase((dk.begin())++, dk.end()); // Будет удалено всё кроме последнего элемента
    cout << "Deque after:" << endl;
    dk.show();
    return 0;
}