#include <iostream>
#include <string>
#include "Wrapper.h"

using namespace std;

int main() {
	dasAuto* yourCar;
	string decision;
	int choice = 0;
	cout << "Hello! Let's configure your auto. If you want to exit press any key" << endl;
	cout << "If you want an auto with diesel engine and Tiptronic transmission, enter 1" << endl;
	cout << "If you want an auto with petrol engine and S-Tronic transmission, enter 2" << endl;
	cin >> choice;
	if (choice == 1) {
		yourCar = new DieselEngine();
		yourCar = new TiptronicTransmission(yourCar);
	}
	else if (choice == 2) {
		yourCar = new PetrolEngine();
		yourCar = new STronicTransmission(yourCar);
	}
	else goto Exit;
	cout << "Which type of the body of the car do you want?" << endl;
	cout << "Enter 1 if it is a coupe" << endl;
	cout << "Enter 2 if if is a liftback" << endl;
	cin >> choice;
	if (choice == 1) yourCar = new Avant(yourCar);
	else if (choice == 2) yourCar = new SStyle(yourCar);
	else goto Exit;
	cout << "Choose the interior. 1 -- White, 2 -- Dark" << endl;
	cin >> choice;
	if(choice == 1) yourCar = new WhiteInterior(yourCar);
	else if(choice == 2) yourCar = new DarkInterior(yourCar);
	else goto Exit;
	cout << "Do you want to add an Embedded Computer: yes or no?" << endl;
	cin.ignore();
	getline(cin, decision);
	if (decision == "yes") yourCar = new EmbeddedÑomputer(yourCar);
	cout << "Do you want to add a Driver Assistant System: yes or no?" << endl;
	getline(cin, decision);
	if (decision == "yes") yourCar = new DriverAssistanceSystem(yourCar);
	cout << "Your car configured. All the options and add-ons:" << endl;
	cout << yourCar->getDescription() << endl;
	cout << "Horsepower -- " << yourCar->power() << endl;
	cout << "It costs " << yourCar->price() << "$ without taxes" << endl;
	cout << "And with taxes it costs " << 341.40 + yourCar->price() << "$" << endl;
	delete yourCar;
Exit:
	return 0;
}