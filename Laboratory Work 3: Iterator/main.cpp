#include "Deque.h"
#include <ctime> // ����� ���� ���������� �������


int main() {
    Deque<double> dq;
    Deque<char> dva;
    Iterator<Deque<char>> check = dva.begin();
    cout << "Iterator empty() check with a spurious deque \"dva\" -- " << check.empty() << endl; // ����� ���������
    dva.insertfirst('a'); // ������� ������ � ��������� ����
    check = dva.begin(); // ���������������� ��������
    cout << "Iterator empty() check with a spurious deque \"dva\" with added element -- " << check.empty() << endl;
    using iterator = Iterator<Deque<double>>; 
    cout << "Deque filling: " << endl;
    dq.insertlast(3); // ������� � �����
    dq.insertfirst(2); // ������� � ������
    dq.insertfirst(1);
    dq.insertlast(4);
    dq.insertlast(5);
    dq.insertfirst(0);
    cout << "Deque: " << endl;
    dq.show(); // ����� �� ����� � ������� �������
    iterator empty = dq.begin();
    cout << "Emptiness check (iterator) -- " << empty.empty() << endl; // ����� ���������
    cout << "Emptiness check (method) -- " << dq.isempty() << endl; // ����� �����
    cout << endl << endl << endl << endl;


    cout << "Creating and filling another deque (dk) for swapping" << endl;
    Deque<double> dk;
    cin >> dk; // ���������� ������ ���� � ������� �������������� ��������� �����
    cout << "Deque dq before swapping: " << endl << dq << endl; // ����� �� ����� � ������� �������������� ��������� ������
    dq.swap(&dk);
    cout << "Deque dq after swapping: " << endl;
    dq.show();
    cout << "Deque dk after swapping: " << endl << dk << endl << endl << endl;
    cout << endl << endl << endl << endl;
    
    
    iterator beginiter = dq.begin(); // ����� ����� � ������ ������������� ��������� �� ������ � �����
    iterator enditer = dq.end();
    cout << "beginiter begin: " << beginiter->data << endl; // ����� ������� �������� ����������
    cout << "Here is the print of deque's filling with postfix ++ operator" << endl;
    for (beginiter; beginiter != NULL; beginiter++) { // ����� ����� ���������� �����������
        cout << beginiter->data << " ";
    }
    cout << endl << "Last element using enditer: " << enditer->data << endl; // ����� ���������� �������� ���������� enditer
    cout << endl << endl << endl << endl;


    cout << "Let's add and delete an element in deque (dk)" << endl;
    cout << "Deque before:" << endl;
    dk.show();
    enditer = dk.end(); // ����� ��������������� �������� �� �����, �� ��� ��-�� ����� ����
    cout << "Inserting random number before the pre-last position (on the pre-pre-last exactly) using prefix -- on enditer iterator " << endl;
    srand(time(0)); // ��� ������� ���������� �����
    dk.insert(--enditer, rand()); // ������� ��������� ����� ����������, �������, ���� � ���� �������� �� ����-������������� �������,
    cout << "Deque after:" << endl; // ����� ���������� �������� �� ������������� �������
    dk.show();
    cout << "Now erasing newly added element" << endl; // ������ �������� ����� ������������ ��������
    cout << "What to erase: " << (--enditer)->data << endl; // �����, ��� ������ �� ������� ����� �����
    dk.erase(enditer); // ���� ��������
    cout << "Deque after:" << endl;
    dk.show(); // ����� ����, ����� ��������, ��� �� ������ �������
    cout << endl << endl << endl << endl;


    cout << "Now let's erase everything but first and last element in deque dq" << endl; // ������� ������ � ��������� �������� � ����
    beginiter = dq.begin();
    enditer = dq.end();
    cout << "Deque before:" << endl << dq << endl;
    dk.erase(++beginiter, enditer); // ����� �������� �� ������� �������� �� ���������� (�� �������)
    cout << "Deque after:" << endl;
    dq.show();
    cout << endl << endl;
    
    cout << "Erasing all items except the last one in deque dk" << endl;
    cout << "Deque before:" << endl << dk << endl;
    dk.erase((dk.begin())++, dk.end()); // ����� ������� �� ����� ���������� ��������
    cout << "Deque after:" << endl;
    dk.show();
    return 0;
}