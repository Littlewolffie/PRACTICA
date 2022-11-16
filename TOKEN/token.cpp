#include "token.hpp"

explicit token::token(codi cod = NULLTOK) throw(error) 
{
	if(cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE) {
		throw error(IdentificadorIncorrecte);
	} else {
		t.cod = cod;
	}
}

explicit token::token(int n) throw(error) 
{
	t.n = n;
}

explicit token::token(const racional & r) throw(error) 
{
	t.r = r;
}

explicit token::token(double x) throw(error) 
{
	t.x = x;
}

explicit token::token(const string & var_name) throw(error) 
{
	t.s = var_name;
	if(var_name == "unassign" or var_name == "e" or var_name == "sqrt" or var_name == "log" or var_name == "exp" or var_name == "evalf") {
		throw error(IdentificadorIncorrecte);
	} else if() {
	
	}
}

token::token(const token & t) throw(error) 
{
	t = t.t;
}

token & token::operador=(const token & t) throw(error) 
{
	t = t.t;
	return *this;
}

token::~token() throw()
{

}

codi token::tipus() const throw() {
	return cod;
}

int token::valor_enter() const throw(error) {
	if(cod == CT_ENTERA) {
		 return n;
	} else {
		throw error(ConsultoraInadequada);
	}
}
