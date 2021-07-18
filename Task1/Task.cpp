#include <iostream>
#include <string>
using namespace std;

struct Pizza
{
	string appelation;
	double diameter;
	double weight;
	string manufactcity;
};

void input(Pizza* newpizza)
{
	getline(cin, newpizza->appelation);
	cin >> newpizza->diameter;
	cin >> newpizza->weight;
	cin.ignore();
	getline(cin, newpizza->manufactcity);
}

void output(Pizza* newpizza)
{
	cout << "Appelation: " << newpizza->appelation << " \n";
	cout << "Diameter: " << newpizza->diameter << " \n";
	cout << "Weight: " << newpizza->weight << " \n";
	cout << "City of the manufacturer: " << newpizza->manufactcity << " \n";
	cout << endl;
}

int main(void) 
{
	Pizza* newpizza = new Pizza;
	input(newpizza);
	output(newpizza);
	delete newpizza;
}
