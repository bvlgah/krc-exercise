unsigned rotate(unsigned x, int n) {
    return (x >> n) | (x << (sizeof(x) - n));
}

