#pragma once

class DB
{
public:
	static void login(std::string usuario, std::string contraseña, bool &login, bool &loginError, bool &respuesta);
	static void insert(std::string usuario, std::string contraseña, int points, bool& respuesta);
};