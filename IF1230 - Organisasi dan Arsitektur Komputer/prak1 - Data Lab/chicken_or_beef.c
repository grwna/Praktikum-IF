int chicken_or_beef(int chicken, int beef) {
    return (chicken >> 4) & 0x0f | (beef << 1) & 0x0f;
}
