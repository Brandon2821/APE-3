#include <iostream>
using namespace std;

int main() {
    float lado, area;
    cout << "Ingrese el valor del lado del cuadrado: ";
    cin >> lado;
    area = lado * lado;
    cout << "El area del cuadrado es: " << area << endl;
    if (lado > 0) {
        cout << "El cuadrado es una figura valida" << endl;
    } else {
        cout << "No es un cuadrado valido" << endl;
    }
    return 0;
}
