# TODO
from cs50 import get_string

"""Formula dada pelo CS50
index = 0.0588 * L - 0.296 * S - 15.8
L is the average number of letters per 100 words in the text,
and S is the average number of sentences per 100 words in the text."""


def main():
    letras = 0,
    palavras = 0,
    frases = 0,
    L = 0.0,
    S = 0.0,
    res = 0,

    # input do usuario
    txt = get_string("Texto: ")

    letras = count_letters(txt)
    palavras = count_words(txt)
    frases = count_sentences(txt)

    L = (letras / palavras) * 100
    S = (frases / palavras) * 100

    # resultado da conta arredeondado pela funcao round
    res = round(0.0588 * L - 0.296 * S - 15.8)

    if res < 1:
        print("Before Grade 1")
    elif res >= 16:
        print("Grade 16+")
    else:
        print("Grade", res)


def count_letters(txt):
    letras = 0

    for i in txt:
        if i.isalpha():
            letras += 1
    return letras


def count_words(txt):
    palavras = 1

    """palavras foi iniciado = 1, para incluir a primeira palavra, ja que na especificação do projeto eles falam q n devemos
    nos preocupar com o texto comecando com espacos, para o programa rodar normalmente, basta colocar palavras = 0 e comecar o texto com espaco."""

    for i in txt:
        if i == ' ':
            palavras += 1

    return palavras


def count_sentences(txt):
    frases = 0

    for i in txt:
        if i == '!' or i == '.' or i == '?':
            frases += 1

    return frases


main()