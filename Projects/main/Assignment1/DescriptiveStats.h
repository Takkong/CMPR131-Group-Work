// Option 3 Descriptive Statistics design delegated to: 
// Ben Halpern
// 
// Reviewed by:
// 
// 2nd Reviewer:
// 
// How to use
//
//


#pragma once
#include "input.h"
#include <iostream>
#include "myContainers.h"
#include <cstdio>//stdio.h
#include <vector>
#include <map>
#include <fstream>

//no using namespace in header files ( best practice )

//start prototypes

//end prototypes



/// Postcondition:
// menu for descriptiveStatistics
char menuDS() {

	clrScrn();
	header("\tDescriptive Statistics -  Chapter 1 Software Development by Thien , Itz, Tony, Jose, and Ben");
	//end header

	string options[] = { "\n\t\tA> Read data file, store into a sorted dynamic array and display the data set ",
						"\n\t\tB> Minimum\t\t\t\tM> Mid Range",
						"\n\t\tC> Maximum\t\t\t\tN> Quartiles",
						"\n\t\tD> Range\t\t\t\tO> Interquartile Range",
						"\n\t\tE> Size\t\t\t\t\tP> Outliers",
						"\n\t\tF> Sum\t\t\t\t\tQ> Sum of Squares",
						"\n\t\tG> Mean\t\t\t\t\tR> Mean Absolute Deviation",
						"\n\t\tH> Median\t\t\t\tS> Root Mean Square",
						"\n\t\tI> Frequencies\t\t\t\tT> Standard Error of the Mean",
						"\n\t\tJ> Mode\t\t\t\t\tU> Coefficient of Variation",
						"\n\t\tK> Standard Deviation\t\t\tV> Relative Standard Deviation ",
						"\n\t\tL> Variance\t\t\n\t\tW> Display all results and write to an output text file",
						"\n" + string(100 , char(196)) +
						"\n\t\t0> exit "

	};//end array definition

	//loops and prints out all the options
	for (string option : options)
		std::cout << option;

	header("");

	return inputChar(string("\nOption : "), string("abcdefghijklmnopqrstuvw"));//return the user inputed char from the allowed options
}//end menuDS





/// [Class] Descriptive Statistics
///		Public:
///			
class DescriptiveStatistics {

private:

	bool *dataLoaded = nullptr;								//
	
	string* dataFile = nullptr;								//
	
	//bool *toInt = nullptr;								//
	
	LinkTList<double> dataset;								// ADT LinkList holding dataset loaded from file
	
	//bool *def = nullptr;									// if defaults were set < Consider removing, possibly redundent

	const bool debug = true;								// constant debugging variable

public:

	//##########################################################################################################
	// Default Constructor									
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: (string) fileName is an existing file containing a dataset
	/// Postcondition: 
	/// [Default Constructor]
	/// Set with a default value for testing purposes, consider removing later
	DescriptiveStatistics() {
		dataLoaded = new bool(false);
		dataFile = new string();
		//toInt = new bool(false);
		//dataset = new LinkTList<double>();

	}//end constructor

	//##########################################################################################################
	// Destructor											
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Postcondition: Deallocated memory dynamically allocated for the dataFile pointer and any other dynamically allocated member variables
	/// [Destructor]
	~DescriptiveStatistics() {

		//debugging switch:
		if (debug) { std::cout << "\n\t\t[DEBUG]: ~calling destructor\n"; }

		delete dataLoaded;
		delete dataFile;
		
	}//end destructor

	//##########################################################################################################
	// read( filename: string ): void						
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: (string) filename is an existing file containing (int) data to be read into the program
	/// Postcondition: reads, inserts, and sorts, the data inputed from the file
	void read(string filename) {

		if (debug) { std::cout << "\n\t\t[DEBUG]: filename" << filename << "\n"; }

		//precondition check:
		fstream chk = fstream(filename, ios::in);
		if (!chk) {//if the file doesn't exist return from read 
		
			std::cout << "\nERROR: File does not exist!\n";
			chk.close();
			return;

		}//end if
		else {
			chk.close();
		}//end else
		//end precondition check


		double value = double();
		fstream file = fstream(filename, ios::in);
		int items = int();
		
		//end initialization


		for (items = 1; file >> value ; items++) {
			if (debug) { std::cout << "\n\t\t[DEBUG]: value read:"<< value <<" \n"; }
			dataset.insertNode(value);
			if (file.eof())
				break;
		}//end for
		dataset.print();
		std::cout << "\n";
	}//end read

