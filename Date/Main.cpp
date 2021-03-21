#include "Date.h"

int main() {

	Date* d = new Date("01:01:2001");
	cin >> *d;
	cout <<( *d );
}