#pragma once

class DB
{
public:
	static void login(std::string usuario, std::string contrase�a, bool &login, bool &loginError, bool &respuesta);
	static void insert(std::string usuario, std::string contrase�a, int points, bool& respuesta);
};