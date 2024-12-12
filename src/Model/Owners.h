#ifndef OWNER_H
#define OWNER_H
#pragma once
#include<iostream>
using namespace std;

class owners {
    private:
        int cedulaOwner;
        string nombre;
        string apellido;
        string direccion;
        string telefono;
        string email;

    public:
        int getCedulaOwner() const;
        string getNombre() const;
        string getApellido() const;
        string getDireccion() const;
        string getTelefono() const;
        string getEmail() const;

        void setCedulaOwner(const int &cedulaOwner);
        void setNombre(const string &nombre);
        void setApellido(const string &apellido);
        void setDireccion(const string &direccion);
        void setTelefono(const string &telefono);
        void setEmail(const string &email);
};
#endif
