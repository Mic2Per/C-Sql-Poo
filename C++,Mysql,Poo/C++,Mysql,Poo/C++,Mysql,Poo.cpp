
#include <iostream>
#include "Cliente.h"
using namespace std;

int main()
{
	int op;
	do {
		cout << "----------Seleccione Una de las opciones----------" << endl;
		cout << "1) Ingresar Registro " << endl;
		cout << "2) Mostrar Registros " << endl;
		cout << "3) Actualizar Registros " << endl;
		cout << "4) Eliminar Registro " << endl;
		cout << "5) Salir " << endl;
		cin >> op;

		switch (op) {
		case 1:
		{
			string nit, nombres, apellidos, direccion, fecha_nacimiento;
			int telefono;
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


			Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
			c.crear();
		}
			break;

		case 2:
		{
			Cliente c;
			c.leer();
		}
		break;

		case 3:
		{
			string nit, nombres, apellidos, direccion, fecha_nacimiento, actualizar;
			int telefono;
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
			getline(cin, fecha_nacimiento);
			cout << "Ingrese el id a modificar: ";
			cin >> actualizar;
			Cliente c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
			c.actualizar();
		}
		break;

		case 4:
		{
			Cliente c;
			c.eliminar();
		}
			break;
		}
	} while (op != 5);

	system("pause");
	return 0;

}