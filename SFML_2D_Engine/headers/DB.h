#pragma once

class DB
{
public:
	static void login(std::string usuario, std::string contraseņa, bool &login, bool &loginError, bool &respuesta);
	static void insert(std::string usuario, std::string contraseņa, int points, bool& respuesta);
};