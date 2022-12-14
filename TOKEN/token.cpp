
#include "token.hpp"

token::t::t() {
	
}
token::t::~t(){
}


token::token(codi cod) throw(error) 
{
	if(cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE) {
		throw error(ConstructoraInadequada);
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
	if (var.size() == 0) cert = false;
	for (unsigned int i=0; i < var.size() and cert;++i){
	// 65-90 97 122 95
		if (var[i] < 65) cert = false;
		if(var[i] < 97 and var[i] > 90 and var[i] != 95 ) cert = false;
		if(var[i] > 122) cert = false;
	}
	return cert;

}

token::token(const string & var_name) throw(error) 
{
	if(var_name == "unassign" or var_name == "e" or var_name == "sqrt" or var_name == "log" or var_name == "exp" or var_name == "evalf") {
	
		throw error(IdentificadorIncorrecte);
		
	}else if(comprova(var_name)){

		new(&this->tip.text) string(var_name);
		//tip.text = var_name;
		code = VARIABLE;
	} 

	else throw error(IdentificadorIncorrecte);
	
}

token::token(const token & t) throw(error) 
{
	*this = t;
}
token &token::operator=(const token & t) throw(error) 
{
	code = t.code;
	if (code == CT_ENTERA) tip.enter = t.tip.enter;
	else if (code == CT_RACIONAL)tip.frac = t.tip.frac;
	else if (code == CT_REAL) tip.real = t.tip.real;
	else if (code == VARIABLE) new(&this->tip.text)  string(t.tip.text);
	return *this;
}

token::~token() throw()
{
	if (code == VARIABLE){
		delete (&this->tip.text);
	}
	
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
	bool igual = true;

	if (code != t.code) igual = false; 
	
	else {

		if ((code == CT_ENTERA) and (tip.enter != t.tip.enter)) igual = false;
		else if ((code == CT_REAL) and (tip.real != t.tip.real)) igual = false;
		else if ((code == CT_RACIONAL) and (tip.frac != t.tip.frac)) igual = false;
		else if ((code == VARIABLE) and (tip.text != t.tip.text)) igual = false;
	}
	return igual;
}


bool token::operator!=(const token & t) const throw() 
{
	return (not (*this == t));
	
}

 bool token::operator>(const token & t) const throw(error)
 {
 
 	if ((t.code <= VAR_PERCENTATGE) or (t.code >= SQRT) or (code <= VAR_PERCENTATGE) or (code >= SQRT)) 
		throw error(PrecedenciaEntreNoOperadors);
		
	bool major = true;	
	
	if (t.code == EXPONENCIACIO) major = false;
	
	else if ((t.code == CANVI_DE_SIGNE) or (t.code == SIGNE_POSITIU)) {
		if (code == EXPONENCIACIO) major = true;	
		else major = false;
	}
	
	else if ((t.code == MULTIPLICACIO) or (t.code == DIVISIO)) {
		if ((code == SUMA) or (code == RESTA) or (code == DIVISIO) or (code == MULTIPLICACIO)) 
			major = false;
		else major = true;
	}
	
	else if ((t.code == SUMA) or (t.code == RESTA)) {
		if ((code == SUMA) or (code == RESTA)) major = false;
	}	
	
	return major;
	

 
}
 
  bool token::operator<(const token & t) const throw(error)
 {
 
 	if ((t.code <= VAR_PERCENTATGE) or (t.code >= SQRT) or (code <= VAR_PERCENTATGE) or (code >= SQRT)) 
		throw error(PrecedenciaEntreNoOperadors);
		
	bool major = true;	
	
	if (code == EXPONENCIACIO) major = false;
	
	else if ((code == CANVI_DE_SIGNE) or (code == SIGNE_POSITIU)) {
		if (t.code == EXPONENCIACIO) major = true;	
		else major = false;
	}
	
	else if ((code == MULTIPLICACIO) or (code == DIVISIO)) {
		if ((t.code == SUMA) or (t.code == RESTA) or (t.code == DIVISIO) or (t.code == MULTIPLICACIO)) 
			major = false;
		else major = true;
	}
	
	else if ((code == SUMA) or (code == RESTA)) {
		if ((t.code == SUMA) or (t.code == RESTA)) major = false;
	}	
	
	return major;
 
 
 }