	//##########################################################################################################
	// clear(): void										
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition: N/A
	/// Postcondition: Empties the contents of the dataset 
	void clear() {

		this->dataset.clear();

	}// end clear

	//##########################################################################################################
	// ReplaceDataset( filename: string ) : void			
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precodition: N/A 
	/// Postcondition: Clears the data currently stored in the current dataset
	void replaceDataset(string fileName) {
		if (debug) { std::cout << "\n\t\t[DEBUG]: filename" << fileName << "\n"; }

		this->clear();
		read(fileName);

	}//end replaceDataset

	//##########################################################################################################
	// getMin() const : double								
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the first value in the sorted dataset
	double getMin() const {
		
		return dataset.getPos(0);
	
	}//end getMin

	//##########################################################################################################
	// getMax() const : double								
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the last value in the sorted dataset
	double getMax() const {

		return (dataset.getPos(dataset.getSize() - 1));
	
	}//end getMax

	//##########################################################################################################
	// getRange() const : double							
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	// [Requires]: getMax(), getMin()
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the range from the highest to the lowest values in the dataset
	double getRange() const {

		return (this->getMax()) - (this->getMin());
	
	}//end getRange

	//##########################################################################################################
	// getSum() const : double								
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the sum of all the values in 
	double getSum() const {

		double sum = double();
		//end initialization

		for (int i = 0; i < dataset.getSize(); i++) {
			
			//debugging
			//std::cout << dataset[i] << "+ ... =" << sum << endl;
			
			sum += dataset[i];
		}//end for
		return (sum);

	}//end getSum

	//##########################################################################################################
	// getSize() const: int									
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	/// Precondition: dataset must be instatiated
	/// Postcondition: Returns the size of the dataset
	int getSize() const {

		return dataset.getSize();
	
	}//end getSize

	//##########################################################################################################
	// getMean() const : double								
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################


	// [Requires]: getSum(), getSize()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the average ( mean ) sum / size
	double getMean() const {
	
		return ( (getSum()) / (this->getSize()) );
	
	}//end getMean

	//##########################################################################################################
	// getMedian() const : double							
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: If the size of the dataset is
	///					 odd then, the middle index is the median.
	///					 even then, the median is the average of the two middle values  
	double getMedian() const {
		
		bool isOdd = (dataset.getSize() % 2) != 0;								//boolean for better readibility
		int pos = int();														//int holding position of median
		//end initialization

		if (isOdd) {

			pos = (dataset.getSize() / 2);
			//pos--;//to account for 1 to 0 shift
			return dataset[pos];
		
		}//end if
		else {
		
			double total = dataset[(dataset.getSize() / 2)] + dataset[(dataset.getSize() / 2) - 1];
			return total / 2.0;
		
		}//end else	
	}//end getMedian

	//##########################################################################################################
	// getFrequencies() const : pair						
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################

	
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns a ( pair ) containing a ( map ) with the frequencies and a ( vector ) filled with the unique values of the dataset
	pair<map<double, int>, vector<double>> getFrequecies() const {
		map <double, int> frequencies;
		vector<double> unique_values;
		//end initialization

		for (int strt = 0; strt < dataset.getSize();  strt++) {
			
			double cur = dataset[strt];
			if (frequencies.find(cur) != frequencies.end()) {//out of bounds error
				
				frequencies[cur] = frequencies.at(cur) + 1;
		
			}//end if
			else {
			
				frequencies.insert(std::pair<double, int>(cur, 1));
				unique_values.push_back(cur);
			
			}//end else
		
		}//end for

		return pair<map<double, int>, vector<double>>(frequencies, unique_values);
	}//end getFrequencies

	//##########################################################################################################
	// displayFrequencies() : void							
	// Completed: [Y] []	Reviewed: [] [N]	Tested [Y][1]
	//##########################################################################################################
	
	// [Requires]: getSize()
	/// Precondition: N/A
	/// Postcondition: Prints out the frequencies of every value of the dataset in a formatted manner
	void displayFrequencies() {
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		//end initialization

		//prints frequency table
		printf("%10s %10s %15s \n", "Value", "Frequency", "Frequency %");
		for (double value : keys) {
			int percent = static_cast<int>(100 * ((static_cast<double>(freq.at(value))) / (static_cast<double>(this->getSize()))));
			printf("%10.2f %10i %13i %%\n", value, freq.at(value), percent);
		}//end for
	}//end 


