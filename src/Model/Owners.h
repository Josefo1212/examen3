#ifndef OWNER_H
#define OWNER_H
#pragma once
#include<iostream>
using namespace std;

class owners {
    private:
        string IdOwner;
        string nombre;
        string apellido;
        string direccion;
        string telefono;
        string email;

    public:
        string getIdOwner() const;
        string getNombre() const;
        string getApellido() const;
        string getDireccion() const;
        string getTelefono() const;
        string getEmail() const;

        void setIdOwner(const string &IdOwner);
        void setNombre(const string &nombre);
        void setApellido(const string &apellido);
        void setDireccion(const string &direccion);
        void setTelefono(const string &telefono);
        void setEmail(const string &email);
};
#endif
