int mod(int x, int y) {
	int q = x / y;
	int r = x - q * y;
	return r;
}

int round_up(int x, int y) {
	int q = ( x + ( y - 1)) / y;
	int m = q * y;
	return m; 
}

int round_down(int x, int y) {
	int q = x / y;
	int m = q * y;
	return m;
}

int mod_pow2(int x, int y) { // y is power of 2
	int r = x & (y - 1);
	return r;
}

int round_up_pow2(int x, int y) {	// y is power of 2
	int m = ( x + (y-1)) & ~(y-1);
	return m;
}

int round_down_pow2(int x, int y) {	// y is power of 2
	int m = x & ~(y-1);
	return 0;
}
