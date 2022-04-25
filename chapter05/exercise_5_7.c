int readlines(char *lineptr[], int maxlines, int maxlen) {
    int num_lines = 0;
    int len;
    char probe[10];

    while (
        num_lines < maxlines
        && (len = getline(lineptr[num_lines], maxlen))
    )
    {
        if (lineptr[num_lines][len] == '\n') {
            lineptr[num_lines][len] = '\0';
        }

        num_lines++;
    }

    if (num_lines >= maxlines && getline(probe, sizeof(probe))) {
        return -1;
    } else {
        return num_lines;
    }
}

