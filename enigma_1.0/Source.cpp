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
int checking_ready = 1; char cheking_en_de_code,cheking_key_logic; int checking_key = 1,key_int[3]; char key_char[3];
char primal_text_char[200] = {'@'};int primal_text_int[200];
int temp,temp_1,temp_2,temp_3,temp_4,temp_5,temp_6,temp_7,temp_8,temp_key;
int rotate_1, rotate_2, rotate_3,key_int_temp_1,key_int_temp_2, key_int_temp_3,temp_rotate;



void encode() {

while (checking_key == 1) {
cout << "You have a key?Type 'y' if you got,or 'n', and i generate him" << endl;
cin >> cheking_key_logic;
if (cheking_key_logic == 'y') {
cout << "Enter your key" << endl;
cin >> key_char;
if ((key_char[0] != 0)&&(key_char[1] != 0)&&(key_char[2] != 0)) {
checking_key = 0;
for (int i = 0; i != 3; i++) {
for (int y = 0; y != 26; y++) {
if (key_char[i] == bykv[y]) {
key_int[i] = y;
}
}
}
}
else {
cout << "I cannot read your answer,please, try again" << endl;
}
}
if (cheking_key_logic == 'n') {
for (int i = 0; i != 3; i++) {

key_int[i] = rand() %26;
//генерация ключа

for (int y = 0; y != 26; y++) {
if (key_int[i] == y) {
key_char[i] = bykv[y];
}
}
//перевод ключа в текстовый вид

}
checking_key = 0;
}
cout << "Your key: " << key_char << endl;
}



{
cout << "Enter your text" << endl;
char primal_text_char[200]={'@'};
cin >> primal_text_char;
cout << "Encoded message: ";
for (int i = 0; i != 200; i++) {
if (primal_text_char[i] != '@') {
for (int y = 0; y != 26; y++) {
if (primal_text_char[i] == bykv[y]) {
primal_text_int[i] == y;
}
}
}
}
//перевод текста в цифры

for (int i = 0; i != 200; i++) {

if (primal_text_char[i] == 0) {
break;
}








temp = primal_text_int[i];
temp_1 = temp + key_int[2];
if (temp_1 > 25) {
temp_1 = temp_1 - 26;
}

temp_1 = rotor1[temp_1];
//переход с обычного на 1 ротор




temp_key = key_int[2] + key_int[1];
if (temp_key > 25) {
temp_key = temp_key - 26;
}

temp_2 = temp_1 + temp_key;
if (temp_2 > 25) {
temp_2 = temp_2 - 26;
}

temp_2 = rotor2[temp_2];
//переход с 1 на 2


temp_key = key_int[0] - key_int[1];

temp_3 = temp_2 + temp_key;
if
(temp_3 > 25) {
temp_3 = temp_3 - 26;
}
if(temp_3<0){
    temp_3=temp_3*(-1);
}

temp_3 = rotor3[temp_3];
//переход со 2 на 3



temp_4 = temp_3 - key_int[0];
if (temp_4 < 0) {
temp_4 = temp_4 * (-1);
}


temp_4 = refl[temp_4];
//переход с 3 на рефлектор


temp_5 = temp_4 + key_int[0];
if (temp_5 > 25) {
temp_5 = temp_5 - 26;
}



for (int g = 0; g != 26; g++) {
if (temp_5==rotor3[g]) {
temp_5 = g;
}
}
//переход с рефлектра на 3



temp_key = key_int[0] - key_int[1];


temp_6 = temp_5 - temp_key;
if (temp_6 < 0) {
temp_6 = temp_6 * (-1);
}
if(temp_6>25){
    temp_6=temp_6-26;
}


for (int g = 0; g != 26; g++) {
if (temp_6 == rotor2[g]) {
temp_6 = g;
}
}
//переход с 3 на 2


temp_key = key_int[1] - key_int[2];


temp_7 = temp_6 - temp_key;
if (temp_7 < 0) {
temp_7 = temp_7 * (-1);
}
if(temp_7>25){
    temp_7=temp_7-26;
}

for (int g = 0; g != 26; g++) {
if (temp_7 == rotor1[g]) {
temp_7 = g;
}
}
//переход с 2 на 1


temp_8 = temp_7 - key_int[2];
if (temp_8 < 0) {
temp_8 = temp_8 * (-1);
}

cout << bykv[temp_8];
//вывод результата



{
temp_rotate = 0;
key_int_temp_1 = key_int[2];
key_int_temp_2 = key_int[1];
key_int_temp_3 = key_int[0];

key_int_temp_1 = key_int_temp_1 + 1;
key_int[2] = key_int[2] + 1;
if (key_int_temp_1 > 25) {
key_int_temp_1 = key_int_temp_1 - 26;
temp_rotate = 1;
}
if ((key_int_temp_1 == key_int[2]) && (temp_rotate == 1)) {
key_int_temp_2 = key_int_temp_2 + 1;
key_int[1] = key_int[1] + 1;
temp_rotate = 0;
if (key_int_temp_2 > 25) {
key_int_temp_2 = key_int_temp_2 - 26;
temp_rotate = 1;
}
}
if ((key_int_temp_2 == key_int[1]) && (temp_rotate == 1)) {
key_int_temp_3 = key_int_temp_3 + 1;
key_int[0] = key_int[0] + 1;
temp_rotate = 0;
if (key_int_temp_3 > 25) {
key_int_temp_3 = key_int_temp_3 - 26;
temp_rotate = 1;
}
}
if ((key_int_temp_3 == key_int[0]) && (temp_rotate == 1)) {
temp_rotate = 0;
}
}
//прокрутка роторов



}



}






}


void decode() {

}




int main() {
srand(time(NULL));
setlocale(LC_ALL, "English");
cout << "Hello, it's simulator Enigma,let's get to work!";


while (checking_ready == 1) {

cout <<endl<< "You want to encode?,Type 'e' to encode,or type 'x' to close the programm" << endl;
cin >> cheking_en_de_code;

if (cheking_en_de_code == 'x') {
break;
}

switch (cheking_en_de_code) {
case 'e': {checking_key=1; encode(); break; }
default:cout << endl << "I cannot read your answer,please try again" << endl;

}

}
}
