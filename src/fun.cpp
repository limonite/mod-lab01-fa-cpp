// Copyright 2022 UNN-IASR
#include "fun.h"
#include "math.h"
#include "ctype.h"

unsigned int faStr1(const char* str) {
    int count = 0;
    bool flagInWord = false;
    bool flagDigits = false;
    int i = 0;
    while (str[i] != '\0') {
        if (!flagInWord && str[i] != ' ') {
            flagInWord = true;
            flagDigits = isdigit(str[i]);
        } else if (flagInWord && str[i] != ' ') {
            if (isdigit(str[i]))
                flagDigits = true;
        }
        if (flagInWord && (str[i] == ' ' || str[i + 1] == '\0')) {
            if (!flagDigits)
                count++;
            flagDigits = false;
            flagInWord = false;
        }

        i++;
    }
    return count;
}
unsigned int faStr2(const char* str) {
    int count = 0;
    bool flagInWord = false;
    bool flagGood = true;
    int i = 0;
    while (str[i] != '\0') {
        if (!flagInWord && str[i] != ' ') {
            flagInWord = true;
            flagGood = isupper(str[i]);
        } else if (flagInWord && str[i] != ' ') {
            if (!islower(str[i]))
                flagGood = false;
        }
        if (flagInWord && (str[i] == ' ' || str[i + 1] == '\0')) {
            if (flagGood)
                count++;
            flagGood = true;
            flagInWord = false;
        }
        i++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    int wCount = 0;
    int symbCount = 0;
    bool flagInWord = false;
    int i = 0;
    while (str[i] != '\0') {
        if (!flagInWord && str[i] != ' ') {
            flagInWord = true;
            wCount++;
            symbCount++;
        } else if (flagInWord && str[i] != ' ') {
            symbCount++;
        }
        if (flagInWord && (str[i] == ' ' || str[i + 1] == '\0'))
            flagInWord = false;
        i++;
    }
    return static_cast<int>(symbCount/wCount);
}
