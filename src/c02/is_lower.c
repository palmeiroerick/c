int is_lower(const char *str) {
    int i = 0;

    while (str[i]) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
        i++;
    }

    return 1;
}