
#include <iostream>
#include "Cliente.h"
using namespace std;

int main()
{
	int op;
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0;
	cout << "Ingrese nit: ";
	getline(cin, nit);
	cout << "Ingrese nombres: ";
	getline(cin, nombres);
	cout << "Ingrese apellidos: ";
	getline(cin, apellidos);
	cout << "Ingrese direccion: ";
	getline(cin, direccion);
	cout << "Ingrese telefono: ";
	cin >> telefono;
	cin.ignore();
	cout << "Ingrese fecha_nacimiento: ";
	getline(cin, fecha_nacimiento);

	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	c.crear();
	c.leer();

	system("pause");
	return 0;
}

// abajo codigo defectuoso
/*
#include <iostream>
#include "Cliente.h"
using namespace std;

int main()
{
	int op;
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
	do {
		cout << "----------Seleccione Una de las opciones----------" << endl;
		cout << "1) Ingresar Registro " << endl;
		cout << "2) Mostrar Registros " << endl;
		cout << "3) Eliminar Registro " << endl;
		cout << "4) Salir " << endl;
		cin >> op;

		switch (op) {
		case 1:

			cout << "Ingrese nit: ";
			getline(cin, nit);
			cout << "Ingrese nombres: ";
			getline(cin, nombres);
			cout << "Ingrese apellidos: ";
			getline(cin, apellidos);
			cout << "Ingrese direccion: ";
			getline(cin, direccion);
			cout << "Ingrese telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese fecha de nacimiento: ";
			cin >> fecha_nacimiento;


			c;
			c.crear();

			break;

		case 2:
		{
			Cliente c;
			c.leer();
		}
		break;

		case 3:
		{

		}
		break;

		case 4:
			break;
		}
	} while (op != 4);

	system("pause");
	return 0;

}*/