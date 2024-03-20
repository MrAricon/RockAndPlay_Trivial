#include "../headers/Game.h"
#include "../headers/Display.h"
#include "../headers/Textures.h"
#include "../headers/DB.h"

void DB::login(std::string usuario, std::string contraseña, bool &login, bool &loginError, bool &respuesta)
{
	try
	{
		ocilib::Environment::Initialize();

		ocilib::Connection con("(DESCRIPTION=(ADDRESS_LIST = (ADDRESS = (PROTOCOL = TCP)(HOST = rockandplay.sytes.net)(PORT = 1521)))(CONNECT_DATA=(SID=orcl)))", "rockandplay", "admin");

		ocilib::Statement check(con);
		check.Execute("SELECT COUNT(*) FROM ranking WHERE username = '" + usuario +"'");

		ocilib::Resultset rsCheck = check.GetResultset();

		while (rsCheck++)
		{
			if (rsCheck.Get<ocilib::ostring>(1) == "0")
			{
				ocilib::Statement st(con);
				st.Execute("SELECT * FROM USERS WHERE username = '" + usuario + "' AND passwd = '" + contraseña + "'");

				ocilib::Resultset rs = st.GetResultset();

				while (rs++)
				{
					if (rs.Get<ocilib::ostring>(4) == usuario && rs.Get<ocilib::ostring>(6) == contraseña)
					{
						login = true;
					}
				}
				if (login == false)
				{
					loginError = true;
				}
			}
			else 
			{
				respuesta = true;
			}
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void DB::insert(std::string usuario, std::string contraseña, int points, bool &respuesta)
{
	try
	{
		ocilib::Environment::Initialize();

		ocilib::Connection con("(DESCRIPTION=(ADDRESS_LIST = (ADDRESS = (PROTOCOL = TCP)(HOST = rockandplay.sytes.net)(PORT = 1521)))(CONNECT_DATA=(SID=orcl)))", "rockandplay", "admin");

		ocilib::Statement check(con);
		check.Execute("SELECT COUNT(*) FROM ranking WHERE username = '" + usuario + "'");

		ocilib::Resultset rsCheck = check.GetResultset();

		while (rsCheck++)
		{
			if (rsCheck.Get<ocilib::ostring>(1) == "0")
			{
				ocilib::Statement st(con);
				st.Execute("INSERT INTO ranking VALUES ((SELECT id_user FROM users WHERE username = '" + usuario + "' ),'" + usuario + "'," + std::to_string(points) + ", SYSDATE)");

				ocilib::Statement comm(con);
				comm.Execute("COMMIT");
			}
			else
			{
				respuesta = true;
			}
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
