unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return (y & ~(~0 << n)) | (x & ((~0 << p) | ~(~0 << n)));
}

