#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Alumno {
    int matricula;
    string nombreCompleto;
    float calificacion1;
    float calificacion2;
    float calificacion3;
    float calificacionFinal;
    bool dadoDeBaja;
};

vector<Alumno> listaAlumnos;

void altaAlumno() {
    Alumno alumno;
    cout << "Matricula: ";
    cin >> alumno.matricula;
    cout << "Nombre completo: ";
    cin.ignore();
    getline(cin, alumno.nombreCompleto);
    cout << "Calificacion 1: ";
    cin >> alumno.calificacion1;
    cout << "Calificacion 2: ";
    cin >> alumno.calificacion2;
    cout << "Calificacion 3: ";
    cin >> alumno.calificacion3;
    alumno.calificacionFinal = (alumno.calificacion1 + alumno.calificacion2 + alumno.calificacion3) / 3.0;
    alumno.dadoDeBaja = false;
    listaAlumnos.push_back(alumno);
    cout << "Alumno dado de alta correctamente." << endl;
}

void bajaAlumno() {
    int matricula;
    cout << "Ingrese la matricula del alumno a dar de baja: ";
    cin >> matricula;
    bool encontrado = false;
    for (int i = 0; i < listaAlumnos.size(); i++) {
        if (listaAlumnos[i].matricula == matricula) {
            listaAlumnos[i].dadoDeBaja = true;
            cout << "Alumno dado de baja correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno no encontrado." << endl;
    }
}

void cambiosAlumno() {
    int matricula;
    cout << "Ingrese la matricula del alumno a modificar: ";
    cin >> matricula;
    bool encontrado = false;
    for (int i = 0; i < listaAlumnos.size(); i++) {
        if (listaAlumnos[i].matricula == matricula) {
            cout << "Matricula: " << listaAlumnos[i].matricula << endl;
            cout << "Nombre completo: " << listaAlumnos[i].nombreCompleto << endl;
            cout << "Calificacion 1: ";
            cin >> listaAlumnos[i].calificacion1;
            cout << "Calificacion 2: ";
            cin >> listaAlumnos[i].calificacion2;
            cout << "Calificacion 3: ";
            cin >> listaAlumnos[i].calificacion3;
            listaAlumnos[i].calificacionFinal = (listaAlumnos[i].calificacion1 + listaAlumnos[i].calificacion2 + listaAlumnos[i].calificacion3) / 3.0;
            cout << "Alumno modificado correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Alumno no encontrado." << endl;
    }
}

void listarAlumnos() {
    for (int i = 0; i < listaAlumnos.size(); i++) {
        if (listaAlumnos[i].dadoDeBaja) {
            cout << "Matricula: " << listaAlumnos[i].matricula << " (DADO DE BAJA)" << endl;
        } else {
            cout << "Matricula: " << listaAlumnos[i].matricula << endl;
            cout << "Nombre completo: " << listaAlumnos[i].nombreCompleto << endl;
            cout << "Calificacion 1: " << listaAlumnos[i].calificacion1 << endl;
            cout << "Calificacion 2: " << listaAlumnos[i].calificacion2 << endl;
            cout << "Calificacion 3: " << listaAlumnos[i].calificacion3 << endl;
            cout << "Calificacion Final: " << fixed << setprecision(2) << listaAlumnos[i].calificacionFinal << endl;
        }
    }
}

int main() {
    int opcion;
    do {
        cout << "Menú de Opciones" << endl;
        cout << "1. Alta" << endl;
        cout << "2. Baja" << endl;
        cout << "3. Cambios" << endl;
        cout << "4. Lista de Alumnos" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                altaAlumno();
                break;
            case 2:
                bajaAlumno();
                break;
            case 3:
                cambiosAlumno();
                break;
            case 4:
                listarAlumnos();
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
