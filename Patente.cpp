#include "Patente.h"
#include <iostream>



Patente::Patente() {
rol = 0;
rut = "";
nombre = "";
direccion = "";
giro = "";
fecha = "";
tipo = "";
valorUTM = 0;

} 

Patente::Patente(int r, string ru, string n, string dir, string gi, string f, string t, int utm)
    : rol(r), rut(ru), nombre(n), direccion(dir), giro(gi), fecha(f), tipo(t), valorUTM(utm) {}
    
    Patente::Patente(const Patente& copia)
    : rol(copia.rol), rut(copia.rut), nombre(copia.nombre),
      direccion(copia.direccion), giro(copia.giro), fecha(copia.fecha), tipo(copia.tipo), valorUTM(copia.valorUTM) {}
      

/****************************************************************************************/

void Patente::setrol(int r) {
    rol = r;
}

/***************************************************************************************/

void Patente::setrut(string ru) {
    rut = ru;
}

/*************************************************************************************/

void Patente::setnombre(string n) {
    nombre = n;
}

/************************************************************************************/

void Patente::setdireccion(string dir) {
    direccion = dir;
}

/************************************************************************************/

void Patente::setgiro(string gi) {
    giro = gi;
}

/************************************************************************************/

void Patente::setfecha(string f) {
    fecha = f;
}

/************************************************************************************/

void Patente::settipo(string t) {
    tipo = t;
}

/************************************************************************************/

void Patente::setvalorUTM(int utm) {
    valorUTM = utm;
}

/************************************************************************************/

int Patente::getrol() const {
    return rol;
}

/************************************************************************************/

string Patente::getrut() const {
    return rut;
}

/************************************************************************************/

string Patente::getnombre() const {
    return nombre;
}

/************************************************************************************/

string Patente::getdireccion() const {
    return direccion;
}

/************************************************************************************/

string Patente::getgiro() const {
    return giro;
}

/************************************************************************************/

string Patente::getfecha() const {
    return fecha;
}

/************************************************************************************/

string Patente::gettipo() const {
    return tipo;
}

/************************************************************************************/

int Patente::getvalorUTM() const {
    return valorUTM;
}

/************************************************************************************/

void Patente::desplegar() const{
    cout << "Rol: " << rol << endl;
    cout << "Rut: " << rut << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Giro: " << giro << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Valor UTM: " << valorUTM << endl;
}

Patente::~Patente() {}

/************************************************************************************/