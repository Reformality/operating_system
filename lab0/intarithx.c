int mod_pow2x(int x, int y) {
	return (y & (y-1)) ? -1 : x & (y - 1);
}

int round_up_pow2x(int x, int y) {
	return (y & (y-1)) ? -1 : ( x + (y-1)) & ~(y-1);
}

int round_down_pow2x(int x, int y) {
	return (y & (y-1)) ? -1 : x & ~(y-1);
}