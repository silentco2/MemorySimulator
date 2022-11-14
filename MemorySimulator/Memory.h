#include <ctime>
#include <cstdlib>
using namespace std;
class Memory {
private:
	int* memory;
	int count = 0;
	string ops[6] = { "","load","store","substract","multiply","add" };
	int mapop(string op) {
		for (int i = 0;i < 6;i++)if (ops[i] == op) return i;
		return -1;
	}
public:
	int size;
	Memory() {
		size = 1000;
		memory = new int[size];
		for (int i = 0;i < size;i++) memory[i] = NULL;
	}
	void print() {
		for (int i = 0;i < size;i++) cout << memory[i] << "\n";
	}
	void insertValue(int value) {
		while (1) {
			srand(time(0));
			int x = size/2 + (rand() % size);
			if (memory[x] == NULL) {
				memory[x] = value;
				break;
			}
		}
	}
	void insertValueAt(int value, int index) {
		memory[index] = value;
	}
	int indexOf(int value) {
		for (int i = size/2;i < size;i++)if (memory[i] == value)return i;
		return -1;
	}
	void insertOp(int index,string op) {
		int value = mapop(op) * 1000 + index;
		if (value > 1000) memory[count++] = value;
	}
	void printOp() {
		int i = 0;
		while (memory[i] != NULL) {
			cout << memory[i] << endl;
			i++;
		}
	}
	int valueAt(int index) { return memory[index]; }
};
