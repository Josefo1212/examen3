#include"../Model/Owners.h"
#pragma once

string owners::getIdOwner() const { return IdOwner; } // Changed to getIdOwner
string owners::getNombre() const { return nombre; }
string owners::getApellido() const { return apellido; }
string owners::getTelefono() const { return telefono; }
string owners::getDireccion() const { return direccion; }
string owners::getEmail() const { return email; }

void owners::setIdOwner(const string &IdOwner) { this->IdOwner = IdOwner; } // Changed to setIdOwner
void owners::setNombre(const string &nombre) { this->nombre = nombre; }
void owners::setApellido(const string &apellido) { this->apellido = apellido; }
void owners::setTelefono(const string &telefono) { this->telefono = telefono; }
void owners::setDireccion(const string &direccion) { this->direccion = direccion; }
void owners::setEmail(const string &email) { this->email = email; }