	//##########################################################################################################
	// getMode() const: vector								
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// [Requires]: getFrequencies()
	/// Precondition: datset cannot be empty and has a value which repeats more than once ( otherwise displays 'no mode' )
	/// Postcondition: Returns a vector containing any mode found in the data set
	// Possibly consider alternative to getMode/getFrequencies
	vector<double> getMode() const {
		map<double, int> freq = getFrequecies().first;
		vector<double> keys = getFrequecies().second;
		vector<double> mode;
		//end initialization
		

		int highest_freq = int();
		for (double value : keys) {

			if (debug) { std::cout << "\n\t\t[DEBUG]: key value: " << value << "\t[DEBUG]: frequency: " << freq.at(value); }
			
			if (freq.at(value) > 1) {//if frequency greater than 1
				
				if (freq.at(value) >= highest_freq) {
					highest_freq = freq.at(value);
					
					if (freq.at(value) == highest_freq) {
						mode.push_back(value);
					}//end if

					if (freq.at(value) > highest_freq) {

						if (mode.empty()) {
							mode.push_back(value);
						}//end if
						else {
							mode.clear();//empty the mode
							mode.push_back(value);
						}//end else
					}//end if
				}//end if
				
			}//end if
		}//end for
		return mode;

	}//end getMode


	void displayMode() {

		if (this->getMode().empty()) {
			std::cout << "no mode\n";
		}//end if
		else {
			for (double mode : this->getMode())
				std::cout << mode << " ";
		}//end else

	
	}//end displayMode

	//##########################################################################################################
	// getStandardDeviation() const : double				
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// Standard Deviation
	//		Standard deviation is a measure of dispersion of data values from the mean.
	//		The formula for standard deviation is the square root of the sum of squared differences from the mean divided by the size of the data set.
	//

	// [Requires]: getSize(), getMean()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the standard deviation as defined [below] 
	///																	Standard deviation is a measure of dispersion of data values from the mean.
	///																	The formula for standard deviation is the square root of the sum of squared differences from the mean divided by the size of the data set.
	double getStandardDeviation() const {
		
		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);


