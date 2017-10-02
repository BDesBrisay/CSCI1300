/*
Author: Bryce DesBrisay
Recitation: CSCI-1300 Arcadia 209
Assignment 4 - Assignment4.cpp
*/

#include <iostream>
#include <string>
using namespace std;

/*
This function compares the two parameter sequences and returns a score of how
similar they are to eachother
*/

float similarityScore(string seq1, string seq2) {
  float seq1Len = seq1.length();
  float seq2Len = seq2.length();
  float mismatches = 0.0;

  if (seq1Len != seq2Len) {
    return 0;
  }

  int i = 0;
  while ( i < seq1Len) {
    if (seq1[i] != seq2[i]) {
      mismatches++;
    }
    i++;
  }

  return (seq1Len - mismatches) / seq1Len;
}

/*
This function counts the number of times a subtring is found in a genome and it
has a higher similarity score than the provided minimum score. Then it returns
the number of matches
*/

int countMatches(string genome, string seq, float minScore) {
  int matches = 0;
  int seqLen = seq.length();

  int pos = 0;
  while (pos <= genome.length() - seqLen) {
    float simScore = similarityScore(genome.substr(pos, seqLen), seq);
    if (simScore >= minScore) {
      matches++;
    }
    pos++;
  }

  return matches;
}

/*
This function finds and returns the highest similarity score between a sequence
a genome by running through the genome and comparing the similarity scores of
the sequence at every point
*/

float findBestMatch(string genome, string seq) {
  float bestMatch = 0.0;

  int pos = 0;
  while (pos < genome.length()) {
    float simScore = similarityScore(genome.substr(pos, seq.length()), seq);
    if (simScore > bestMatch) {
      bestMatch = simScore;
    }
    pos++;
  }

  return bestMatch;
}

/*
This function compares a sequence to three different genomes and returns the
genome which the sequence is most similar to
*/

int findBestGenome(string One, string Two, string Three, string seq) {
  float OneScore = findBestMatch(One, seq);
  float TwoScore = findBestMatch(Two, seq);
  float ThreeScore = findBestMatch(Three, seq);

  if (OneScore > TwoScore && OneScore > ThreeScore) {
    return 1;
  } else if (TwoScore > OneScore && TwoScore > ThreeScore) {
    return 2;
  } else if (ThreeScore > OneScore && ThreeScore > TwoScore) {
    return 3;
  } else {
    return 0;
  }
}

/*
This function returns the DNA complement sequence of a given sequence
*/

string complementSequence(string seq) {
  string complement = "";

  int i = 0;
  while (i < seq.length()) {
    if (seq[i] == 65) {
      complement += "T";
    } else if (seq[i] == 67) {
      complement += "G";
    }
    i++;
  }

  return complement;
}

/*
This functon returns the reverse of the compliment sequence that we got from the
previous function
*/

string reverseComplementSequence(string seq) {
  string complement = complementSequence(seq);
  string reverseSeq = "";

  int i = complement.length();
  while (i > 0) {
    reverseSeq += complement[i];
    i--;
  }

  return reverseSeq;
}
