#include <cstdio>
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

#define TAILLE_MAX 30

unsigned int mots_vers_pts(const char* mot);

int main(void)
{
    unsigned int nb_pts = 0;
    char buffer[TAILLE_MAX];
    while (1)
    {
        scanf("%s", buffer);

        if (strcmp(buffer, "*") == 0)
            break;

        nb_pts += mots_vers_pts(buffer);
    }
    std::cout << nb_pts;

    return 0;
}


unsigned int mots_vers_pts(const char* mot)
{
    size_t taille_mot = strnlen(mot, TAILLE_MAX);
    if (taille_mot >= 8) {
        return 11;
    }
    switch (taille_mot) {
    case 0:
    case 1:
    case 2: return 0;
    case 3:
    case 4: return 1;
    case 5: return 2;
    case 6: return 3;
    case 7: return 5;
    default: return 0;
    }
}
