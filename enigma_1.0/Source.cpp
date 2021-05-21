#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

char bykv[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int cif[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
using namespace std;
int rotor1[26] = { 4,10,12,5,11,6,3,16,21,25,13,19,14,22,24,7,23,20,18,15,0,8,1,17,2,9 };
int rotor2[26] = { 0,9,3,10,18,8,17,20,23,1,11,7,22,19,12,2,16,6,25,13,15,24,5,21,14,4 };
int rotor3[26] = { 1,3,5,7,9,11,2,15,17,19,23,21,25,13,24,4,8,22,6,0,10,12,20,18,16,14 };
int refl[26] = { 24,17,20,7,16,18,11,3,15,23,13,6,14,10,12,8,4,1,5,25,2,22,21,9,0,19 };
char agr[3]; char key[3]; int prov = 1; int convtext[200]; int shif[200]; int r1, r2, r3; int spin1 = 0; int spin2 = 0; int spin3 = 0; char shifr[200]; int temp, temp1, temp2; int ans; char ennd[200];

void kodd(int sim, int r1, int r2, int r3) {
	int simr1, simr2, simr3, simref, symb;
	simr1 = r1 + sim;
	if (simr1 > 26)simr1 = simr1 - 26;
	for (int i = 0; i != 26; i++)
	{
		if (simr1 == cif[i])temp = rotor1[i];
	}
	simr1 = temp;
	temp = r2 - r1; if (temp < 0)temp = temp * (-1) - 1;
	simr2 = simr1 + temp;
	if (simr2 > 26)simr2 = simr2 - 26;
	for (int i = 0; i != 30; i++)
	{
		if (simr2 == cif[i])temp = rotor2[i];
	}
	simr2 = temp;
	temp = r3 - r2; if (temp < 0)temp = temp * (-1) - 1;
	simr3 = simr2 + temp;
	if (simr3 > 26)simr3 = simr3 - 26;
	for (int i = 0; i != 30; i++)
	{
		if (simr3 == cif[i])temp = rotor3[i];
	}
	simr3 = temp;
	simref = simr3 - r3;
	if (simref < 0)simref = simref * (-1) - 1;
	{if (simref == 0)temp2 = 24;
	if (simref == 1)temp2 = 17;
	if (simref == 2)temp2 = 20;
	if (simref == 3)temp2 = 7;
	if (simref == 4)temp2 = 16;
	if (simref == 5)temp2 = 18;
	if (simref == 6)temp2 = 11;
	if (simref == 7)temp2 = 3;
	if (simref == 8)temp2 = 15;
	if (simref == 9)temp2 = 23;
	if (simref == 10)temp2 = 13;
	if (simref == 11)temp2 = 6;
	if (simref == 12)temp2 = 14;
	if (simref == 13)temp2 = 10;
	if (simref == 14)temp2 = 12;
	if (simref == 15)temp2 = 8;
	if (simref == 16)temp2 = 4;
	if (simref == 17)temp2 = 1;
	if (simref == 18)temp2 = 5;
	if (simref == 19)temp2 = 25;
	if (simref == 20)temp2 = 2;
	if (simref == 21)temp2 = 22;
	if (simref == 22)temp2 = 21;
	if (simref == 23)temp2 = 9;
	if (simref == 24)temp2 = 0;
	if (simref == 25)temp2 = 19;
	}
	simref = temp2;
	simr3 = simref + r3; if (simr3 > 26)simr3 = simr3 - 26;
	for (int i = 0; i != 26; i++) {
		if (simr3 = rotor3[i])temp = cif[i];
	}
	simr3 = temp;
	temp = r3 - r2; if (temp < 0)temp = temp * (-1) - 1;
	simr2 = simr3 - temp;
	for (int i = 0; i != 26; i++) {
		if (simr2 = rotor2[i])temp = cif[i];
	}
	simr2 = temp;
	temp = r2 - r1; if (temp < 0)temp = temp * (-1) - 1;
	simr1 = simr2 - temp;
	for (int i = 0; i != 26; i++) {
		if (simr1 = rotor1[i])temp = cif[i];
	}
	simr1 = temp;
	symb = simr1 - r1; if (symb < 0)symb = symb * (-1) - 1;
	cout << bykv[symb];
}


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "English");
again:
	prov = 1;
	while (prov == 1) {
		system("cls");
		cout << "Did you have a key?Print 'Yes' if you have it,or 'No',and i generate him" << endl;
		cin >> agr;
		if (agr[0] == 'Y' || agr[0] == 'y') {
			cout << "Enter the key,it must consist of a small english letter,like a abc" << endl;
			cin >> key[0]>> key[1]>>key[2];
			cout << "Your key is " << key << endl;
			prov = 0;
			for (int i = 0; i != 3; i++) {
				if (key[i] == 'a')key[i] = 0;
				if (key[i] == 'b')key[i] = 1;
				if (key[i] == 'c')key[i] = 2;
				if (key[i] == 'd')key[i] = 3;
				if (key[i] == 'r')key[i] = 4;
				if (key[i] == 'f')key[i] = 5;
				if (key[i] == 'g')key[i] = 6;
				if (key[i] == 'h')key[i] = 7;
				if (key[i] == 'i')key[i] = 8;
				if (key[i] == 'j')key[i] = 9;
				if (key[i] == 'k')key[i] = 10;
				if (key[i] == 'l')key[i] = 11;
				if (key[i] == 'm')key[i] = 12;
				if (key[i] == 'n')key[i] = 13;
				if (key[i] == 'o')key[i] = 14;
				if (key[i] == 'p')key[i] = 15;
				if (key[i] == 'q')key[i] =

					16;
				if (key[i] == 'r')key[i] = 17;
				if (key[i] == 's')key[i] = 18;
				if (key[i] == 't')key[i] = 19;
				if (key[i] == 'u')key[i] = 20;
				if (key[i] == 'v')key[i] = 21;
				if (key[i] == 'w')key[i] = 22;
				if (key[i] == 'x')key[i] = 23;
				if (key[i] == 'y')key[i] = 24;
				if (key[i] == 'z')key[i] = 25;


			}
		}
		else
			if (agr[0] == 'N' || agr[0] == 'n') {
				for (int i = 0; i != 3; i++) {
					key[i] = rand() % 26;
				}
				cout << "Your key is " << bykv[key[0]] << bykv[key[1]] << bykv[key[2]] << endl;
				prov = 0;
			}
	}
	char text[200] = { '@','@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', '@', };
	cout << "Enter the text,dont use big letter" << endl;
	cin >> text;


	r3 = key[0]; r2 = key[1]; r1 = key[2];
	for (int i = 1; i != 200; i++) {
		if (text[i] == 'a')convtext[i] = 0;
		if (text[i] == 'b')convtext[i] = 1;
		if (text[i] == 'c')convtext[i] = 2;
		if (text[i] == 'd')convtext[i] = 3;
		if (text[i] == 'e')convtext[i] = 4;
		if (text[i] == 'f')convtext[i] = 5;
		if (text[i] == 'g')convtext[i] = 6;
		if (text[i] == 'h')convtext[i] = 7;
		if (text[i] == 'i')convtext[i] = 8;
		if (text[i] == 'j')convtext[i] = 9;
		if (text[i] == 'k')convtext[i] = 10;
		if (text[i] == 'l')convtext[i] = 11;
		if (text[i] == 'm')convtext[i] = 12;
		if (text[i] == 'n')convtext[i] = 13;
		if (text[i] == 'o')convtext[i] = 14;
		if (text[i] == 'p')convtext[i] = 15;
		if (text[i] == 'q')convtext[i] = 16;
		if (text[i] == 'r')convtext[i] = 17;
		if (text[i] == 's')convtext[i] = 18;
		if (text[i] == 't')convtext[i] = 19;
		if (text[i] == 'u')convtext[i] = 20;
		if (text[i] == 'v')convtext[i] = 21;
		if (text[i] == 'w')convtext[i] = 22;
		if (text[i] == 'x')convtext[i] = 23;
		if (text[i] == 'y')convtext[i] = 24;
		if (text[i] == 'z')convtext[i] = 25;
		if (text[i] == '@')break;
	}


	for (int i = 1; i != 200; i++) {
		{r1++;
		if (text[i] == ' ')continue;
		if (r1 == 26) { r1 = 0; spin1 = 1; }
		if (spin1 == 1 && r1 == key[0]) { r2++; spin1 = 0; }
		if (r2 == 26) { r2 = 0; spin2 = 1; }
		if (spin2 == 1 && r2 == key[1]) { r3++; spin2 = 0; }
		if (r3 == 26) r3 = 0; }
		//прокрутка ротора
		if (text[i] == '@')break;
		kodd(convtext[i], r1, r2, r3);
	}
	char gg;
	cout << endl << "You wanna go another?Enter 'y' to continue, or 'n' to exit" << endl;
	cin >> gg;
	if (gg == 'y')goto again;
}