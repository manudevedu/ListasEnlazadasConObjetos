#include <iostream>
#include <string>

using namespace std;

class Alumno {
public:
    string nombres;
    string apellidos;
    string carnet;
    string email;
    string telefono;
    double notas[5];
};

struct Nodo {
    Alumno alumno;
    Nodo* siguiente;
};

int main() {
    Nodo* inicio = nullptr;
    Nodo* actual = nullptr;
    char respuesta;

    while (true) {
        cout << "¿Desea ingresar un nuevo alumno? (S/N): ";
        cin >> respuesta;

        if (cin.fail() || (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n')) {
            cout << "[Error] Opcion no valida. Ingrese S o N.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            break;
        }
    }

    while (respuesta == 'S' || respuesta == 's') {
        Nodo* nuevoNodo = new Nodo();

        cout << "\n--- Ingrese los datos del alumno ---\n";
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nuevoNodo->alumno.nombres);
        cout << "Apellidos: ";
        getline(cin, nuevoNodo->alumno.apellidos);
        cout << "Carnet: ";
        getline(cin, nuevoNodo->alumno.carnet);
        cout << "Email: ";
        getline(cin, nuevoNodo->alumno.email);
        cout << "Telefono: ";
        getline(cin, nuevoNodo->alumno.telefono);

        for (int i = 0; i < 5; i++) {
            while (true) {
                cout << "Ingrese la nota " << (i + 1) << " (0 a 10): ";
                if (cin >> nuevoNodo->alumno.notas[i]) {
                    if (nuevoNodo->alumno.notas[i] >= 0 && nuevoNodo->alumno.notas[i] <= 10) {
                        break;
                    }
                    else {
                        cout << "[Error] La nota debe estar entre 0 y 10 puntos.\n";
                    }
                }
                else {
                    cout << "[Error] Entrada invalida. Ingrese un numero.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        }

        nuevoNodo->siguiente = nullptr;

        if (inicio == nullptr) {
            inicio = nuevoNodo;
            actual = inicio;
        }
        else {
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }

        while (true) {
            cout << "\n¿Desea agregar otro alumno? (S/N): ";
            cin >> respuesta;

            if (cin.fail() || (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n')) {
                cout << "[Error] Opcion no valida. Ingrese S o N.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                break;
            }
        }
    }

    if (inicio != nullptr) {
        cout << "\n========================================";
        cout << "\n        INFORMACION DE ALUMNOS";
        cout << "\n========================================\n";

        actual = inicio;
        while (actual != nullptr) {
            cout << "Nombres:   " << actual->alumno.nombres << "\n";
            cout << "Apellidos: " << actual->alumno.apellidos << "\n";
            cout << "Carnet:    " << actual->alumno.carnet << "\n";
            cout << "Email:     " << actual->alumno.email << "\n";
            cout << "Telefono:  " << actual->alumno.telefono << "\n";

            cout << "Notas:     [ ";
            double suma = 0;
            for (int i = 0; i < 5; i++) {
                cout << actual->alumno.notas[i] << " ";
                suma += actual->alumno.notas[i];
            }
            cout << "]\n";

            double promedio = suma / 5.0;
            cout << "Promedio:  " << promedio << "\n";
            cout << "----------------------------------------\n";

            actual = actual->siguiente;
        }

        while (inicio != nullptr) {
            actual = inicio;
            inicio = inicio->siguiente;
            delete actual;
        }
    }
    else {
        cout << "\nNo se registraron alumnos en la lista.\n";
    }

    return 0;
}