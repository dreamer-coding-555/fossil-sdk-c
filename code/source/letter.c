/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/string/letter.h"
#include "fossil/common/common.h"
#include "fossil/string/manip.h"
#include <stdlib.h>
#include <ctype.h>

enum {
    _FOSSIL_LETTER_DEFAULT_VALUE = 0
};

// Return the character at the specified index in a null-terminated C string
cletter fossil_cletter_at(const_cletter *str, size_t index) {
    if (!str || index >= fossil_cstr_length(str)) {
        return cterminator; // Return null character for out-of-bounds access or null pointer
    }
    return str[index];
}

// Return the wide character at the specified index in a null-terminated wide C string
wletter fossil_wletter_at(const_wletter *str, size_t index) {
    if (!str || index >= fossil_wstr_length(str)) {
        return wterminator; // Return null wide character for out-of-bounds access or null pointer
    }
    return str[index];
}

// Return the byte at the specified index in a byte string
bletter fossil_bletter_at(const_bletter *str, size_t index) {
    if (!str || index >= fossil_bstr_length(str)) {
        return cterminator; // Return null character for out-of-bounds access or null pointer
    }
    return str[index];
}

// cletter functions
int16_t fossil_cletter_is_alpha(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int16_t fossil_cletter_is_digit(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ch >= '0' && ch <= '9';
}

int16_t fossil_cletter_is_alnum(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return fossil_cletter_is_alpha(ch) || fossil_cletter_is_digit(ch);
}

int16_t fossil_cletter_is_lower(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ch >= 'a' && ch <= 'z';
}

int16_t fossil_cletter_is_upper(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ch >= 'A' && ch <= 'Z';
}

cletter fossil_cletter_to_lower(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    if (fossil_cletter_is_upper(ch)) {
        return ch + ('a' - 'A');
    }
    return ch;
}

cletter fossil_cletter_to_upper(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    if (fossil_cletter_is_lower(ch)) {
        return ch - ('a' - 'A');
    }
    return ch;
}

int16_t fossil_cletter_is_space(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isspace(ch);
}

int16_t fossil_cletter_is_punct(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ispunct(ch);
}

int16_t fossil_cletter_is_graph(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isgraph(ch);
}

int16_t fossil_cletter_is_print(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isprint(ch);
}

int16_t fossil_cletter_is_cntrl(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iscntrl(ch);
}

int16_t fossil_cletter_is_xdigit(cletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isxdigit(ch);
}

// bletter functions
int16_t fossil_bletter_is_alpha(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int16_t fossil_bletter_is_digit(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ch >= '0' && ch <= '9';
}

int16_t fossil_bletter_is_alnum(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return fossil_bletter_is_alpha(ch) || fossil_bletter_is_digit(ch);
}

int16_t fossil_bletter_is_lower(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ch >= 'a' && ch <= 'z';
}

int16_t fossil_bletter_is_upper(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ch >= 'A' && ch <= 'Z';
}

bletter fossil_bletter_to_lower(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    if (fossil_bletter_is_upper(ch)) {
        return ch + ('a' - 'A');
    }
    return ch;
}

bletter fossil_bletter_to_upper(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    if (fossil_bletter_is_lower(ch)) {
        return ch - ('a' - 'A');
    }
    return ch;
}

int16_t fossil_bletter_is_space(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isspace(ch);
}

int16_t fossil_bletter_is_punct(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return ispunct(ch);
}

int16_t fossil_bletter_is_graph(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isgraph(ch);
}

int16_t fossil_bletter_is_print(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isprint(ch);
}

int16_t fossil_bletter_is_cntrl(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iscntrl(ch);
}

int16_t fossil_bletter_is_xdigit(bletter ch) {
    if (ch == cterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return isxdigit(ch);
}

int16_t fossil_wletter_is_alpha(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswalpha(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_digit(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswdigit(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_alnum(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswalnum(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_lower(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswlower(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_upper(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswupper(ch) ? 1 : 0;
}

wletter fossil_wletter_to_lower(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return towlower(ch);
}

wletter fossil_wletter_to_upper(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return towupper(ch);
}

int16_t fossil_wletter_is_space(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswspace(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_punct(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswpunct(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_graph(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswgraph(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_print(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswprint(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_cntrl(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswcntrl(ch) ? 1 : 0;
}

int16_t fossil_wletter_is_xdigit(wletter ch) {
    if (ch == wterminator) {
        return _FOSSIL_LETTER_DEFAULT_VALUE;
    }
    return iswxdigit(ch) ? 1 : 0;
}
