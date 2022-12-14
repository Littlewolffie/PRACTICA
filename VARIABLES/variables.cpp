#include "variables.hpp"

// Construeix un conjunt de variables buit.
variables::variables() throw(error){

    i = 0;

}

// Constructora per còpia, assignació i destructora.
variables::variables(const variables & v) throw(error){

    i = v.i;

}
variables &variables::operator=(const variables & v) throw(error){

    i = v.i;
    return *this;

}
variables::~variables() throw(error){}

/* Afegeix al conjunt de variables la variable de nom v juntament amb el seu
valor-expressió e. Si la variable v ja existia llavors li assigna el nou
valor-expressió. */
void variables::assign(const string & v, const expressio & e) throw(error){

    i = 0;

}

/* Elimina del conjunt de variables el parell amb la variable de nom v. Si
la variable no existeix llavors no fa res. */
void variables::unassign(const string & v) throw(){

    i = 0;

}

/* Consulta el valor-expressió de la variable v. Si la variable no està en
el conjunt de variables retorna l'expressió buida. */
expressio variables::valor(const string & lv) const throw(error){

	token t(5);
	expressio e(t);
	return e;
}

/* Retorna en l totes les claus del conjunt de variables, en un ordre
qualsevol. Si no hi ha cap clau retorna la llista buida.*/
void variables::dump(list<string> & l) const throw(error){

}
