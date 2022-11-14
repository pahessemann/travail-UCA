#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int moyenne(int n,...) {
	va_list ap;
	va_start(ap, n);
	int s = 0;
	for(int i=0; i<n; i++)
		s += va_arg(ap, int);
	va_end(ap);
	return s/n;
}

int main() {
	printf("%i\n", moyenne(5,7,8,9,10,11));
}
