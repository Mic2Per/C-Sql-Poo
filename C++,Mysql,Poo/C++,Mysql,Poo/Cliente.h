#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
class Cliente : Persona {

private: string nit;

public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}

	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string insert = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento)VALUES('"+ nit +"','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso" << endl;
				cout << "\n";
			}
			else {
				cout << "Error al ingresar" << endl;
				cout << "\n";
			}
		}
		else {
			cout << "error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}


	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from clientes";
			const char* e = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------Clientes-----------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;
				}
				cout << "\n";
			}
			else {
				cout << "Error al ingresar" << endl;
				cout << "\n";
			}
		}
		else {
			cout << "error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int eliminar;
			cout << "Ingrese el id a eliminar: ";
			cin >> eliminar;
			string ee = to_string(eliminar);
			string insert = "delete from clientes where id_cliente=" + ee + " ";
			const char* a = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), a);
			if (!q_estado) {
				cout << "Ingreso exitoso" << endl;
				cout << "\n";
			}
			else {
				cout << "Error al ingresar" << endl;
				cout << "\n";
			}
		}
		else {
			cout << "error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string actualizar;
			string t = to_string(telefono);
			string insert = "UPDATE clientes SET nit='" + nit + "',nombres='" + nombres + "',apellidos='" + apellidos + "',direccion='" + direccion + "',telefono=" + t + ",fecha_nacimiento='" + fecha_nacimiento + "' where id_cliente=" + actualizar + " ";
			const char* e = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), e);
			if (!q_estado) {
				cout << "Ingreso exitoso" << endl;
				cout << "\n";
			}
			else {
				cout << "Error al ingresar" << endl;
				cout << "\n";
			}
		}
		else {
			cout << "error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}
};

