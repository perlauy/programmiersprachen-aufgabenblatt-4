# Notes

int i = 5;
int& j = i; // j ist eine "Adresse"; es darf nicht ein Wert wie 5 sein.

std::vector<int> v(100, 0);
int& z = v[10];

&i = the address from i;
int* k = &i; would be valid, BUT DON'T!

int* k = new int{5};