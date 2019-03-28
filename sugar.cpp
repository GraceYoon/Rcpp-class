#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector plus(NumericVector x, NumericVector y){
  NumericVector res = x + y;
  return res;
}

// [[Rcpp::export]]
IntegerVector seq_cpp(int n){
  IntegerVector l = seq_len(n);
  return l; 
}