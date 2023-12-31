#pragma once
#include "config.h" 
#include "SymTable.cpp"

// 3 operand instructions
set<string> itype3= {"+", "-", "*", "/", "%", "&", "|", "^", "<<", ">>", "==", "<", ">", "!=", "<=", ">=", "setarr", "getarr"};

// 2 operand instructions
set<string> itype2= {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "ifgoto", "callint", "array"};

// 1 operand instructions
set<string> itype1= {"++", "--", "label", "printint", "scan", "callvoid", "goto", "retint", "printstr"};

// No operand instruction
set<string> itype0= {"ret","exit"};

// TODO :  TEST_CASES. 
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

	stack<int> activationRecord;

	TAC(){
		isInt1 = false;
		isInt2 = false;
		opd1 = NULL;
		opd2 = NULL;
		dest = NULL;
		isBreak = false;
	}

};

vector < TAC* > IR;
// SymTable symTable;
SymTable* ST = new SymTable();

// void readFile(char* fileName);
// void fillTAC(vector <string> instr);
// bool isIntegerLiteral(string str);