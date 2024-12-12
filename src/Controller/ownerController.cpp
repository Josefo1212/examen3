#include"../Model/owners.h"
#include<fstream>
#include<sstream>
#include<string>
#pragma once
using namespace std;

extern owners* ownersPtr;
extern int ownersCount;

void leerOwners(const string &ownersFile) {
    ifstream archivoOwner("../bin/owners.csv");
    string line;

    if (!archivoOwner.is_open()) {
        cout << "No se pudo abrir el archivo " << ownersFile << endl;
        return;
    }
    getline(archivoOwner, line); // Skip the header line
    while (getline(archivoOwner, line)) {
        owners owner;
        stringstream ss(line);
        string tempStr;

        getline(ss, tempStr, ',');
        owner.setCedulaOwner(stoi(tempStr)); // Convert string to int
        getline(ss, tempStr, ',');
        owner.setNombre(tempStr);
        getline(ss, tempStr, ',');
        owner.setApellido(tempStr);
        getline(ss, tempStr, ',');
        owner.setDireccion(tempStr);
        getline(ss, tempStr, ',');
        owner.setTelefono(tempStr);
        getline(ss, tempStr, ',');
        owner.setEmail(tempStr);

        owners* temp = new owners[ownersCount + 1];
        for (int i = 0; i < ownersCount; ++i) {
            temp[i] = ownersPtr[i];
        }
        temp[ownersCount] = owner;
        delete[] ownersPtr;
        ownersPtr = temp;
        ownersCount++;
    }
    archivoOwner.close();
}

void guardarOwners(const string &ownersFile) {
    ofstream file("../bin/owners.csv");
    file << "cedulaOwner,nombre,apellido,direccion,telefono,email\n";
    for (int i = 0; i < ownersCount; ++i) {
        file << ownersPtr[i].getCedulaOwner() << ","
             << ownersPtr[i].getNombre() << ","
             << ownersPtr[i].getApellido() << ","
             << ownersPtr[i].getDireccion() << ","
             << ownersPtr[i].getTelefono() << ","
             << ownersPtr[i].getEmail() << "\n";
    }
    file.close();
}

void actualizarOwners(const string &cedula) {
    for (int i = 0; i < ownersCount; ++i) {
        if (ownersPtr[i].getCedulaOwner() == stoi(cedula)) { // Convert string to int
            owners original = ownersPtr[i];
            owners &owner = ownersPtr[i];
            cout << "Ingrese nuevos datos (nombre, apellido, direccion, telefono, email): " << endl;
            string nombre, apellido, direccion, telefono, email;
            cin >> nombre >> apellido >> direccion >> telefono;
            cin.ignore(); // Ignore the newline character left in the buffer
            getline(cin, email); // Use getline to read the email
            owner.setNombre(nombre);
            owner.setApellido(apellido);
            owner.setDireccion(direccion);
            owner.setTelefono(telefono);
            owner.setEmail(email);

            cout << "Confirma los cambios? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                guardarOwners("../bin/owners.csv");
                cout << "Cambios confirmados y guardados." << endl;
            } else {
                ownersPtr[i] = original;
                cout << "Cambios revertidos." << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}

void insertarOwners() {
    owners owner;
    cout << "Ingrese datos del owner (cedulaOwner, nombre, apellido, direccion, telefono, email): " << endl;
    string cedulaOwner, nombre, apellido, direccion, telefono, email;
    cin >> cedulaOwner >> nombre >> apellido >> direccion >> telefono >> email;
    owner.setCedulaOwner(stoi(cedulaOwner)); // Convert string to int
    owner.setNombre(nombre);
    owner.setApellido(apellido);
    owner.setDireccion(direccion);
    owner.setTelefono(telefono);
    owner.setEmail(email);

    cout << "Confirma la insercion del owner? (s/n): ";
    char confirmacion;
    cin >> confirmacion;
    if (confirmacion == 's' || confirmacion == 'S') {
        owners* temp = new owners[ownersCount + 1];
        for (int i = 0; i < ownersCount; ++i) {
            temp[i] = ownersPtr[i];
        }
        temp[ownersCount] = owner;
        delete[] ownersPtr;
        ownersPtr = temp;
        ownersCount++;
        guardarOwners("../bin/owners.csv");
        cout << "Owner insertado." << endl;
    } else {
        cout << "Insercion cancelada." << endl;
    }
}

void borrarOwners(const string &cedula) {
    for (int i = 0; i < ownersCount; ++i) {
        if (ownersPtr[i].getCedulaOwner() == stoi(cedula)) { // Convert string to int
            cout << "Esta seguro de que desea eliminar el owner con cedula " << cedula << "? (s/n): ";
            char confirmacion;
            cin >> confirmacion;
            if (confirmacion == 's' || confirmacion == 'S') {
                owners* temp = new owners[ownersCount - 1];
                for (int j = 0, k = 0; j < ownersCount; ++j) {
                    if (j != i) {
                        temp[k++] = ownersPtr[j];
                    }
                }
                delete[] ownersPtr;
                ownersPtr = temp;
                ownersCount--;
                guardarOwners("../bin/owners.csv");
                cout << "Owner eliminado." << endl;
            } else {
                cout << "Eliminacion cancelada." << endl;
            }
            return;
        }
    }
    cout << "Owner no encontrado." << endl;
}