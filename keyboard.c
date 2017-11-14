/***************************************************
* Nombre del modulo: keyboard.c
*
* Modulo creado para la asignatura Elo312
* Laboratorio de Estructura de Computadores
* del departamento de Electr�nica de la Universidad
* T�cnica Federico Santa Mar�a. El uso o copia
* est� permitido y se agracede mantener el nombre 
* de los creadores.
*
* Escrito inicialmente el 01/01/2004 Por Michael Kusch & Wolfgang Freund
* Modificado el 24/09/2014           Por Mauricio Sol�s & Andr�s Llico.
*
* Descripci�n del m�dulo:
* Modulo driver teclado matricial
* Contiene las funciones que permiten manejar el
* teclado matricial.
***************************************************/

/*  Include section
*
***************************************************/
#include "keyboard.h"

/*  Defines section
*
***************************************************/
typedef unsigned char uchar;

/*  Local Function Prototype Section
*
***************************************************/
void keyboard_button_action(char);


/*  Global Variables Section
*
***************************************************/
uchar BUTMAT_CLK = 0;           // cu�ntas interrupciones se lleva presionado el bot�n
uchar BUTMAT_PREV = 0xFF;       // tecla de la lectura anterior, FF => ninguna.


////////////////////////////////////////
//       RUTINAS IMPLEMENTADAS        //
//                                    //

/**************************************************
* Nombre    		: void keyboard_init(void)
* returns			: void
* Creada por		: Michael Kusch
* Fecha creaci�n	: 01/01/2004
* Descripci�n		: Inicializa los puertos del 
* driver del teclado.
**************************************************/
void keyboard_init(void)
{
    PTOUT = 0x00;
    PTDIR = 0x00;
}

/**************************************************
* Nombre    		: void keyboard_tec_matrix(void)
* returns			: void
* Creada por		: Michael Kusch
* Fecha creaci�n	: 01/01/2004
* Descripci�n		: Lee la matriz de botones y 
* llama a la funci�n keyboard_button_action() cuando
* detecta que se ha presionado una tecla (o se ha mantenido
* presionada una tecla).
* Esta funci�n debe ser llamada cada cierta cantidad de tiempo.
**************************************************/
void keyboard_tec_matrix(void)
{
    uchar BUTMAT = 0xFF;        // tecla de 0 a 15
    uchar k, i, temp;

    temp = 0x00;
    for(PTDIR = 0x10; PTDIR > 0; PTDIR <<= 1) {
        asm("NOP"); asm("NOP");
        asm("NOP"); asm("NOP");
        asm("NOP");
        k = (((~PTIN) & 0x0F) | PTDIR);
        if ( (k & 0x0F) )	           // si hay alg�n bit de columna en 0, entonces if es verdadero
            temp = k;	               // y se guarda el valor de la columna y filas activas
    }

    if (temp) {	                       // hubo tecla presionada?
        switch	(temp & 0xF0) {
        case BIT4:
            BUTMAT = 0;	 // fila 1
            break;
        case BIT5:
            BUTMAT = 4;	 // fila 2
            break;
        case BIT6:
            BUTMAT = 8;	 // fila 3
            break;
        case BIT7:
            BUTMAT = 12; // fila 4
            break;
        }

        switch	(temp & 0x0F) {
        case BIT0:
            asm("NOP");
            BUTMAT += 0; // col 1
            break;
        case BIT1:
            BUTMAT += 1; // col 2
            break;
        case BIT2:
            BUTMAT += 2; // col 3
            break;
        case BIT3:
            BUTMAT += 3; // col 4
            break;
        }

        if (BUTMAT != BUTMAT_PREV) {              // bot�n presionado es distinto al anterior?
            BUTMAT_PREV = BUTMAT;
            BUTMAT_CLK = 0;
            keyboard_button_action(BUTMAT);
        }
        else {
            if (++BUTMAT_CLK == 100) {            // presionada por m�s de 100*10[ms] (1 [s])?
                keyboard_button_action(BUTMAT);   // actuar como si se volvi� a presionar el bot�n
                BUTMAT_CLK -= 33;                 // por cada 0.5 [s] que siga presionado el bot�n
            }
        }
    }
    else
        BUTMAT_PREV = 0xFF;                       // ning�n bot�n presionado
}
//                                    //
////////////////////////////////////////


////////////////////////////////////////
//     RUTINAS NO IMPLEMENTADAS       //
//                                    //

/**************************************************
* Nombre    		: void keyboard_button_action(char arg1)
* returns			: void
* arg1				: Tecla presionada
* Creada por		: Michael Kusch
* Fecha creaci�n	: 01/01/2004
* Descripci�n		: Realiza una accion segun la
tecla que ha sido presionada.
**************************************************/
void keyboard_button_action(char tecla)
{
  //////EDITOR 1 ///////
  if ((int)tecla==3){ 
  switch (tecla):
  case 0:
   printf("A");
  case 1:
   printf("B");
  case 2:
   printf("C");
  case 4:
   printf("D");
  case 5: 
   printf("E");
  case 6:
   printf("F");
  case 8:
   printf("G");
  case 9:
   printf("H");
  case 10:
   printf("I");
  }
  
  else if ((int)tecla==7){ 
  switch (tecla):
  case 0:
   printf("J");
  case 1:
   printf("K");
  case 2:
   printf("L");
  case 4:
   printf("M");
  case 5: 
   printf("N");
  case 6:
   printf("O");
  case 8:
   printf("P");
  case 9:
   printf("Q");
  case 10:
   printf("R");
  }
  
  else if ((int)tecla==11){ 
  switch (tecla):
  case 0:
   printf("S");
  case 1:
   printf("T");
  case 2:
   printf("U");
  case 4:
   printf("V");
  case 5: 
   printf("W");
  case 6:
   printf("X");
  case 8:
   printf("Y");
  case 9:
   printf("Z");
  }

  else if ((int)tecla==11){ 
  switch (tecla):
  case 0:
   printf("1");
  case 1:
   printf("2");
  case 2:
   printf("3");
  case 4:
   printf("4");
  case 5: 
   printf("5");
  case 6:
   printf("6");
  case 8:
   printf("7");
  case 9:
   printf("8");
  case 10:
   printf("9");
  case 
   printf("\b");
  case 14:
   printf("\n");
   
  //////EDITOR 2 ///////
   printf("%c",(int)tecla);
  
   
  /////EDITOR 3 ///////
   if ((int)tecla==3){
   printf("A");
   }
   else if ((int)tecla == 7){
   printf("B");
   }
   else if((int)tecla == 11){
   printf("C");
   }
   else if ((int)tecla==15){
   printf("D");
   }
   else if 
   
   
   
}

