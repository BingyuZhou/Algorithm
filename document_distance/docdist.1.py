# docdist1.py
# improved version of document distance with hashtable
from __future__ import division
from __future__ import print_function
import cProfile
import math
# math.acos(x) is the arccosine of x.
# math.sqrt(x) is the square root of x.

import string
# string.join(words,sep) takes a given list of words,
#    and returns a single string resulting from concatenating them
#    together, separated by the string sep .
# string.lower(word) converts word to lower-case

import sys
import time


##################################
# Operation 1: read a text file ##
##################################
def read_file(filename):
    """ 
    Read the text file with the given filename;
    return a list of the lines of text in the file.
    """
    try:
        fp = open(filename)
        L = fp.readlines()
    except IOError:
        print("Error opening or reading input file: ", filename)
        sys.exit()
    return L


#################################################
# Operation 2: split the text lines into words ##
#################################################
def get_words_from_line_list(L):
    """
    Parse the given list L of text lines into words.
    Return list of all words found.
    """

    word_list = []
    for line in L:
        words_in_line = get_words_from_string(line)
        word_list.extend(words_in_line)
    return word_list


translation_table = str.maketrans(
    string.punctuation + string.ascii_uppercase,
    " " * len(string.punctuation) + string.ascii_lowercase)


def get_words_from_string(line):
    """
    Return a list of the words in the given input string,
    converting each word to lower-case.

    Input:  line (a string)
    Output: a list of strings 
              (each string is a sequence of alphanumeric characters)
    """

    line = line.translate(translation_table)
    word_list = line.split()
    return word_list


##############################################
# Operation 3: count frequency of each word ##
##############################################
def count_frequency(word_list):
    """
    Return a list giving pairs of form: (word,frequency)
    """
    L = {}
    for word in word_list:
        if word in L:
            L[word] += 1
        else:
            L[word] = 1
    L = sorted(L.items())
    return L


###############################################################
# Operation 4: sort words into alphabetic order             ###
###############################################################
def insertion_sort(A):
    """
    Sort list A into order, in place.

    From Cormen/Leiserson/Rivest/Stein,
    Introduction to Algorithms (second edition), page 17,
    modified to adjust for fact that Python arrays use 
    0-indexing.
    """
    for j in range(len(A)):
        key = A[j]
        # insert A[j] into sorted sequence A[0..j-1]
        i = j - 1
        while i > -1 and A[i] > key:
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
    return A


#############################################
## compute word frequencies for input file ##
#############################################
def word_frequencies_for_file(filename):
    """
    Return alphabetically sorted list of (word,frequency) pairs 
    for the given file.
    """

    line_list = read_file(filename)
    word_list = get_words_from_line_list(line_list)
    freq_mapping = count_frequency(word_list)

    print("File", filename, ":")
    print(len(line_list), "lines,")
    print(len(word_list), "words,")
    print(len(freq_mapping), "distinct words")

    return freq_mapping


def inner_product(L1, L2, domain):
    """
    Inner product between two vectors, where vectors
    are represented as alphabetically sorted (word,freq) pairs.

    Example: inner_product([["and",3],["of",2],["the",5]],
                           [["and",4],["in",1],["of",1],["this",2]]) = 14.0 
    """
    sum = 0.0
    i = 0
    j = 0
    while i < len(L1) and j < len(L2):
        # L1[i:] and L2[j:] yet to be processed
        if L1[i][0] in domain:
            if (L2[j][0] == L1[i][0]):
                sum += L1[i][1] * L2[j][1]
                i += 1
                j += 1
            else:
                j += 1
        else:
            i += 1
    return sum


def vector_angle(L1, L2):
    """
    The input is a dict of (word,freq) pairs, sorted alphabetically.

    Return the angle between these two vectors.
    """
    s1 = set()
    s2 = set()
    for l in L1:
        s1.add(l[0])
    for l in L2:
        s2.add(l[0])
    domain = s1.intersection(s2)
    numerator = inner_product(L1, L2, domain)
    denominator = math.sqrt(
        inner_product(L1, L1, s1) * inner_product(L2, L2, s2))
    return math.acos(numerator / denominator)


def main():
    start = time.time()

    if len(sys.argv) != 3:
        print("Usage: docdist1.py filename_1 filename_2")
    else:
        filename_1 = sys.argv[1]
        filename_2 = sys.argv[2]
        sorted_word_list_1 = word_frequencies_for_file(filename_1)
        sorted_word_list_2 = word_frequencies_for_file(filename_2)
        distance = vector_angle(sorted_word_list_1, sorted_word_list_2)
        print("The distance between the documents is: %0.6f (radians)" %
              distance)
    print("computation time: {}s ".format(time.time() - start))


if __name__ == "__main__":
    cProfile.run("main()")
