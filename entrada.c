char ayuda(int hola, float nose, char unBuenParametro){
	
	int falso = 0;
	int algo = -falso;
	
	if (!falso){
		algo = -5;
		algo = falso;
		algo = !falso;
		algo = !falso && falso;
		algo = (!falso + algo) || falso;
	}
	else{
		int cero = !1;
		int uno = (1 && 2) || (0 < 0);
		int dos = ((!uno)*(-uno))  + uno * 2;
		int tres = 1.5 + 1.5;
		int cuatro = sizeof(int);
		int cinco = unaFuncionQueDevuelveCinco();
		int seis = 6 ? !0 : -500;
		int siete = ++seis;
		siete++;
		int ocho = siete;
		procesarNumeros(cuatro,dos,cero);
	}
	char estoNoAnda = "chau" + "hola" + 3 * 4;
	
	return ayuda(1,otraFuncion(algo));
	
}

int funcion(){
	
	int unaVariable,otraCosa,otraOtraCosa = 5;
	char otraVariable = 'a';
	float repetido = 345.23;
	float repetido = 012;
	float repetido = 0x433;
	
	int i;
	
	2*2*"hola" + 2234;
	
	("hola" * 2) + 2 + (3 + 4);
	
	
	for(i = 0; i<10 ;i++ ){
		int otroCoso = 10;
		
		while( otroCoso != 0 ){
			otroCoso--;
		}
	}
	
	
	
	printf("%i",i);
	
	return otraVariable;
}