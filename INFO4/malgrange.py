#!/usr/bin/env python3

TAILLE = 6


def tableurV(mat, TV, sommet, e):
    for i in range(TAILLE):
        if mat[sommet][i] == 1 and TV[i] == -1:
            TV[i] = e
            tableurV(mat, TV, i, e + 1)


def tableurH(mat, TH, sommet, e):
    for i in range(TAILLE):
        if mat[i][sommet] == 1 and TH[i] == -1:
            TH[i] = e
            tableurH(mat, TH, i, e + 1)


def malgrange(mat, TV, TH, sommet, l, visite):
    if sommet >= TAILLE:
        return

    debut = sommet
    while debut < TAILLE and visite[debut] == -9:
        debut += 1
    if debut >= TAILLE:
        return

    for i in range(sommet, TAILLE):
        TV[i] = -1
        TH[i] = -1

    TV[debut] = 0
    TH[debut] = 0

    tableurV(mat, TV, debut, 1)
    tableurH(mat, TH, debut, 1)

    print(f"Composante {l} ==> {{", end="")
    for i in range(TAILLE):
        if TV[i] != -1 and TH[i] != -1:
            print(f" {i + 1} ", end="")
            sommet += 1
            visite[i] = -9
    print("}")

    malgrange(mat, TV, TH, debut, l + 1, visite)


if __name__ == "__main__":
    mat = [
        [0, 1, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 0, 1, 1, 0],
        [1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 1, 0],
    ]

    tv = [0] * TAILLE
    th = [0] * TAILLE
    visite = [9] * TAILLE

    print()
    print("Les composantes connexes sont :")
    print()

    malgrange(mat, tv, th, 0, 1, visite)

    print()
