using namespace std;
class Register {
public:
	int PC = 0, IR = 0, AC = 0;
	Memory* memory;
	Register(Memory* m) {
		memory = m;
	}
	bool fetch() {
		cout << "---PC checks if program is over---\n";
		if (memory->valueAt(PC) == NULL) return false;
		cout << "---fetcing data---\n";
		cout << "---storing value in IR---\n";
		IR = memory->valueAt(PC);
		return true;
	}
	void execute() {
		cout << "---Executing---\n";
		int c = IR / 1000;
		int index = IR % 1000;
		switch (c) {
		case 1:
			cout << "---Loading value from Memory---\n";
			AC = memory->valueAt(index);
			break;
		case 2:
			cout << "---Storing value in Memory---\n";
			memory->insertValueAt(AC, index);
		case 3:
			cout << "---Substracting from AC---\n";
			AC -= memory->valueAt(index);
			break;
		case 4:
			cout << "---Multiplying on AC---\n";
			AC *= memory->valueAt(index);
			break;
		case 5:
			cout << "---Adding to AC---\n";
			AC += memory->valueAt(index);
			break;
		default:
			cout << "Error OP is not found\n";
			break;
		}
		cout << "---Incrementing PC---\n";
		PC++;
	}
	void FEcycle() {
		while (fetch()) {
			execute();
		}
		cout << "...Program finished Exiting...\n";
	}
};