		return sqrt( (sum) / static_cast<double>( (this->getSize()) ) )  ;

	}//end getStandardDeviation

	//##########################################################################################################
	// getVariance() const : double							
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################
	
	// [Requires]: getSize()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the variance of the datset as defined by the definition [below]
	///																    Variance measures dispersion of data from the mean. 
	///																	The formula for variance is the sum of squared differences from the mean divided by the size of the data set.
	/// Note: the Variance is the standard Deviation ^2
	double getVariance() const {

		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);


		return sum / static_cast<double>(this->getSize());

	}//end getVariance

	//##########################################################################################################
	// getMidRange() const : double							
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// [Requires]: getMax(), getMin()
	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the average of the sum of the max and min
	double getMidRange() {


		return (this->getMax() + this->getMin()) / 2.0;

	}//end getQuartiles

	//##########################################################################################################
	// getMedianN() const : double				
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	
	/// Precondition: set is a LinkTList<double> containing a set to find the median of.
	/// Postcondition: Returns the median of set
	double getMedianN(LinkTList<double> set) const {

		bool isOdd = (set.getSize() % 2) != 0;								//boolean for better readibility
		int pos = int();														//int holding position of median
		//end initialization

		if (isOdd) {

			pos = (set.getSize() / 2);
			//pos--;//to account for 1 to 0 shift
			return set[pos];

		}//end if
		else {

			double total = set[(set.getSize() / 2)] + set[(set.getSize() / 2) - 1];
			return total / 2.0;

		}//end else	
	}//end getMedian


	//##########################################################################################################
	// getQuartiles() const : double				
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]									 <[LOGIC ERROR]>	
	//##########################################################################################################

	//possible logical error may need revising

	// [Requires]: getMedian(), getMedianN(), dataset
	/// Precondition: dataset cannot be empty and should be of 4 or greater
	/// Postcondition: Returns a pointer with the value [make sure to deallocate] of an array carrying the 3 quartiles which break up the dataset into 4 sections
	double* getQuartiles() const {
		double* quartile = new double[3];
		quartile[1] = this->getMedian();
		auto qHalf = dataset.split(quartile[1]);
		quartile[0] = getMedianN(qHalf.first);
		quartile[2] = getMedianN(qHalf.second);
		return quartile;
		
	}//end getQuartiles


	void displayQuartiles() const {
		double* quartiles = this->getQuartiles();
		for (int i = 0; i < 3; i++) {
			std::cout << "Q" << (i + 1) << ": " << quartiles[i] << "\n";
		}//end for
		delete[] quartiles;
	}//end displayQuartile

	//##########################################################################################################
	// getInterQuartileRange() const : double											
	// Completed: [Y] []	Reviewed: [] [N]
	//##########################################################################################################

	// [Requires]: getQuartiles()
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the interQuartileRange, which is Q3 - Q1
	double getInterQuartileRange() const {

		double* quartiles = this->getQuartiles();
		return quartiles[2] - quartiles[0];

	}//end getInterQuartileRange

	//##########################################################################################################
	// getOutlier() const : double							
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// [Requires]: getQuartiles(), getInterQuartileRange(), dataset
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns a vector containing possible outlier candidates
	vector<double> getOutliers() const{
		double* quartiles = this->getQuartiles();
		const double FENCERANGE = 1.5 * (this->getInterQuartileRange());
		double upperFence = ( quartiles[2] + FENCERANGE );
		double lowerFence = ( quartiles[0] - FENCERANGE );
		vector<double> outliers;
		for (int i = 0; i < dataset.getSize(); i++) {
			if (dataset.getPos(i) < lowerFence || dataset.getPos(i) > upperFence) {
				outliers.push_back(dataset.getPos(i));
			}//end if

		}//end for

		delete[] quartiles;
		return outliers;

	}//end getOutliers

	void displayOutliers() {
		vector<double> outliers = this->getOutliers();
		for (double value : outliers) {
			std::cout << value << " ";
		}//end for

	}//end displayOutliers

	//##########################################################################################################
	// getSumOfSquares() const : double						
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// [Requires]: getMean(), getSize()
	/// Precondition: dataset cannot be empty
	/// Postcondition: returns the sum of the difference between each datavalue and the mean squared.
	double getSumOfSquares() const {
		double sum = double();
		//end initialization

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i] - (this->getMean())), 2.0);

		
		return sum;

	}//end getSumOfSquare

	//##########################################################################################################
	// getMeanAbsoluteDeviation() const : double			
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	// [Requires]: getMean(), getSize()
	/// Precondition:
	/// Postcondition:
	double getMeanAbsoluteDeviation() const {

		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += abs((dataset[i] - (this->getMean())));


		return sum / static_cast<double>(this->getSize());

	}//end getMeanAbsoluteDeviation


	//##########################################################################################################
	// getRootMeanSquare() const : double					
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getRootMeanSquare() const{


		double sum = double();

		for (int i = 0; i < this->getSize(); i++)
			sum += pow((dataset[i]), 2.0);


		return sqrt(sum / static_cast<double>(this->getSize()));

	}//end getRootMeanSquare

	//##########################################################################################################
	// getStandardErrorOfTheMean() const : double			
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getStandardErrorOfTheMean() const {

		return (this->getStandardDeviation()) / (sqrt(this->getSize()));

	}//end getStandardErrorOfTheMean

	//##########################################################################################################
	// getCoeffecientOfVariation() const : double			
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################

	/// Precondition:
	/// Postcondition:
	double getCoeffitiantOfVariation() const{

		return (this->getStandardDeviation())/(this->getMean());

	}//end getCoeffecientOfVariation

	
	//##########################################################################################################
	// getRelativeStandardDeviation() const : double		
	// Completed: [Y] []	Reviewed: [] [N]	Tested [N][0]
	//##########################################################################################################


	/// Precondition: dataset cannot be empty
	/// Postcondition: Returns the standard deviation * 100 divided by the mean
	double getRelativeStandardDeviation() const {

		return this->getCoeffitiantOfVariation() * 100.0;

	}//end getRelativeStandardDeviation

};//end class Descriptive Statistics

