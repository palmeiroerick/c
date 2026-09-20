int is_upper(const char *str) {
    int i = 0;

    while (str[i]) {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
        i++;
    }

    return 1;
}