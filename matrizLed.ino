/************************************************************************************
* Name: Matriz de Leds
* Descrição: Mostra letras ou imagens em uma matriz de leds.
*
* Escrito por: Guilherme Alceu Xavier da Silva <guilherme.xavier@pucpr.br>
*************************************************************************************/
/************************************************************************************
* Constantes e variáveis
************************************************************************************/
//Definição de da quantidade de linhas e colunas e seus respectivos pinos
const int numLinhas = 4;
const int numColunas = 4;
const int pinosLinha[numLinhas] = {2,4,5,8};
const int pinosColuna[numColunas] = {3,6,7,9};

//Tempo de espera para após mostrar uma letra/desenho na matriz
const int delayMatriz = 200;

//Definição das letras/desenhos e para exibição
int branco[4][4] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};
int a[4][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,1,1,1},
	{1,0,0,1}
};
int b[4][4] = {
	{1,1,1,1},
	{1,0,1,0},
	{1,0,1,0},
	{1,1,1,1}
};
int e[4][4] = {
	{1,1,1,1},
	{1,1,1,0},
	{1,0,0,0},
	{1,1,1,1}
};
int h[4][4] = {
	{1,0,0,1},
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1}
};
int l[4][4] = {
	{1,0,0,0},
	{1,0,0,0},
	{1,0,0,0},
	{1,1,1,0}
};
int n[4][4] = {
	{1,0,0,1},
	{1,1,0,1},
	{1,0,1,1},
	{1,0,0,1}
};
int o[4][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1}
};

/************************************************************************************
* Função: void imprimirLetra(int letra[numLinhas][numColunas], int tempoAceso)
* Descrição: Mostra uma letra/desenho na matriz.			 
* Notas: Não atiliza mais a função apagarLeds para economizar tempo: apaga o led
* 		 logo após acender.
*		 Agora utiliza a função millis para controlar o tempo.
************************************************************************************/
void imprimirLetra(int letra[numLinhas][numColunas], int tempoAceso){
	unsigned long tempoInicial = millis();
	unsigned long tempoAtual = millis();
	//Mostra a letra/desenho na matriz enquanto o tempo dentro da função for menor que o limite
	while((tempoAtual-tempoInicial)<tempoAceso){
		for(int li=0;li<numLinhas;li++){
			//Deixa a linha como LOW para poder acender os leds
			digitalWrite(pinosLinha[li], LOW);
			for(int co=0;co<numColunas;co++){
			    if(letra[li][co]==1){
			    	//Acende o led
					digitalWrite(pinosColuna[co], HIGH);
					delay(1);
				}				
				//Apaga o led
				digitalWrite(pinosColuna[co], LOW);					
			}
			//Deixa a linha como HIGH para impedir que um led seja aceso na linha
			digitalWrite(pinosLinha[li], HIGH);
		}
		tempoAtual = millis();
	}
	delay(delayMatriz);
}

/************************************************************************************
* Função: void imprimirFrase(int frase, int tempoAceso)
* Descrição: Recebe uma frase, desmembra em letras e mostra na matriz com 
* 			 a função imprimirLetra.
************************************************************************************/
void imprimirFrase(int frase, int tempoAceso){
	
}

/************************************************************************************
* Função: void apagarLeds()
* Descrição: Coloca todos os pinos da linha como HIGH e todos da coluna como LOW 
* 			 para apagar todos os leds.
* Notas: Como o led é um diodo, a corrente não passa no sentido invertido e ele
* 		 mantém apagado.
************************************************************************************/
void apagarLeds(){	
	for (int x = 0; x < numLinhas; x++) {
		digitalWrite(pinosLinha[x], HIGH);
	}
	for (int x = 0; x < numColunas; x++) { 
		digitalWrite(pinosColuna[x], LOW);
	}
}

/************************************************************************************
* Função: void acenderLeds()
* Descrição: Coloca todos os pinos da linha como LOW e todos da coluna como HIGH 
* 			 para acender todos os leds.
* Notas: Função contrária a apagarLeds e deve ser utilizada apenas para para fins
* 		 de debug para visualizar se a configuração do número de portas está correto
* 		 e se todos os leds estão funcionando.
************************************************************************************/
void acenderLeds(){
	for (int li = 0; li < numLinhas; li++) {
		digitalWrite(pinosLinha[li], LOW);
	}
	for (int co = 0; co < numColunas; co++) { 
		digitalWrite(pinosColuna[co], HIGH);
	}
}

/************************************************************************************
* Função: void setup()
* Descrição: Seta todos pinos como output e apaga todos os leds.
* Notas: É possível chamar a função acenderLeds para verificar se a configuração do 
* 		número dos pinos está correta e se todos os leds estão funcionando.
************************************************************************************/
void setup() {	
	for (int x = 0; x < numLinhas; x++) {
		pinMode(pinosLinha[x], OUTPUT);
	}
	for (int x = 0; x < numColunas; x++) { 
		pinMode(pinosColuna[x], OUTPUT);
	}
	apagarLeds();
	//acenderLeds();
}

/************************************************************************************
* Função: void loop()
* Descrição: Onde o programa acontece - chama a função imprimirLetra para mostrar
* 			 as letras na matriz.
************************************************************************************/
void loop() {
	imprimirLetra(h,1000);
	imprimirLetra(e,1000);
	imprimirLetra(l,1000);	
	imprimirLetra(l,1000);
	imprimirLetra(o,1000);	
}
