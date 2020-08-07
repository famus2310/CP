char text[5 * N];
ll prefix[5 * N];
ll len;
 
ll solve() {
	prefix[0] = -1;
	for (int i = 1, j = -1; i < len; i++) {
		while (j != -1 && text[j + 1] != text[i])
			j = prefix[j];
		if (text[j + 1] == text[i])
			j++;
		prefix[i] = j;
	}
	return (prefix[len - 1] + 1);
}
