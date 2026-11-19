#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {

    int opcion;
    string producto = "";
    float monto = 0.0;

    do {

        cout << "================================" << endl;
        cout << "       REGISTRO DE VENTAS" << endl;
        cout << "================================" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Mostrar ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

    if (opcion == 1) {

        cin.ignore();

        cout << "Ingrese el nombre del producto: ";
        getline(cin, producto);

        cout << "Ingrese el monto de la venta: ";
         cin >> monto;

        ofstream archivo("ventas.txt", ios::app);

        if (archivo.is_open()) {

         archivo << "Producto: " << producto
          << " | Monto: $" << monto << endl;

            archivo.close();

             cout << "Venta registrada correctamente." << endl;

        } else {
                cout << "Error al abrir el archivo." << endl;
        }

        }
    else if (opcion == 2) {

        ifstream archivo("ventas.txt");

        if (archivo.is_open()) {

            string linea;

            cout << endl;
            cout << "========= VENTAS REGISTRADAS =========" << endl;

            while (getline(archivo, linea)) {
                cout << linea << endl;
                }

                archivo.close();

            } else {
                cout << "No hay ventas registradas." << endl;
            }

        }
        else if (opcion == 3) {

            cout << "Saliendo del programa..." << endl;

        }
        else {

            cout << "Opcion no valida." << endl;

        }

    } while (opcion != 3);

    return 0;
} 
