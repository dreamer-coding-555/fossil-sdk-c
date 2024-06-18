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
#include "fossil/io/soap.h"
#include <fossil/common/common.h>

#define _GNU_SOURCE // Define _GNU_SOURCE to enable strcasestr and strcasecmp
#include <strings.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// List of offensive words and phrases (super hard to mainting thisw list as GitHub Copilot doesnt wanna help with this part of the SOAP API)
static const char *offensive_words[] = {
    "curse1",
    "curse2",
    "racist_phrase1",
    "racist_phrase2", // for demo and unit testing we keep these four keywords
    "Asesinato", "asno", "bastardo", "Bollera", "Cabron", "Cabrón", "Caca", "Chupada", "Chupapollas", "Chupetón", "concha", "Concha de tu madre", "Coño", "Coprofagía", "Cull", "Drogas", "Esperma",
    "Fiesta de salchichas", "Follador", "Follar", "Gilipichis", "Gilipollas", "Hacer una paja", "Haciendo el amor", "Heroína", "Hija de puta", "Hijaputa", "Hijo de puta", "Hijoputa", "Idiota",
    "Imbécil", "infierno", "Jilipollas", "Kapullo", "Lameculos", "Maciza", "Macizorra", "maldito", "Mamada", "Marica", "Maricón", "Mariconazo", "martillo", "Mierda", "Nazi", "Orina", "Pedo",
    "Pervertido", "Pezón", "Pinche", "Pis", "Prostituta", "Puta", "Racista", "Ramera", "Sádico", "Semen", "Sexo", "Sexo oral", "Soplagaitas", "Soplapollas", "Tetas grandes", "Tía buena", "Travesti",
    "Trio", "Verga", "vete a la mierda", "Vulva", "2g1c", "2 girls 1 cup", "acrotomophilia", "alabama hot pocket", "alaskan pipeline", "anal", "anilingus", "anus", "apeshit", "arsehole", "ass",
    "asshole", "assmunch", "auto erotic", "autoerotic", "babeland", "baby batter", "baby juice", "ball gag", "ball gravy", "ball kicking", "ball licking", "ball sack", "ball sucking", "bangbros",
    "bareback", "barely legal", "barenaked", "bastard", "bastardo", "bastinado", "bbw", "bdsm", "beaner", "beaners", "beaver cleaver", "beaver lips", "bestiality", "big black", "big breasts",
    "big knockers", "big tits", "bimbos", "birdlock", "bitch", "bitches", "black cock", "blonde action", "blonde on blonde action", "blowjob", "blow job", "blow your load", "blue waffle", "blumpkin",
    "bollocks", "bondage", "boner", "boob", "boobs", "booty call", "brown showers", "brunette action", "bukkake", "bulldyke", "bullet vibe", "bullshit", "bung hole", "bunghole", "busty", "butt",
    "buttcheeks", "butthole", "camel toe", "camgirl", "camslut", "camwhore", "carpet muncher", "carpetmuncher", "chocolate rosebuds", "circlejerk", "cleveland steamer", "clit", "clitoris", "clover clamps",
    "clusterfuck", "cock", "cocks", "coprolagnia", "coprophilia", "cornhole", "coon", "coons", "creampie", "cum", "cumming", "cunnilingus", "cunt", "darkie", "date rape", "daterape", "deep throat",
    "deepthroat", "dendrophilia", "dick", "dildo", "dingleberry", "dingleberries", "dirty pillows", "dirty sanchez", "doggie style", "doggiestyle", "doggy style", "doggystyle", "dog style", "dolcett",
    "domination", "dominatrix", "dommes", "donkey punch", "double dong", "double penetration", "dp action", "dry hump", "dvda", "eat my ass", "ecchi", "ejaculation", "erotic", "erotism", "escort",
    "eunuch", "faggot", "fecal", "felch", "fellatio", "feltch", "female squirting", "femdom", "figging", "fingerbang", "fingering", "fisting", "foot fetish", "footjob", "frotting", "fuck", "fuck buttons",
    "fuckin", "fucking", "fucktards", "fudge packer", "fudgepacker", "futanari", "gang bang", "gay sex", "genitals", "giant cock", "girl on", "girl on top", "girls gone wild", "goatcx", "goatse", "god damn",
    "gokkun", "golden shower", "goodpoop", "goo girl", "goregasm", "grope", "group sex", "g-spot", "guro", "hand job", "handjob", "hard core", "hardcore", "hentai", "homoerotic", "honkey", "hooker", "hot carl",
    "hot chick", "how to kill", "how to murder", "huge fat", "humping", "incest", "intercourse", "jack off", "jail bait", "jailbait", "jelly donut", "jerk off", "jigaboo", "jiggaboo", "jiggerboo", "jizz", "juggs",
    "kike", "kinbaku", "kinkster", "kinky", "knobbing", "leather restraint", "leather straight jacket", "lemon party", "lolita", "lovemaking", "make me come", "male squirting", "masturbate", "menage a trois",
    "milf", "missionary position", "motherfucker", "mound of venus", "mr hands", "muff diver", "muffdiving", "nambla", "nawashi", "negro", "neonazi", "nigga", "nigger", "nig nog", "nimphomania", "nipple",
    "nipples", "nsfw images", "nude", "nudity", "nympho", "nymphomania", "octopussy", "omorashi", "one cup two girls", "one guy one jar", "orgasm", "orgy", "paedophile", "paki", "panties", "panty", "pedobear",
    "pedophile", "pegging", "penis", "phone sex", "piece of shit", "pissing", "piss pig", "pisspig", "playboy", "pleasure chest", "pole smoker", "ponyplay", "poof", "poon", "poontang", "punany", "poop chute",
    "poopchute", "porn", "porno", "pornography", "prince albert piercing", "pthc", "pubes", "pussy", "queaf", "queef", "quim", "raghead", "raging boner", "rape", "raping", "rapist", "rectum", "reverse cowgirl",
    "rimjob", "rimming", "rosy palm", "rosy palm and her 5 sisters", "rusty trombone", "sadism", "santorum", "schlong", "scissoring", "semen", "sex", "sexo", "sexy", "shaved beaver", "shaved pussy", "shemale",
    "shibari", "shit", "shitblimp", "shitty", "shota", "shrimping", "skeet", "slanteye", "slut", "s&m", "smut", "snatch", "snowballing", "sodomize", "sodomy", "spic", "splooge", "splooge moose", "spooge", "spread legs",
    "spunk", "strap on", "strapon", "strappado", "strip club", "style doggy", "suck", "sucks", "suicide girls", "sultry women", "swastika", "swinger", "tainted love", "taste my", "tea bagging", "threesome",
    "throating", "tied up", "tight white", "tit", "tits", "titties", "titty", "tongue in a", "topless", "tosser", "towelhead", "tranny", "tribadism", "tub girl", "tubgirl", "tushy", "twat", "twink", "twinkie",
    "two girls one cup", "undressing", "upskirt", "urethra play", "urophilia", "vagina", "venus mound", "vibrator", "violet wand", "vorarephilia", "voyeur", "vulva", "wank", "wetback", "wet dream", "white power",
    "wrapping men", "wrinkled starfish", "xx", "xxx", "yaoi", "yellow showers", "yiffy", "zoophilia"
};