// Note: possibly change name of function.
/// Precondition:
/// Postcondition:
void runDescriptiveStatistics() {

	DescriptiveStatistics desc = DescriptiveStatistics();

	do {
		switch (menuDS()) {
			case '0': return; break;


			//#######################################################################################################################
			// Option A : Read													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################
			

			case 'A': {//Read
				
				desc.read("DATASET3.DAT");
				break; 
			
			}//end case A

			//#######################################################################################################################
			// Option B : Min													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'B': {//min
				
				std::cout << desc.getMin();
				break; 
			
			}//end case B

			//#######################################################################################################################
			// Option C : Max													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'C': {//max
			
				std::cout << desc.getMax();
				break; 
			
			}//end case C

			//#######################################################################################################################
			// Option D : Range													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'D': {//range
			
				std::cout << desc.getRange();
				break;
			
			}//end case D

			//#######################################################################################################################
			// Option E : Size													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'E': {//size
				
				std::cout << desc.getSize(); 
				break; 
			
			}//end case E

			//#######################################################################################################################
			// Option F : Sum													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'F': {//sum
				
				std::cout << desc.getSum();
				break; 
			
			}//end case F

			//#######################################################################################################################
			// Option G : Mean													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'G': {//mean

				std::cout << desc.getMean();
				break; 
			
			}//end case G

			//#######################################################################################################################
			// Option H : Median												
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'H': {//median 

				std::cout << desc.getMedian();
				break; 
			
			}//end case H

			//#######################################################################################################################
			// Option I : Display Frequencies									
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'I': {//display frequencies

				desc.displayFrequencies();
				break;
			
			}//end case I

			//#######################################################################################################################
			// Option J : Mode													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'J': {//mode
				desc.displayMode();
				break;
			
			}//end case J


			//#######################################################################################################################
			// Option K : Standard Deviation									
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'K': {//standard deviation

				std::cout << desc.getStandardDeviation();
				break;
			
			}//end case K


			//#######################################################################################################################
			// Option L : Varaince												
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'L': {//varaince

				std::cout << desc.getVariance();
				break;
			
			}//end case L

			//#######################################################################################################################
			// Option M : Mid range												
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'M': {//mid range

				std::cout << desc.getMidRange();
				break;
			
			}//end case M

			//#######################################################################################################################
			// Option N : Quartiles												
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'N': {//Quartiles
				desc.displayQuartiles();
				break;
			
			}//end case N

			//#######################################################################################################################
			// Option O : InterQuartile Range									
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'O': {//interquartile range

				std::cout << desc.getInterQuartileRange();
				break;
			
			}//end case O

			//#######################################################################################################################
			// Option P : Outliers												
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'P': {//Outliers

				desc.displayOutliers();
				break;
			
			}//end case P

			//#######################################################################################################################
			// Option Q : Sum of Squares										
			// Completed: [Y] [d]	Reviewed: [] [N]
			//#######################################################################################################################

			case 'Q': {//sum of squares

				std::cout << desc.getSumOfSquares();
				break;
			
			}//end case Q

			//#######################################################################################################################
			// Option R : Mean Absolute Deviation								
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'R': {//Mean Absolute Deviation
				std::cout << desc.getMeanAbsoluteDeviation();
				break;
			
			}//end case R

			//#######################################################################################################################
			// Option S : Root Mean Square										
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'S': {//Root Mean Square

				std::cout << desc.getRootMeanSquare();
				break;
			
			}//end case S

			//#######################################################################################################################
			// Option T : Standard Error of the Mean							
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'T': {//Standard Error of the Mean

				std::cout << desc.getStandardErrorOfTheMean();
				break;
			
			}//end case T


			//#######################################################################################################################
			// Option U : Coefficient of Variation								
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'U': {// Coefficient of Variation

				std::cout << desc.getCoeffitiantOfVariation();
				break;
			
			}//end case U

			//#######################################################################################################################
			// Option V : Relative Standard Deviation							
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			case 'V': {//Relative Standard Deviation

				std::cout << desc.getRelativeStandardDeviation();
				break;
			
			}//end case V


			//#######################################################################################################################
			// Option W : Display all resultsand write to an output text file	
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################


			case 'W': {//Display all resultsand write to an output text file

				
				break;
			
			}//end case W


			//#######################################################################################################################
			// Invalid Option													
			// Completed: [Y] []	Reviewed: [] [N]
			//#######################################################################################################################

			default: { 

				std::cout << "\nInvalid option: Please select a option within the menu";
				break;
			
			}//end default

		}//end switch
		pause();
	} while (true);
	
}


