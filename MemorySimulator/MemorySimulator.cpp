#include <iostream>
#include "Memory.h"
#include "Register.h"
using namespace std;
int main() {
	Memory* m = new Memory();
	m->insertValue(2);
	m->insertValue(3);
	int address1 = m->indexOf(2);
	int address2 = m->indexOf(3);
	m->insertOp(address1, "load");
	m->insertOp(address2, "add");
	m->insertOp(address1, "store");
	Register* r = new Register(m);
	r->FEcycle();
	m->print();
}