#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

struct {             // Structure declaration
  int num_of_rows;
 vector<string> code;
  vector<string> s_number;
   vector<string> Year;
  vector<string> Month;
  vector<string> Date;
  vector<double> M_temp;
  vector<int> Days_M_temp;
  vector<string> quality;
    // Member (string variable)
} Airdata;


void bSort() {

    int n = Airdata.M_temp.size();
    double temp;
    string temp2;
    int temp3;
    bool swapped;

    do {
        swapped = false;

        for (int i = 1; i < n; ++i) {
            if (Airdata.M_temp[i - 1] > Airdata.M_temp[i]) {
                // Swap elements Airdata.M_temp[i] and Airdata.M_temp[i]
                 temp = Airdata.M_temp[i - 1];
                Airdata.M_temp[i - 1] = Airdata.M_temp[i];
                Airdata.M_temp[i] = temp;
                //sort code
                temp2 = Airdata.code[i - 1];
                Airdata.code[i - 1] = Airdata.code[i];
                Airdata.code[i] = temp2;
                //sort date vector
                temp2 = Airdata.Date[i - 1];
                Airdata.Date[i - 1] = Airdata.Date[i];
                Airdata.Date[i] = temp2;
                //sort days_M_temp vector
                temp3 = Airdata.Days_M_temp[i - 1];
                Airdata.Days_M_temp[i - 1] = Airdata.Days_M_temp[i];
                Airdata.Days_M_temp[i] = temp3;
                //sort quality vector
                      temp2 = Airdata.quality[i - 1];
                Airdata.quality[i - 1] = Airdata.quality[i];
                Airdata.quality[i] = temp2;
                //sort s_number vector

                      temp2 = Airdata.s_number[i - 1];
                Airdata.s_number[i - 1] = Airdata.s_number[i];
                Airdata.s_number[i] = temp2;
                 //sort Month vector
                   temp2 = Airdata.Month[i - 1];
                Airdata.Month[i - 1] = Airdata.Month[i];
                Airdata.Month[i] = temp2;

                 //sort Year vector
                         temp2 = Airdata.Year[i - 1];
                Airdata.Year[i - 1] = Airdata.Year[i];
                Airdata.Year[i] = temp2;
                swapped = true;
            }
        }
    } while (swapped);
}

//select year or all data
int selectfiletype(){
    int choise;
    cout << "Select a dataset to analyze:" << endl;

    cout << "1. 2022 data set" << endl;
    cout << "2. ALL dataset" << endl;
    cout<<"Your choise :";
    cin>>choise;

return choise;
}


// Function to read and parse CSV data from a file
bool readCSV(const string filename, int choise) {

 ifstream file;
    double temp;
    int n_days;

    if(filename=="both"){

            string files[]={"Bendigo Airport Temperature Data-all.csv","Avalon Airport Temperature Data-all.csv"};
    if(choise==1){
        files[0]="Avalon Airport Temperature Data-2022.csv";
        files[1]="Bendigo Airport Temperature Data-2022.csv";
    }
      int numRows = 0; // Initialize the row count
            for(int i=0;i<2;i++){
                    file.open(files[i]);
    string line;
string column;
vector<std::string> row;
    getline(file, line);
bool inQuotes = false;


    while (getline(file, line)) {
 for (char c : line) {
          if (c == ',' ) {
              if(column.empty()){
                             row.clear();
               break;
              }
              else{
                 row.push_back(column);
              }

                column.clear();
            } else {
                column += c;
            }
        }
if(column.empty()){
               row.clear();

              }
              else{
                 row.push_back(column);
              }

if(!row.empty()){

    Airdata.code.push_back(row[0]);
Airdata.s_number.push_back(row[1]);
Airdata.Year.push_back(row[2]);
Airdata.Month.push_back(row[3]);
Airdata.Date.push_back(row[4]);
        temp =stod(row[5]);
Airdata.M_temp.push_back(temp);
       n_days =stod(row[6]);
Airdata.Days_M_temp.push_back(n_days);
Airdata.quality.push_back(row[7]);

row.clear();

        numRows++;
}

    }
    file.close();
    Airdata.num_of_rows=numRows;
}



bSort();

    }
    else{
           ifstream file;
    file.open(filename);
    string line;
string column;
vector<std::string> row;
    getline(file, line);
bool inQuotes = false;
    int numRows = 0; // Initialize the row count

    while (getline(file, line)) {
 for (char c : line) {
          if (c == ',' ) {
              if(column.empty()){
                             row.clear();
               break;
              }
              else{
                 row.push_back(column);
              }

                column.clear();
            } else {
                column += c;
            }
        }
if(column.empty()){
               row.clear();

              }
              else{
                 row.push_back(column);
              }

if(!row.empty()){

    Airdata.code.push_back(row[0]);
Airdata.s_number.push_back(row[1]);
Airdata.Year.push_back(row[2]);
Airdata.Month.push_back(row[3]);
Airdata.Date.push_back(row[4]);
        temp =stod(row[5]);
Airdata.M_temp.push_back(temp);
       n_days =stod(row[6]);
Airdata.Days_M_temp.push_back(n_days);
Airdata.quality.push_back(row[7]);

row.clear();

        numRows++;
}

    }
    file.close();
Airdata.num_of_rows=numRows;
bSort();

    }

return 1;
  // Replace with actual logic
}

