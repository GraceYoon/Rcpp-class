#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector cpy(NumericVector x){
  // changing outvec will affect invec
  NumericVector invec(x);
  NumericVector outvec(x);
  for (int i=0; i<invec.size(); i++) {
    outvec[i] = log(invec[i]);
  }
  
  return outvec;
}

// [[Rcpp::export]]
NumericVector cpy2(NumericVector x){
  // changing outvec will NOT affect invec
  NumericVector invec(x);
  NumericVector outvec = clone(x);
  for (int i=0; i<invec.size(); i++) {
    outvec[i] = log(invec[i]);
  }
  
  return outvec;
}
