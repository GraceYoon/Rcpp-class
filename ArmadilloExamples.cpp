#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;

// [[Rcpp::export]]
arma::mat matrix_mult(const arma::mat& X, const arma::mat& Y) {
  int m = X.n_rows;
  int n = Y.n_cols;
  arma::mat Z(m,n);
  Z = X * Y;
  return Z;
}

// Compute coefficients and their standard error
// during multiple linear regression given a
// design matrix X containing N observations with
// P regressors and a vector y containing of
// N responses
// [[Rcpp::export]]
Rcpp::List fastLm(const arma::mat& X,
                  const arma::colvec& y) { 
  // Dimension information
  int n = X.n_rows, p = X.n_cols;
  // Fit model y ~ X
  arma::colvec coef = arma::solve(X, y); 
  // Compute the residuals
  arma::colvec res  = y - X*coef;
  // Estimated variance of the random error
  double s2 = std::inner_product(res.begin(), res.end(), res.begin(), 0.0) / (n - p);
  // Standard error matrix of coefficients
  arma::colvec std_err = arma::sqrt(s2 * arma::diagvec(arma::pinv(X.t()*X)));
  // Create named list with the above quantities
  return Rcpp::List::create( Rcpp::Named("coefficients") = coef, Rcpp::Named("stderr") = std_err, Rcpp::Named("df.residual") = n - p );
}