// Function to find the hottest day in the dataset
void findHottestDay() {

int vsize=Airdata.num_of_rows;
    cout << "Hottest Date :" <<Airdata.Year[vsize-1]<<"/"<<Airdata.Month[vsize-1]<<"/"<<Airdata.Date[vsize-1]<< "  Temperature:" <<Airdata.M_temp[vsize-1]<< "°C" << endl;


}

// Function to find the coldest day in the dataset
void findColdestDay() {

int vsize=Airdata.num_of_rows;
    cout << "Coldest Date :" <<Airdata.Year[0]<<"/"<<Airdata.Month[0]<<"/"<<Airdata.Date[0]<< "  Temperature:" <<Airdata.M_temp[0]<< "°C" << endl;
}

// Function to calculate the mean temperature
double calculateMeanTemperature(const vector<vector<string>>& data) {
    // Implement mean temperature calculation logic here
    // ...

    return 0.0; // Replace with actual logic
}

// Function to calculate the median temperature
double calculateMedianTemperature() {
    vector<double> data=Airdata.M_temp;
 size_t size = data.size();

    if (size == 0) {
        // Handle the case of an empty vector
        cout << "Empty data vector. Median not available." << endl;
        return 0.0;
    }

    // Calculate the middle index
    size_t middleIndex = size / 2;

    if (size % 2 == 0) {
        // If the vector has an even number of elements, average the two middle values
        double middleValue1 = data[middleIndex];
        double middleValue2 = data[middleIndex - 1];
        return (middleValue1 + middleValue2) / 2.0;
    } else {
        // If the vector has an odd number of elements, return the middle value
        return data[middleIndex];
    }
}

int main() {
    cout << "Turing Moore Engineering Temperature Data Analyser 1.0" << endl;

    vector<vector<string>> selectedData;

    // Ask the user which dataset they want to analyze
    int choice;
     int choise2;
    cout << "Select a dataset to analyze:" << endl;

    cout << "1. Bendigo Airport Data" << endl;
    cout << "2. Avalon Airport Data" << endl;
    cout << "3. Both" << endl;
    cout << "4. Own Data sheet" << endl;
    cin >> choice;

    if (choice == 1 ) {

        choise2=selectfiletype();
       if(choise2==1){
        readCSV("Bendigo Airport Temperature Data-2022.csv",choice);
       }
        else if(choise2==2){
                   readCSV("Bendigo Airport Temperature Data-all.csv",choice);

        }
    }

    if (choice == 2 ) {
              choise2=selectfiletype();
       if(choise2==1){
        readCSV("Avalon Airport Temperature Data-2022.csv",choice);
       }
        else if(choise2==2){
                   readCSV("Avalon Airport Temperature Data-all.csv",choice);

        }

    readCSV("Avalon Airport Temperature Data-2022.csv",choice);

    }

    if (choice == 3 ) {
           choise2=selectfiletype();
       if(choise2==1){
        readCSV("both",choise2);
       }
        else if(choise2==2){
                   readCSV("both",choise2);

        }


    }
    if (choice == 4 ) {
            string csvname;
            cout<<"input csv name :";
            getline(cin, csvname);
        getline(cin, csvname);

    readCSV(csvname,choice);

    }
    // Display total number of rows and columns
    cout << "Total number of rows: " << Airdata.num_of_rows << endl;
    cout << "Total number of columns: " << 8 << endl;

    // Find and display the hottest day
    findHottestDay();

    // Find and display the coldest day
    findColdestDay();

    // Calculate and display the mean temperature
    double meanTemperature = calculateMeanTemperature(selectedData);
    cout << "Mean temperature for the year: " << meanTemperature << "°C" << endl;

    // Calculate and display the median temperature
    double medianTemperature = calculateMedianTemperature();
    cout << "Median temperature for the year: " << medianTemperature << "°C" << endl;

    return 0;
}
