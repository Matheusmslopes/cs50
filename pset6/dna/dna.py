import csv
import sys


def main():

    # TODO: Check for command-line usage(done)
    if len(sys.argv) != 3:
        print("Command-line error")
        sys.exit(1)

    # TODO: Read database file into a variable
    with open (sys.argv[1], "r") as arquivoBD:
        reader = csv.DictReader(arquivoBD)
        bd = [linha for linha in reader]

    # TODO: Read DNA sequence file into a variable
    with open (sys.argv[2], "r") as arquivoDNA:
        dna = arquivoDNA.read()

    # TODO: Find longest match of each STR in DNA sequence
    sequencia = {}
    for pessoa in bd[0].keys():
        if pessoa == "name":
            continue
        sequencia[pessoa] = longest_match(dna, pessoa)

    # TODO: Check database for matching profiles
    for linha in bd:
        maior = True
        for pessoa in linha.keys():
            if pessoa == "name":
                continue
            elif int(linha[pessoa]) != sequencia[pessoa]:
                maior = False
                break
        if maior:
                print(linha["name"])
                return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
