#ifndef PATENTE_H
#define PATENTE_H
#include <string>


using namespace std;

/************************ Crear clase ***************************************/

class Patente {  
private:
  int rol;
  string rut;
  string nombre;
  string direccion;
  string giro;
  string fecha;
  string tipo;
  int valorUTM;

public:
 
  Patente();
  Patente(int r, string rt, string n, string dn, string go, string f, string t, int utm);
  Patente(const Patente& copia);

/******************************** setters ***********************************************************/

  void setrol(int r);
  void setrut(string rt);
  void setnombre(string n);
  void setdireccion(string dn);
  void setgiro(string go);
  void setfecha(string f);
  void settipo(string t);
  void setvalorUTM(int utm);

/********************************* getters ***********************************************************/

  int getrol() const;
  string getrut() const;
  string getnombre() const;
  string getdireccion() const;
  string getgiro() const;
  string getfecha() const;
  string gettipo() const;
  int getvalorUTM() const;

  void desplegar() const;
  virtual ~Patente();

};
#endif 