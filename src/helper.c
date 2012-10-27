int read2(unsigned char *c) {
	return *c << 8 | *(c+1);
}

int read3(unsigned char *c) {
	return *c << 16 | *(c+1) << 8 | *(c+2);
}
