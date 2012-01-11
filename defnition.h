/*
 ============================================================================
 Name        : Procsi.c
 Author      : Fabien Belli & Guillaume Lestel
 Version     :
 Copyright   : Aucune réutilisation sans demande
 Description : Emulateur de PROCSI en C
 ============================================================================
 */

#define TAILLE_LIGNE 256

#define COMMENTAIRE ';'

#define DEBUG 1

typedef union{
	short brut;
	struct {
		unsigned codeop :   6;
		unsigned mode :     4;
		unsigned source :   3;
		unsigned dest :     3;
	}codage;
}mot;

//definition des modes
enum mode{
	REGREG = 0,
			REGIMM = 4,
			REGDIR = 8,
			REGIND = 12,
			DIRIMM = 5,
			DIRREG = 1,
			INDIMM = 6,
			INDREG = 2
}mode;

//definition des codages
enum codeop{
	LOAD    = 0,
			STORE   = 1,
			ADD     = 2,
			SUB     = 3,
			JMP     = 4,
			JEQ     = 5,
			CALL    = 6,
			RET     = 7,
			PUSH    = 8,
			POP     = 9,
			HALT    = 10
}codeop;

enum SR{
		Z=0,
		N=1,
		O=2,
		C=3
};

void displayREG();
int checkREG(int reg1);
void remplirREG();
void remplirmemData();
void modSR(int value1);

int stepByStep(int debug);
void RegistresDebug(int debug, int PC);
void analyserMemoire(mot *mem, int debugMode);
void MemoryDebug(int debug, int addr);
void visitMemory();
void visitStack();

// définitions pour la compilation
//
mot* construireADD(char* ligne);
mot* construireSUB(char* ligne);
mot construireHALT();
int numRegistre(char* op);
mot* convertTwoPart(char* donnees);
char* stripNmemo(char* ligne, int size);
mot* compilateur(FILE* fichier);
char* getMnemo(char* ligne);
short getImmediat(char* data);
void addInstr(mot* memoire, mot* ligne, int* index, int* taille_tableau);

#endif // DEFNITION_H_INCLUDED
