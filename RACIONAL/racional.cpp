#include "racional.hpp"



int mcd(int a, int b) {
    if (a == 0) {
    	return b;
    } else if(b == 0) {
    	return a;
    } else {
    	return mcd(b%a, a);
    }
} 




int mcm(int a, int b) 
{
	return (a*b)/mcd(a,b);
}




void racional::simplificar() 
{
	int n = numerador;	
	numerador = numerador / mcd(numerador,denominador);
	denominador = denominador / mcd(n, denominador);
	if ( denominador < 0 ){ 
		numerador = -1*numerador;
		denominador = -1*denominador;
	} 
}

racional::racional(int n, int d) throw(error)
{
	if(d == 0) {
		throw error(DenominadorZero);
	}
	numerador = n;
	denominador = d;
	simplificar();
}

racional::racional(const racional & r) throw(error)
{
	numerador = r.numerador;
	denominador = r.denominador;
}

racional & racional::operator=(const racional & r) throw(error)
{
	numerador = r.numerador;
	denominador = r.denominador;
	return *this;
}

racional::~racional() throw()
{

}

int racional::num() const throw()
{
	return numerador;
}

int racional::denom() const throw()
{
	return denominador;
}

int racional::part_entera() const throw()
{
	if ( numerador < 0) return (-1);
	else return numerador/denominador;
	
}

racional racional::residu() const throw()
{
	racional r;
	if(numerador > denominador) {
		int aux = numerador/denominador;
		r.numerador = numerador - aux*denominador;
		r.denominador = denominador;
	} else if(numerador < denominador) {
		if (numerador < 0 )
			r.numerador = numerador+denominador;
		else r.numerador = numerador;	
		r.denominador = denominador;
	} else if(numerador == denominador) {
		r.numerador = 0;
		r.denominador = 1;
	}
	return r;
}

racional racional::operator+(const racional & r) const throw(error)
{
	int auxnum;
	int auxdenom;
	if (r.denominador != denominador) {
		 auxnum = numerador*r.denominador + r.numerador*denominador;
		 auxdenom = mcm(denominador, r.denominador);
	}
	else {
	
		auxnum = numerador + r.numerador;
		auxdenom = denominador;	
	
	}
	return racional(auxnum, auxdenom);
	
}

racional racional::operator-(const racional & r) const throw(error)
{
	int auxnum;
	int auxdenom;
	if (r.denominador != denominador) {
		 auxnum = numerador*r.denominador - r.numerador*denominador;
		 auxdenom = mcm(denominador, r.denominador);
	}
	else {
	
		auxnum = numerador - r.numerador;
		auxdenom = denominador;	
	
	}
	return racional(auxnum, auxdenom);
}

racional racional::operator*(const racional & r) const throw(error)
{
	int auxnum = numerador*r.numerador;
	int auxdenom = denominador*r.denominador;
	return racional(auxnum, auxdenom);
}

racional racional::operator/(const racional & r) const throw(error)
{
	int auxnum = numerador*r.denominador;
	int auxdenom = denominador*r.numerador;
	return racional(auxnum, auxdenom);
}


bool racional::operator==(const racional & r) const throw()
{

	return (numerador == r.numerador and denominador == r.denominador);

}

bool racional::operator!=(const racional & r) const throw()
{

	return (not (*this == r));

}
bool racional::operator<(const racional & r) const throw()
{
	int auxnumerador = numerador;
	int r_auxnumerador = r.numerador;
	
	if (denominador != r.denominador){
		int mcm1 = mcm(denominador,r.denominador);
		int auxnumerador =numerador * mcm1/denominador;
		int r_auxnumerador =r.numerador * mcm1/r.denominador;
		
	}
	
	return (auxnumerador <  r_auxnumerador);
}

bool racional::operator<=(const racional & r) const throw()
{
	int auxnumerador = numerador;
	int r_auxnumerador = r.numerador;
	
	if (denominador != r.denominador){
		int mcm1 = mcm(denominador,r.denominador);
		int auxnumerador =numerador * mcm1/denominador;
		int r_auxnumerador =r.numerador * mcm1/r.denominador;
		
	}
	
	return (auxnumerador <=  r_auxnumerador);
}

bool racional::operator>(const racional & r) const throw()
{

	return (not(*this <= r));
}

bool racional::operator>=(const racional & r) const throw()
{

	return (not(*this < r));
}
