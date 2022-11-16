#include "token.hpp"

explicit token::token(codi cod = NULLTOK) throw(error) {
	if(cod == CT_ENTERA or cod == CT_RACIONAL or cod == CT_REAL or cod == VARIABLE) {
		throw error(IdentificadorIncorrecte);
	} else {
		t.cod = cod;
	}
}

explicit token::token(int n) throw(error) {
	t.n = n;
}

explicit token::token(const racional & r) throw(error) {
	t.r = r;
}

explicit token::token(double x) throw(error) {
	t.x = x;
}

explicit token::token(const string & var_name) throw(error) {
	t.s = var_name;
	if(
}
