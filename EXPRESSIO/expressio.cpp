#include "expressio.hpp"
#include <stack>
using std::stack;


/* Constructora d'una expressió formada per un sol token: un operand. Si
s'utiliza el valor del token per defecte es construeix la que
anomenem "expressió buida". Si el tipus del token no és el del token
per defecte (NULLTOK), ni el d'una CT_ENTERA, CT_RACIONAL, CT_REAL,
CT_E, VARIABLE o VAR_PERCENTAtGE es produeix un error sintàctic. */
expressio::expressio(const token t) throw(error){
	
	if ((t.tipus() != token::NULLTOK) and ( t.tipus() != token::CT_ENTERA ) and (t.tipus() != token::CT_RACIONAL) and (t.tipus() != token::CT_REAL) and (t.tipus() != token::CT_E) and (t.tipus() != token::VARIABLE) and (t.tipus() != token::VAR_PERCENTATGE)){
	
	throw error(ErrorSintactic);
	
	}
	_arrel = new node;	
	_arrel->tok = t;

}

/* Constructora a partir d'una seqüència de tokens. Es produeix un error si
la seqüència és buida o si no es pot construir l'arbre d'expressió
corresponent(és a dir, si és sintàcticament incorrecta). */
// sintaxis ncorrectas, tamañao != 0 en la lista de operadores , tamaño != 1 en la pila de expresiones , parentesis sin abrir/cerrar , HACER METODO PRIVADO PARA COMPROVAR LOS 2 TOCKENS QUE VAN SEGUIDOS
expressio::expressio(const list<token> & l) throw(error){

	if (l.size() == 0) throw error(ErrorSintactic);
	stack<expressio> aux; // para crear el arbo a partir de expresiones sueltas 
	stack<token> aux_tok; // para guardar operadores 
	
}

// Constructora per còpia, assignació i destructora.
expressio::expressio(const expressio & e) throw(error){

i = 0;

}
expressio &expressio::operator=(const expressio & e) throw(error){

i = 0;
return *this;

}
expressio::~expressio() throw(error){}

// Retorna cert si i només si s'aplica a l'expressió buida.
expressio::operator bool() const throw(){

	return true;
}

/* Operadors d'igualtat i desigualtat. Dues expressions es consideren
iguals si i només si els seus arbres d'expressió són idèntics. */
bool expressio::operator==(const expressio & e) const throw(){

    return true;

}
bool expressio::operator!=(const expressio & e) const throw(){

    return false;

}

/* Retorna una llista sense repeticions, en qualsevol ordre, amb
els noms de les variables de l'expressió. */
void expressio::vars(list<string> & l) const throw(error){



}

/* Substitueix totes les aparicions de la variable de nom v per
l'expressió e. Si no existeix la variable v dins de l'expressió a la
que apliquem aquest mètode l'expressió no es modifica. */
void expressio::apply_substitution(const string & v, const expressio & e) throw(error){

i = 0;

}

/* Aplica un pas de simplificació a l'expressió. La subexpressió a
simplificar es busca seguint el recorregut "left to right" postordre
explicat a l'apartat "Procés d'avaluació". Es pot produir qualsevol dels
errors semàntics que apareixen més avall numerats des del 32 al 35. */
void expressio::simplify_one_step() throw(error){

i = 0;

}

/* Aplica successius passos de simplificació com l'anterior fins que
l'expressió es trobi completament simplificada. Llavors diem que es
troba en "forma normal". Es pot produir qualsevol dels errors
semàntics que apareixen més avall numerats des del 32 al 35. */
void expressio::simplify() throw(error){

i = 0;

}

/* Converteix l'expressió en la seqüència de tokens lt corresponent: els
operadors apareixen entre els operands si són infixos, abans si són
prefixos i els símbols de funció van seguits de parèntesis que tanquen
els seus arguments separats per comes. S'han d'introduir només aquells
parèntesis que siguin estrictament necessaris per trencar les regles de
precedència o associativitat en l'ordre d'aplicació dels operadors. */
void expressio::list_of_tokens(list<token> & lt) throw(error){

i = 0;

}

