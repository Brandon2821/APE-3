#include <iostream>
using namespace std;

int main() {

    char repetir;

    do {

        int N;
        cout << "Ingrese numero de estudiantes: ";
        cin >> N;

        while (N <= 0) {
            cout << "Debe ser mayor a 0: ";
            cin >> N;
        }

        int contA=0, contB=0, contC=0;
        int aprobados=0, reprobNota=0, reprobAsistencia=0;

        float totalProm=0;
        float mayorProm=-1, menorProm=11;
        string mejor, peor;

        for(int i=0; i<N; i++) {

            string nombre;
            char paralelo;
            float n1,n2,n3,asistencia;

            cout << "\nNombre: ";
            cin >> nombre;

            cout << "Paralelo (A/B/C): ";
            cin >> paralelo;
            while(paralelo!='A' && paralelo!='B' && paralelo!='C') {
                cout << "Error. Ingrese A, B o C: ";
                cin >> paralelo;
            }

            do {
                cout << "Nota 1: "; cin >> n1;
            } while(n1<0 || n1>10);

            do {
                cout << "Nota 2: "; cin >> n2;
            } while(n2<0 || n2>10);

            do {
                cout << "Nota 3: "; cin >> n3;
            } while(n3<0 || n3>10);

            do {
                cout << "Asistencia: "; cin >> asistencia;
            } while(asistencia<0 || asistencia>100);

            float promedio = n1*0.3 + n2*0.3 + n3*0.4;

            if(paralelo=='A') contA++;
            if(paralelo=='B') contB++;
            if(paralelo=='C') contC++;

            string estado;

            if(asistencia < 70) {
                estado = "Reprobado por asistencia";
                reprobAsistencia++;
            }
            else {
                if(promedio >= 9) estado = "Excelente";
                else if(promedio >= 8) estado = "Muy bueno";
                else if(promedio >= 7) estado = "Bueno";
                else if(promedio >= 6) estado = "En riesgo";
                else {
                    estado = "Reprobado";
                    reprobNota++;
                }
            }

            if(promedio >= 6 && asistencia >= 70) {
                aprobados++;
            }

            cout << "Promedio: " << promedio << endl;
            cout << "Estado: " << estado << endl;

            if(promedio > mayorProm) {
                mayorProm = promedio;
                mejor = nombre;
            }

            if(promedio < menorProm) {
                menorProm = promedio;
                peor = nombre;
            }

            totalProm += promedio;
        }

        float promGeneral = totalProm / N;

        cout << "\n--- REPORTE ---\n";
        cout << "Total estudiantes: " << N << endl;
        cout << "Paralelo A: " << contA << endl;
        cout << "Paralelo B: " << contB << endl;
        cout << "Paralelo C: " << contC << endl;
        cout << "Aprobados: " << aprobados << endl;
        cout << "Reprobados por nota: " << reprobNota << endl;
        cout << "Reprobados por asistencia: " << reprobAsistencia << endl;
        cout << "Promedio general: " << promGeneral << endl;
        cout << "Mejor estudiante: " << mejor << " (" << mayorProm << ")\n";
        cout << "Peor estudiante: " << peor << " (" << menorProm << ")\n";
        cout << "% Aprobados: " << (aprobados*100.0/N) << "%" << endl;

        cout << "\nDesea repetir? (SI/NO): ";
        cin >> repetir;

    } while(repetir=='S' || repetir=='s');

    return 0;
}
