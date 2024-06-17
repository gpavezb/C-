#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Patente.h" 

const int OPCION_SALIR = 7;
const int OPCION_ASIGNAR_UTM = 1;
const int OPCION_ACTUALIZAR_VERIFICADOR = 2;
const int OPCION_VALOR_TOTAL_UTM = 3;
const int OPCION_CONSULTA_RUT = 4;
const int OPCION_CONSULTA_ROL = 5;
const int OPCION_MOSTRAR_DATOS = 6;

//******************************************************************************//

using namespace std;

void asignarValoresUTM(vector<Patente>& patentes, int tamanio)
{
    for (int i = 0; i < tamanio; i++) {
        int valor = rand() % 8 + 1;                                         //****** crea un valor aleatorios para utm entre 1 y 8 ******//
        patentes[i].setvalorUTM(valor);                                    //****** asigna el valor utm a patente ******//
    }
    cout << "Se han asignado valores UTM aleatorios a todas las patentes." << endl;
}

float convertir(const vector<Patente>& patentes, int tamanio)
{
    float actual;
    int suma = 0;
    cout << "Ingrese el valor del UTM actual: " << endl;
    cin >> actual;
    for (int i = 0; i < tamanio; i++) {
        suma += patentes[i].getvalorUTM();
    }

    return suma * actual;
}


void consulta(const vector<Patente>& patentes, int tamanio)
{
    int opc = 0;

    while (opc != OPCION_SALIR)
    {
        cout << "¿Prefiere realizar la consulta utilizando el RUT o el ROL?" << endl;
        cout << "1. RUT" << endl;
        cout << "2. ROL" << endl;
        cout << OPCION_SALIR << ". Ir al menú principal" << endl;
        cout << "Ingrese la opción: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
        {
            bool encontrada = false;
            string RUT;
            cout << "Ingrese el RUT: ";
            cin >> RUT;

            for (int i = 0; i < tamanio; i++)
            {
                if (patentes[i].getrut() == RUT)
                {
                    patentes[i].desplegar();
                    encontrada = true;
                    break;                                                     //****** se detiene el bucle al encontrar una coincidencia *******//
                }
            }

            if (!encontrada)
            {
                cout << "No se encontraron registros asociados a este RUT." << endl;
            }
        }
        break;
        case 2:
        {
            bool encontrada = false;
            int ROL;
            cout << 
            "Por favor, ingrese un ROL.";
            cin >> ROL;

            for (int i = 0; i < tamanio; i++)
            {
                if (patentes[i].getrol() == ROL)
                {
                    patentes[i].desplegar();
                    encontrada = true;
                    break;                                                      //****** se detiene el bucle al encontrar una coincidencia *******//
                }
            }

            if (!encontrada)
            {
                cout << "No se encontraron registros asociados a este ROL." << endl;
            }
        }
        break;
        case OPCION_SALIR:
            cout << "Regresando al menú principal." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
            break;
        }
    }
}

vector<Patente> lectura(int& count)
{
    vector<Patente> patentes;

    ifstream archivo("patenteComerciales.txt");
    if (!archivo.is_open()) {
        cerr << "No fue posible abrir el archivo." << endl;
        return patentes;
    }

    string linea;
    int rol;
    string rut, nombre, direccion, giro, fecha, tipo, utmm;
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        count++;
        stringstream ss(linea);
        getline(ss, utmm, ';');
        getline(ss, linea, ';');
        rol = stoi(linea);
        getline(ss, rut, ';');
        getline(ss, nombre, ';');
        getline(ss, direccion, ';');
        getline(ss, giro, ';');
        getline(ss, fecha, ';');
        getline(ss, tipo, ';');

        int utmValor = stoi(utmm);
        patentes.emplace_back(rol, rut, nombre, direccion, giro, fecha, tipo, utmValor);
    }

    archivo.close();

    return patentes;
}

void muestraPatentes(const vector<Patente>& patentes, int tamanio, bool valoresAsignados) {
    for (int i = 0; i < tamanio; i++) {
        cout << endl;
        cout << "Es el dato: " << i + 1 << endl;
        cout << "Rol: " << patentes[i].getrol() << endl;
        cout << "Rut: " << patentes[i].getrut() << endl;
        cout << "Nombre: " << patentes[i].getnombre() << endl;
        cout << "Dirección: " << patentes[i].getdireccion() << endl;
        cout << "Tipo: " << patentes[i].gettipo() << endl;
        cout << "Giro: " << patentes[i].getgiro() << endl;
        cout << "Fecha: " << patentes[i].getfecha() << endl;
        

        if (valoresAsignados) {
            cout << "Valor De La UTM: " << patentes[i].getvalorUTM() << endl;
        }

        cout << ".............................." << endl;
    }
}

int main() {
    int tamanio = 0;
    int opcion = 0;
    vector<Patente> patentes;
    int totalUTM = 0;
    bool valoresAsignados = false;
    srand(time(nullptr));

    while (opcion != OPCION_SALIR) {
        cout << "-----Menú-----" << endl;
        cout << "1.Asignar valores UTM de forma aleatoria" << endl;
        cout << "2.Actualizar Dígito de Verificación" << endl;
        cout << "3.Valor total de UTM asignados" << endl;
        cout << "4.Consultar por Patente" << endl;
        cout << "5.Patente por antigüedad" << endl;
        cout << "6.Mostrar Datos" << endl;
        cout << OPCION_SALIR << ". Salir" << endl;
        cout << "Ingresar opción: ";
        cin >> opcion;

        switch (opcion) {
        case OPCION_ASIGNAR_UTM: {
            if (!valoresAsignados) {
                patentes = lectura(tamanio);
                asignarValoresUTM(patentes, tamanio);
                valoresAsignados = true;
            }
            else {
                cout << "Los valores UTM han sido asignados previamente." << endl;
            }
            break;
        }
        case OPCION_ACTUALIZAR_VERIFICADOR: break;
        case OPCION_VALOR_TOTAL_UTM: {
            if (valoresAsignados) {
                float total = convertir(patentes, tamanio);
                cout << "Valor total de las UTM asignadas: $" << total << " pesos" << endl;
            }
            else {
                cout << "Antes de continuar, debes asignar valores UTM aleatorios." << endl;
            }
            break;
        }
        case OPCION_CONSULTA_RUT:
        case OPCION_CONSULTA_ROL: {
            consulta(patentes, tamanio);
            break;
        }
        case OPCION_MOSTRAR_DATOS: {
            if (!valoresAsignados) {
                patentes = lectura(tamanio);
                valoresAsignados = true;
            }
            muestraPatentes(patentes, tamanio, valoresAsignados);
            break;
        }
        case OPCION_SALIR:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    }

    return 0;
}
