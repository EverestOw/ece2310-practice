#include<iostream>
#include<fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
/**
 * TO DO: 
 * Add <vector>, <cstdlib>, and <ctime>​
 */

using namespace std;

/**
 * TO DO: 
 * Create function prototypes for all the functions.
 * Write their function declarations below mai()).
 * 
 * See promptFile(...) and printVec(...), which serve as examples.
 * 
 */


//------------------------PROTOTYPE-------------------------------------------
void promptFile(vector<string> &); 
void printVec(const vector<string> &);

int ranGen(int);

bool readFile(string, vector<string> &);
bool writeFile(string, const vector<string>&, const vector<string>&);


//------------------------MAIN BODY-------------------------------------------
int main()
{
    vector<string> roster;
    vector<string> qBank;
    readFile("2310_F26_Rosters.csv", roster);
    readFile("Questions.csv", qBank);

    vector<string> dummy;

    writeFile("output.csv",roster, dummy);
    // writeFile("Student_question_bank.csv",roster, qBank);

    return 0;
}

//------------------------DECLARATIONS-------------------------------------------
/**
 * @brief prompts the user to give a file to read
 * 
 */
void promptFile(vector<string> & v){
    cout << "file to read?\n";
    string myFile = "";
    cin >> myFile;
    readFile(myFile, v);
}


/**
 * @brief prints out the elements in v
 * 
 * @param v: vector<string>
 */
void printVec(const vector<string>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

/**
 * @brief randomly returns a number from 0 to upperBound.
 *
 * @param upperBound: int (only positive integers)
 * 
 * TO DO:
 * Use <random> for modern C++ random generation instead 
 * - Determine distribution type: uniform or binomial, etc
 * 
 * @return int
 */
int ranGen(int upperBound){

    //  Case: non-positive integers
    if (upperBound <= 0) {
        throw std::invalid_argument("upperBound must be a positive integer."); 
    }

    //  Random device implementation
    random_device random = random_device();

    return random() % upperBound;
}

/**
 * @brief reads contents of filename and populates into vec.
 * 
 * @param filename :string 
 * @param vec: vector<string> &
 * 
 * @return bool: operation succeded.
 */
bool readFile(string filename, vector<string> & vec) {

   ifstream inputFile(filename);

    //error handling
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file\n";
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();

    return true;
}

/**
 * @brief writes to filename with the first column from v0, second column from v1
 * 
 * @param filename: string
 * @param v0: vector<string> (for students names). Must be non-empty
 * @param v1: vector<string> (for questions). Must be non-empty
 * 
 * @return bool: indicates whether operation succeeded or not.
 */
bool writeFile(string filename, const vector<string>& v0, const vector<string>& v1){

    // Check for empty vector parameters
    if (v0.size() == 0 || v1.size() == 0)
    {
        cerr << "Error: Empty vector supplied as argument" << endl;
        return false;
    }

    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error: Could not create data.csv" << endl;
        return false;
    }

    // write under the structure:
    // Student_Name, Question_#
    const int V1_SIZE = v1.size();

    for(int i = 0; i < v0.size(); i++){
        outputFile << v0[i] << "," << v1[ranGen(V1_SIZE)] << endl;
    }
    outputFile.close();

    return true;
}
