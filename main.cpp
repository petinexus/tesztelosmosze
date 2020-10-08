#include "Game.h"

/*
	Szechenyi Istvan Egyetem - MOSZE 2020 - Vodor
		- Borbely Roland
		- Vitez Marcell
		- Voznek Peter
*/


/*! \brief main függvény
 *         
 *  
 *  A main try catch-ben vizsgáljuk meg a bemenő adatok megfelelőségét. 
 *         
 *  \return 0 lesz a visszatérési értéke, ha minden rendben lefut
 *  
 *  \param argc [in] argumentumok száma
 *  \param argv [in] karaktertípusú tömb az argumentumokkal 
 */
int main(int argc, char** argv)
{
	if (argc == 3)
	   /*! \brief a try catch függvény
       *
	   *  
	   * A try catch-ben vizsgáljuk meg a bemenő adatok megfelelőségét. 
	   * 
	   * \return hiba esetén a hibakóddal tér vissza
	   * 
       * @see parseUnit() 9 sor
       */
		try
		{
			Game g(argv);
			g.runGame();
		}
		catch(std::string e)
		{
			std::cout << e;
		}
	else
		std::cout << "Incorrect number of parameters!";

	return 0;
}

