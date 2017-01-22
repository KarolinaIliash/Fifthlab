#include "hash_map.h"
#include <iostream>
#include <string>
#include<conio.h>

using namespace std;
	

int menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Insert" << endl;
		else  cout << "   Insert" << endl;
		if (key == 1) cout << "-> Get" << endl;
		else  cout << "   Get" << endl;
		if (key == 2) cout << "-> Remove" << endl;
		else  cout << "   Remove" << endl;
		if (key == 3) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

template<typename Key, typename Value>
bool menu_realiz(int answer, hash_map<Key, Value>& map) {
	Key key;
	Value value;
	bool is_present;
	Value result;
	switch (answer) {
	case 0:
		cout << "Key = ";
		cin >> key;
		cout << "Value = ";
		cin >> value;
		map.put(key, value);
		return 0;
	case 1:
		cout << "Key = ";
		cin >> key;
		is_present = map.get(key, result);
		if (is_present) {
			cout << result << endl;
		}
		else {
			cout << "We don't have such a key\n";
		}
		return 0;
	case 2:
		cout << "Key = ";
		cin >> key;
		is_present = map.remove(key);
		if (is_present) {
			cout << "It's ok\n";
		}
		else {
			cout << "We don't have such a key\n";
		}
		return 0;
	case 3:
		return 1;
	}
}

int main() {
	cout << "int - 0\ndouble - 1\nstring - 2\n";
	cout << "Enter type of Key\n";
	int k_type, v_type;
	cin >> k_type;
	cout << "Enter type of Value\n";
	cin >> v_type;
	hash_map<int, int> map1;
	hash_map<int, double> map2;
	hash_map<int, string> map3;
	hash_map<double, int> map4;
	hash_map<double, double> map5;
	hash_map<double, string> map6;
	hash_map<string, int> map7;
	hash_map<string, double> map8;
	hash_map<string, string> map9;
	do {
		system("cls");
		int answer = menu();
		switch (k_type) {
		case 0:
			switch (v_type) {
			case 0:
				if (menu_realiz<int, int>(answer, map1))
					return 0;
				break;
			case 1:
				if(menu_realiz<int, double>(answer, map2))
					return 0;
				break;
			case 2:
				if(menu_realiz<int, string>(answer, map3))
					return 0;
				break;
			}
			break;
		case 1:
			switch (v_type) {
			case 0:
				if(menu_realiz<double, int>(answer, map4))
					return 0;
				break;
			case 1:
				if(menu_realiz<double, double>(answer, map5))
					return 0;
				break;
			case 2:
				if(menu_realiz<double, string>(answer, map6))
					return 0;
				break;
			}
			break;
		case 2:
			switch (v_type) {
			case 0:
				if(menu_realiz<string, int>(answer, map7))
					return 0;
				break;
			case 1:
				if(menu_realiz<string, double>(answer, map8))
					return 0;
				break;
			case 2:
				if(menu_realiz<string, string>(answer, map9))
					return 0;
				break;
			}
			break;
		}
	} while (_getch() != 27);
}