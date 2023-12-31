#include "Symbol.cpp"

static int labelCounter = 0;
static int tempCounter = 0;

class Env{
public:
	string name;
	
	// if it is a method
	string returnType;
	int argNum;
	vector <string> argTypeList;

	// if it is a class
	string Class;
	string ParentClass;
	
	map <string, Symbol*> varList;
	map <string, Symbol*> methodList;
	map <string, Symbol*> addTable;

	int width;
	int maxWidth;	
	int offset;

	// string type;
	string type; 

	vector <Env*> children;
	Env *prevEnv;

	Env(string _name, string _type, Env *prev_env, string _return_type, string Class, string ParentClass);

	string getMethodType();
	string genTemp(string varType, string genericType, int _width, string varToken, int line);
	Symbol* addVar(string varName, string varType, string genericType, int _width, string varToken, int line);
	int getWidth(string varType, string genericType, int _width);
	Symbol* getVar(string varName);
	vector <string> setArgTypeList(vector <string> args);
	Env* findClass(string className, Env* baseEnv);
	Env* getClassEnv();
	Env* getMethod(string methodName, Env* baseEnv);
	Env* getMethodFromClass(string methodName, string className, Env* baseEnv);
	void printTableEnv(Env* env);
	// Symbol* getVarInClass(string varName, string className);
	// Symbol* getVarEnv(string varName);
};