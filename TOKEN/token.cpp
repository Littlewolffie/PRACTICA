#include "token.hpp"

token::token(codi cod = NULLTOK) throw(error) 
{
	if(cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE) {
		throw error(IdentificadorIncorrecte);
	} else {
		code = cod;
		
	}
}

token::token(int n) throw(error) 
{
	tip.enter = n;
	code = CT_ENTERA;
	
}

token::token(const racional & r) throw(error) 
{
	tip.frac = r;
	code = CT_RACIONAL;
}

token::token(double x) throw(error) 
{
	tip.real = x;
	code = CT_REAL;
}

bool comprova (string var){

	bool cert = true;;
	for (int i=0, i < var.size() and cert,++i){
	// 65-90 97 122 95
		if (var[i] < 65) cert = false;
		if(var[i] < 97 and var[i] > 90 and var[i] != 95 ) cert = false;
		if(var[i] > 122) cert = false;
	}
	return cert;

}

explicit token::token(const string & var_name) throw(error) 
{
	if(var_name == "unassign" or var_name == "e" or var_name == "sqrt" or var_name == "log" 		or var_name == "exp" or var_name == "evalf") {
	
		throw error(IdentificadorIncorrecte);
		
	}else if(comprova(var_name)){
	
		tip.text = var_name;
		code = VARIABLE;
	} 

	else throw error(IdentificadorIncorrecte);
	
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

token::codi token::tipus() const throw() 
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
	bool igual = false;
	if (code == CT_ENTERA and t.code == CT_ENTERA and t.enter == enter){
		cert = true;
		
	}
	if (code == CT_REAL and t.code == CT_REAL and t.real == real){
		cert = true;
		
	}
	if (code == CT_RACIONAL and t.code == CT_RACIONAL and t.frac == frac){
		cert = true;
		
	}
	if (code == VARIABLE and t.code == VARIABLE and t.text == text){
		cert = true;	
	}
	
	return igual;
}


bool token::operator!=(const token & t) const throw() 
{
	return (not (*this == t));
	
}

 bool token::operator>(const token & t) const throw(error)
 {
 
 	if (code > t.code) return true;
 	else return false;
 
 
 }
 
  bool token::operator<(const token & t) const throw(error)
 {
 
 	if (code < t.code) return true;
 	else return false;
 
 
 }
