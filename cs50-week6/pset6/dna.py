import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    file = open(sys.argv[1], "r")
    reader = csv.DictReader(file)
    # get the names of the headers, as a list
    headers = reader.fieldnames

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    num_subseq = {}
    for subseq in headers[1:]:
        key = subseq
        num_subseq[subseq] = longest_match(sequence, subseq)

    # TODO: Check database for matching profiles
    sample_is_match = False
    for row in reader:
        row_match = True
        for subseq in num_subseq:
            # csv files are read as string, so it cannot be compared with numbers. Need to convert
            # strings to numbers.
            if int(row[subseq]) != num_subseq[subseq]:
                row_match = False
                break
        if row_match == True:
            sample_is_match = True
            print(row['name'])
       # if all(int(row[subseq]) == num_subseq[subseq] for subseq in num_subseq):
          #  print(row["name"])
          #  match = True
    if sample_is_match == False:
        print("No match.")

    file.close()
    return


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
