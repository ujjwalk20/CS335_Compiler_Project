#pragma once
#include "config.h" 
#include "SymTable.cpp"

// 3 operand instructions
set<string> itype3= {"+", "-", "*", "/", "%", "&", "|", "^", "<<", ">>", "==", "<", ">", "!=", "<=", ">=", "setarr", "getarr", "call", "||", "&&"};

// 2 operand instructions
set<string> itype2= {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "ifgoto", "array"};

// 1 operand instructions
set<string> itype1= {"++", "--", "label", "printint", "scan", "goto", "retint", "printstr", "param", "readParam"};

// No operand instruction
set<string> itype0= {"ret","exit", "beginScope", "endScope"};

// Arrays need to neccessarily have a pre-defined integer size
struct TAC
{
	int lineNum;

	string op;
	int opType;

	Symbol* dest;

	Symbol* opd1;
	Symbol* opd2;

	string target;

	string l1;
	string l2;

	string array_name;
	int array_size;
	
	bool isInt1;
	bool isInt2;

	bool isBreak;
	bool isContinue;
	bool isArgScope;

	// stack<int> activationRecord;

	TAC(){
		isInt1 = false;
		isInt2 = false;
		opd1 = NULL;
		opd2 = NULL;
		dest = NULL;
		isBreak = false;
		isArgScope = false;
	}

	
	Env* oldScope;
	Env* newScope;

};

vector < TAC* > IR;
// SymTable symTable;
SymTable* ST = new SymTable();
