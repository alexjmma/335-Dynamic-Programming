///////////////////////////////////////////////////////////////////////////////
// dynamic_subsequence.hpp
//
// Dynamic programming algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

std::string dynamic_longest_substring(const std::string& a,
                                      const std::string& b) {
  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function.
  std::string best = "";
  int len1 = a.length();
  int len2 = b.length();

  std::string** A = new std::string*[len1 + 1];
  for(int i = 0; i < len1 + 1; ++i) {
    A[i] = new std::string[len2 + 1];
  }

  for (int j = 0; j <= len1; j++){
    A[j][0] = "";
  }

  for (int k = 0; k <= len2; k++){
    A[0][k] = "";
  }

  for (int i = 1; i <= len1; i++){
    for (int j = 1; j <= len2; j++){
        if(a[i - 1] != b[j - 1]){
          A[i][j] = "";
        }
        else
        {
          A[i][j] = A[i -1][j - 1] + a[i -1];
          int blen = best.length();
          int tlen = A[i][j].length();
          if(tlen > blen){
            best = A[i][j];
          }
        }
    }
  }

  return best;
}

std::string dynamic_longest_subsequence(const std::string& a,
                                        const std::string& b) {

  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function.
  std::string best = "";
  int len1 = a.length();
  int len2 = b.length();

  std::string** A = new std::string*[len1 + 1];
  for(int i = 0; i < len1 + 1; ++i) {
    A[i] = new std::string[len2 + 1];
  }

  for (int j = 0; j <= len1; j++){
    A[j][0] = "";
  }

  for (int k = 0; k <= len2; k++){
    A[0][k] = "";
  }

  for (int i = 1; i <= len1; i++){
    for (int j = 1; j <= len2; j++){
        if(a[i - 1] == b[j - 1]){
          A[i][j] = A[i -1][j - 1] + a[i - 1];
        }
        else if(A[i -1][j].length() > A[i][j - 1].length())
        {
          A[i][j] = A[i -1][j];
        }
        else
        {
          A[i][j] = A[i][j - 1];
        }
        best = A[i][j];
    }
  }

  return best;
}
