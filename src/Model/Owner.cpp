#include"../Model/Owners.h"
#pragma once

int owners::getCedulaOwner() const { return cedulaOwner; }
string owners::getNombre() const { return nombre; }
string owners::getApellido() const { return apellido; }
string owners::getTelefono() const { return telefono; }
string owners::getDireccion() const { return direccion; }
string owners::getEmail() const { return email; }

void owners::setCedulaOwner(const int &cedulaOwner) { this->cedulaOwner = cedulaOwner; }
void owners::setNombre(const string &nombre) { this->nombre = nombre; }
void owners::setApellido(const string &apellido) { this->apellido = apellido; }
void owners::setTelefono(const string &telefono) { this->telefono = telefono; }
void owners::setDireccion(const string &direccion) { this->direccion = direccion; }
void owners::setEmail(const string &email) { this->email = email; }