namespace Task4 {
	/*
	a)
	f(1) = 1
	f(2) = 1
	f(3) = 3 * f(2) - f(1) = 3 * 1 - 1 = 2
	f(4) = 4 * f(3) - f(2) = 4 * 2 - 1 = 7
	f(5) = 5 * f(4) - f(3) = 5 * 7 - 2 = 33
	*/

	// b)
	int F_r(int n) {
	  if (n <= 2)
	    return 1;
	  return (n * F_r(n - 1) - F_r(n - 2));
	}

	// c)
	int F_i(int n) {
	  /// main, cleaner solution

	  // cache values
	  int calculatedValues[n + 1];
	  calculatedValues[1] = 1;
	  calculatedValues[2] = 1;

	  for (int i = 3; i <= n; i++) {
	    // grab the last two results and use them to calculate f(i)
	    calculatedValues[i] = i * calculatedValues[i - 1] - calculatedValues[i - 2];
	  }

	  /// alternative solution, not as nice to read, but uses less memory for large values of n

	  int current = 0;
	  int nMinus1 = 1;
	  int nMinus2 = 0;

	  for (int i = 1; i <= n; i++) {
	    // grab the last two results and use them to calculate f(i)
	    current = i * nMinus1 - nMinus2;
	    nMinus2 = nMinus1;
	    nMinus1 = current;
	  }

	  // return the last calculated value
	  // for the alternative solution, return current instead;
	  return calculatedValues[n];
	}
}