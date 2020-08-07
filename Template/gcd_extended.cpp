LL gcdExtended(LL a, LL b, LL& x, LL& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL xtmp, ytmp;
	LL g = gcdExtended(b % a, a, xtmp, ytmp);
	x = ytmp - (b / a) * xtmp;
	y = xtmp;
	return g;
}