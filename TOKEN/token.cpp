#include "token.hpp"

explicit token::token(codi cod = NULLTOK) throw(error) 
{
	if(cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE) {
		throw error(IdentificadorIncorrecte);
	} else {
		code = cod;
	}
}

explicit token::token(int n) throw(error) 
{
	tip.enter = n;
	code = CT_ENTERA;
	
}

explicit token::token(const racional & r) throw(error) 
{
	tip.frac = r;
	code = CT_RACIONAL;
}

explicit token::token(double x) throw(error) 
{
	tip.real = x;
	code = CT_REAL;
}

explicit token::token(const string & var_name) throw(error) 
{
	if(var_name == "unassign" or var_name == "e" or var_name == "sqrt" or var_name == "log" or var_name == "exp" or var_name == "evalf") {
		throw error(IdentificadorIncorrecte);
	} else if() {
	
	} else {
		tip.text = var_name;
		code = VARIABLE;
	}
}

token::token(const token & t) throw(error) 
{
	tip = t.tip;
	code = t.code;
}

token & token::operador=(const token & t) throw(error) 
{
	tip = t.tip;
	code = t.code;
	return *this;
}

token::~token() throw()
{

}

codi token::tipus() const throw() 
{
	return code;
}

int token::valor_enter() const throw(error) 
{
	if(code == CT_ENTERA) {
		 return tip.enter;
	} else {
		throw error(ConsultoraInadequada);
	}
}

racional token::valor_racional() const throw(error) 
{
	if(code == CT_RACIONAL) {
		 return tip.frac;
	} else {
		throw error(ConsultoraInadequada);
	}
}

double token::valor_real() const throw(error) 
{
	if(code == CT_REAL) {
		 return tip.real;
	} else {
		throw error(ConsultoraInadequada);
	}
}

string token::identificador_variable() const throw(error) 
{
	if(code == VARIABLE) {
		 return tip.text;
	} else {
		throw error(ConsultoraInadequada);
	}
}

bool token::operator==(const token & t) const throw() 
{

}
