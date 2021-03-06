
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int divisor;
public:
	hashTable(int N, int M);
	int hashFnc(int key);
	int hashFnc2(int key);
	void put(int key, string value);
	void erase(int key);
	string find(int key);
};

hashTable::hashTable(int N, int M) {
	capacity = N;
	divisor = M;   // 2차 해시함수의 
	table = new entry[capacity];
	return;
}

int hashTable::hashFnc(int key) {
	return key % capacity;
}

int hashTable::hashFnc2(int key) {
	return divisor - (key & divisor);
}

void hashTable::put(int key, string value) {
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid == ISITEM && probe <= capacity) {
		index = hashFnc(index + hashFnc2(key));   // 1칸 이동하는 것이 아니라, 2차 해시함수 결과값(= hashFnc2(key)) 만큼 이동해야함
		probe++;
	}

	if (probe > capacity)
		return;
	
	table[index] = entry(key, value);
	return;
}

void hashTable::erase(int key) {
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity) {
		if (table[index].key == key && table[index].valid == ISITEM) {
			table[index].erase();
			return;
		}
		index = hashFnc(index + hashFnc2(key));
		probe++;
	}
	return;
}

string hashTable::find(int key) {
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity) {
		if (table[index].key == key && table[index].valid == ISITEM)
			return table[index].value;

		index = hashFnc(index + hashFnc2(key));
		probe++;
	}
	return "";
}
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};

class hashTable {
private:
	entry* table;
	int capacity;
	int hashFnc(int key);
public:
	hashTable(int N);
	void put(int key, string value);
	void erase(int key);
	string find(int key);
	void vacant();
};

hashTable::hashTable(int N) {
	capacity = N;
	table = new entry[capacity];
	return;
}

int hashTable::hashFnc(int key) {
	return key % capacity;
}

void hashTable::put(int key, string value) {
	int index = hashFnc(key);
	int probe = 1;
	
	while (table[index].valid == ISITEM && probe <= capacity) {
		index = hashFnc(index + 1);
		probe++;
	}

	if (probe > capacity)
		return;
	cout << probe << endl;
	table[index] = entry(key, value);
	return;
}

void hashTable::erase(int key) {
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity) {
		if (table[index].valid == ISITEM && table[index].key == key) {
			cout << table[index].value << endl;
			table[index].erase();
			return;
		}
		index = hashFnc(index + 1);
		probe++;
	}

	cout << "None" << endl;
	return;
}

string hashTable::find(int key) {
	int index = hashFnc(key);
	int probe = 1;

	while (table[index].valid != NOITEM && probe <= capacity) {

		if (table[index].valid == ISITEM && table[index].key == key)
			return table[index].value;

		index = hashFnc(index + 1);
		probe++;
	}
	return "None";
}

void hashTable::vacant()
{
	int count = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (table[i].valid == NOITEM || table[i].valid == AVAILABLE)
			count++;
	}
	cout << count << endl;
}

int main(void)
{
	int t, n;
	cin >> t >>  n;

	hashTable h(n);
	while (t--)
	{
		string a;
		cin >> a;
		if (a == "put")
		{
			int b;
			string c;
			cin >> b >> c;
			h.put(b, c);
		}
		else if (a == "erase")
		{
			int b;
			cin >> b;
			h.erase(b);
		}
		else if (a == "find")
		{
			int b;
			cin >> b;
			cout << h.find(b) << endl;
		}
		else if (a == "vacant")
		{
			h.vacant();
		}
	}
}