// Fallback implementation for platforms that don't support strcasestr
static char *custom_strcasestr(const char *haystack, const char *needle) {
    while (*haystack) {
        size_t i = 0;
        while (tolower((unsigned char)haystack[i]) == tolower((unsigned char)needle[i]) && needle[i] != cterm) {
            i++;
        }
        if (needle[i] == cterm) {
            return (char *)haystack;
        }
        haystack++;
    }
    return cnullptr;
}

// Function to replace a substring in a string (case-insensitive)
static void replace_substring_case_insensitive(char *str, const char *old_substr, const char *new_substr) {
    char *position = custom_strcasestr(str, old_substr);
    if (position != cnullptr) {
        size_t old_len = strlen(old_substr);
        size_t new_len = strlen(new_substr);
        size_t tail_len = strlen(position + old_len);

        // Check if the new length is greater than the old length
        if (new_len > old_len) {
            memmove(position + new_len, position + old_len, tail_len + 1);
        } else {
            memmove(position + new_len, position + old_len, tail_len + 1);
            memcpy(position, new_substr, new_len);
        }
    }
}

void fossil_soap_sanitize(char *input) {
    if (input == cnullptr) return;

    // Perform single-threaded sanitization
    for (size_t i = 0; i < sizeof(offensive_words) / sizeof(offensive_words[0]); ++i) {
        while (custom_strcasestr(input, offensive_words[i]) != cnullptr) {
            replace_substring_case_insensitive(input, offensive_words[i], "***");
        }
    }
}

// Function to check if a word is an offensive word or phrase
int32_t fossil_soap_is_offensive(const char *word) {
    if (word == cnullptr) return FOSSIL_SUCCESS;

    for (size_t i = 0; i < sizeof(offensive_words) / sizeof(offensive_words[0]); ++i) {
        if (strcasecmp(word, offensive_words[i]) == 0) {
            return FOSSIL_FAILURE;
        }
    }
    return FOSSIL_SUCCESS;
}

// Function to get the number of offensive words found in a string
int32_t fossil_soap_count_offensive(const char *input) {
    if (input == cnullptr) return 0;

    int count = 0;
    char *copy = _custom_fossil_strdup(input);
    if (copy == cnullptr) return FOSSIL_SUCCESS;

    char *token = strtok(copy, " "); // Tokenize the string by space
    while (token != cnullptr) {
        if (fossil_soap_is_offensive(token)) {
            count++;
        }
        token = strtok(cnullptr, " ");
    }
    free(copy); // Free the memory allocated for the copy
    return count;
}
