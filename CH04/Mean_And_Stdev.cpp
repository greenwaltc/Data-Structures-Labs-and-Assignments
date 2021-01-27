/** Program to compute the mean and standard deviation of a 
    sequence of numbers from an input file.
*/

#include <iostream>   //Define cout and cerr
#include <istream>    //Define input operations
#include <ostream>    //Define output operations
#include <fstream>    //Define file streams
#include <iterator>
#include <algorithm>  //Define standard algorithms
#include <numeric>    //Define numeric algorithms
#include <vector>     //Define the vector class
#include <cmath>      //Define math operations

using namespace std;
/** Function class to compute the square of 
    the difference of a value from the mean.
*/
class Square_Diff {
private:
  /** The mean to be subtracted from each value. */ 
  double mean;
  
public:
  /** Construct a Square_Diff object remembering
      the value of the mean.
      @param m The mean to be remembered
  */
  Square_Diff(double m) : mean (m) {}
  
  /** Subtract the mean from the input value and
      return the square of the difference.
      @param x The input value
      @return (x - mean) squared
  */
  double operator()(double x) {
    double diff = x - mean;
    return diff * diff;
  }
};

/** Main function to read a sequence of double values
    from an input file and compute the mean and standard 
    deviation
    @param argc The count of the command line parameters
    @param argv The array of command line parameters: argv[1]
    is the name of the input file.
*/
int main(int argc, char* argv[])
{
  // Validate command line and open input file
  if (argc < 2) {
    cerr << "Usage Mean_And_Stdev <input file>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  // Declare an input_stream_iterator and attach it to in
  istream_iterator<double> ins(in);
  istream_iterator<double> eof;
  // Declare vector to hold the input.
  vector<double> input_data;
  // Read data
  copy(ins, eof, back_inserter(input_data));
  // Compute the sum of the input.
  double sum = 
    accumulate(input_data.begin(), input_data.end(), 0.0);
  // Compute the mean.
  double mean = sum / input_data.size();
  // Load the square deviation values.
  transform(input_data.begin(), input_data.end(), 
	    input_data.begin(), Square_Diff(mean));
  // Compute the sum of the squared deviations
  double sum_sq_dev = 
    accumulate(input_data.begin(), input_data.end(), 0.0);
  // Compute the standard deviation
  double stdev = sqrt(sum_sq_dev / (input_data.size() - 1.0));
  // Output result
  cout << "Mean: " << mean << " stdev: " << stdev << "\n";
  // Exit
  return 0;
}

