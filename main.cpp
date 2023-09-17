#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

struct
{ // Structure declaration
    int num_of_rows;
    double mean;
    double median;
    string coldest_date;
    double coldest_temp;
    string hottest_date;
    double hottest_temp;

    vector<string> code;
    vector<string> s_number;
    vector<string> Year;
    vector<string> Month;
    vector<string> Date;
    vector<double> M_temp;
    vector<int> Days_M_temp;
    vector<string> quality;
    // Member (string variable)
} Airdata,byYear,byMonth,AirdataUnsorted;

void savelog(const string &text)
{
    // Open the file "log.txt" in append mode
    ofstream logfile("log.txt", ios_base::app);

    if (!logfile.is_open())
    {
        cerr << "Error opening log file." << endl;
        return;
    }

    // Write the text to the log file
    logfile << text << endl;

    // Close the log file
    logfile.close();
}

// sort data...

void calcDtails(string choice)
{

       vector<string> code;
    vector<string> s_number;
    vector<string> Year;
    vector<string> Month;
    vector<string> Date;
    vector<double> M_temp;
    vector<int> Days_M_temp;
    vector<string> quality;
    int n=0;

    if(choice=="Airdata"){
             n = Airdata.num_of_rows;
    code=Airdata.code;
  s_number=Airdata.s_number;
     Year=Airdata.Year;
    Month=Airdata.Month;
    Date=Airdata.Date;
     M_temp=Airdata.M_temp;
     Days_M_temp=Airdata.Days_M_temp;
     quality=Airdata.quality;

    }
    else if(choice=="Year"){
 n = byYear.num_of_rows;
      code=byYear.code;
    s_number=byYear.s_number;
     Year=byYear.Year;
     Month=byYear.Month;
     Date=byYear.Date;
     M_temp=byYear.M_temp;
    Days_M_temp=byYear.Days_M_temp;
     quality=byYear.quality;

    }

    else{
             n = byMonth.num_of_rows;
 code=byMonth.code;
    s_number=byMonth.s_number;
     Year=byMonth.Year;
     Month=byMonth.Month;
     Date=byMonth.Date;
     M_temp=byMonth.M_temp;
    Days_M_temp=byMonth.Days_M_temp;
     quality=byMonth.quality;

    }


    double temp;
    string temp2;
    int temp3;
    bool swapped;

    do
    {
        swapped = false;

        for (int i = 1; i < n; ++i)
        {
            if (M_temp[i - 1] > M_temp[i])
            {
                // Swap elements M_temp[i] and M_temp[i-1]
                temp = M_temp[i - 1];
               M_temp[i - 1] = M_temp[i];
                M_temp[i] = temp;
                // sort code
                temp2 = code[i - 1];
               code[i - 1] = code[i];
                code[i] = temp2;
                // sort date vector
                temp2 = Date[i - 1];
                Date[i - 1] = Date[i];
                Date[i] = temp2;
                // sort days_M_temp vector
                temp3 = Days_M_temp[i - 1];
                Days_M_temp[i - 1] = Days_M_temp[i];
                Days_M_temp[i] = temp3;
                // sort quality vector
                temp2 = quality[i - 1];
                quality[i - 1] = quality[i];
                quality[i] = temp2;
                // sort s_number vector

                temp2 = s_number[i - 1];
                s_number[i - 1] = s_number[i];
                s_number[i] = temp2;
                // sort Month vector
                temp2 = Month[i - 1];
                Month[i - 1] = Month[i];
                Month[i] = temp2;

                // sort Year vector
                temp2 = Year[i - 1];
                Year[i - 1] = Year[i];
                Year[i] = temp2;
                swapped = true;
            }
        }
    } while (swapped);



 vector<double> data = M_temp;
    double sum = 0.0;
    long int count = data.size();

    if (count == 0)
    {

        cerr << "Empty data vector. Mean not available." << endl;
         double mean= 0.0;
    }

    // Calculate the sum of temperature values
    for (double temperatureStr : data)
    {
        double temperature = temperatureStr;
        sum += temperature;
    }

    // Calculate the mean temperature
    double mean = sum / count;
double median;
data = M_temp;
    size_t size = data.size();

    if (size == 0)
    {
        // Handle the case of an empty vector
        cout << "Empty data vector. Median not available." << endl;
        median= 0.0;
    }

    // Calculate the middle index
    size_t middleIndex = size / 2;

    if (size % 2 == 0)
    {
        // If the vector has an even number of elements, average the two middle values
        double middleValue1 = data[middleIndex];
        double middleValue2 = data[middleIndex - 1];
        median= (middleValue1 + middleValue2) / 2.0;
    }
    else
    {
        // If the vector has an odd number of elements, return the middle value
        median= data[middleIndex];
    }


  if(choice=="Airdata"){

    Airdata.hottest_date=Year[n - 1]+"/"+ Month[n - 1]+"/"+ Date[n - 1];
    Airdata.hottest_temp=M_temp[n- 1];
     Airdata.coldest_date=Year[0]+"/"+ Month[0]+"/"+ Date[0];
    Airdata.coldest_temp=M_temp[0];
    Airdata.mean=mean;
    Airdata.median=median;

  }
  else if(choice=="Year"){

     byYear.hottest_date=Year[n- 1]+"/"+ Month[n - 1]+"/"+Date[n - 1];
    byYear.hottest_temp=M_temp[n- 1];
         byYear.coldest_date=Year[ 0]+"/"+ Month[0]+"/"+ Date[0];
    byYear.coldest_temp=M_temp[0];
      byYear.mean=mean;
    byYear.median=median;
  }
  else{
     byMonth.hottest_date=Year[n - 1]+"/"+ Month[n - 1]+"/"+ Date[n - 1];
  byMonth.hottest_temp=M_temp[n - 1];
       byMonth.coldest_date=Year[ 0]+"/"+ Month[0]+"/"+ Date[0];
    byMonth.coldest_temp=M_temp[0];
    byMonth.mean=mean;
    byMonth.median=median;
  }


}

// select year or all data
int selectfiletype()
{
    int choise;
    cout << "Select a dataset to analyze:" << endl;

    cout << "1. 2022 data set" << endl;
    cout << "2. ALL dataset" << endl;
    cout << "Your choise :";
    cin >> choise;

    return choise;
}

// Function to read and parse CSV data from a file
bool readCSV(const string filename, int choise)
{

    ifstream file;
    double temp;
    int n_days;

    if (filename == "both")
    {

        string files[] = {"Bendigo Airport Temperature Data-all.csv", "Avalon Airport Temperature Data-all.csv"};
        if (choise == 1)
        {
            files[0] = "Avalon Airport Temperature Data-2022.csv";
            files[1] = "Bendigo Airport Temperature Data-2022.csv";
        }
        int numRows = 0; // Initialize the row count
        for (int i = 0; i < 2; i++)
        {
            file.open(files[i]);
            string line;
            string column;
            vector<std::string> row;
            getline(file, line);
            bool inQuotes = false;

            while (getline(file, line))
            {
                for (char c : line)
                {
                    if (c == ',')
                    {
                        if (column.empty())
                        {
                            row.clear();
                            break;
                        }
                        else
                        {
                            row.push_back(column);
                        }

                        column.clear();
                    }
                    else
                    {
                        column += c;
                    }
                }
                if (column.empty())
                {
                    row.clear();
                }
                else
                {
                    row.push_back(column);
                }

                if (!row.empty())
                {

                    Airdata.code.push_back(row[0]);
                    Airdata.s_number.push_back(row[1]);
                    Airdata.Year.push_back(row[2]);
                    Airdata.Month.push_back(row[3]);
                    Airdata.Date.push_back(row[4]);
                    temp = stod(row[5]);
                    Airdata.M_temp.push_back(temp);
                    n_days = stod(row[6]);
                    Airdata.Days_M_temp.push_back(n_days);
                    Airdata.quality.push_back(row[7]);

                    row.clear();

                    numRows++;
                }
            }
            file.close();
            Airdata.num_of_rows = numRows;
        }


    }
    else
    {
        ifstream file;
        file.open(filename);
        string line;
        string column;
        vector<std::string> row;
        getline(file, line);
        bool inQuotes = false;
        int numRows = 0; // Initialize the row count

        while (getline(file, line))
        {
            for (char c : line)
            {
                if (c == ',')
                {
                    if (column.empty())
                    {
                        row.clear();
                        break;
                    }
                    else
                    {
                        row.push_back(column);
                    }

                    column.clear();
                }
                else
                {
                    column += c;
                }
            }
            if (column.empty())
            {
                row.clear();
            }
            else
            {
                row.push_back(column);
            }

            if (!row.empty())
            {

                Airdata.code.push_back(row[0]);
                Airdata.s_number.push_back(row[1]);
                Airdata.Year.push_back(row[2]);
                Airdata.Month.push_back(row[3]);
                Airdata.Date.push_back(row[4]);
                temp = stod(row[5]);
                Airdata.M_temp.push_back(temp);
                n_days = stod(row[6]);
                Airdata.Days_M_temp.push_back(n_days);
                Airdata.quality.push_back(row[7]);

                row.clear();

                numRows++;
            }
        }
        file.close();
        Airdata.num_of_rows = numRows;

    }



    return 1;
    // Replace with actual logic
}

// Function to find the hottest day in the dataset
void findHottestDay()
{

    int vsize = Airdata.num_of_rows;
    cout << "Hottest Date :" << Airdata.Year[vsize - 1] << "/" << Airdata.Month[vsize - 1] << "/" << Airdata.Date[vsize - 1] << "  Temperature:" << Airdata.M_temp[vsize - 1] << "%C" << endl;
}

// Function to find the coldest day in the dataset
void findColdestDay()
{

    int vsize = Airdata.num_of_rows;
    cout << "Coldest Date :" << Airdata.Year[0] << "/" << Airdata.Month[0] << "/" << Airdata.Date[0] << "  Temperature:" << Airdata.M_temp[0] << "%C" << endl;
}

// Function to calculate the mean temperature
double calculateMeanTemperature()
{
    vector<double> data = Airdata.M_temp;
    double sum = 0.0;
    long int count = data.size();

    if (count == 0)
    {

        cerr << "Empty data vector. Mean not available." << endl;
        return 0.0;
    }

    // Calculate the sum of temperature values
    for (double temperatureStr : data)
    {
        double temperature = temperatureStr;
        sum += temperature;
    }

    // Calculate the mean temperature
    double mean = sum / count;

    return mean;
}

// Function to calculate the median temperature
double calculateMedianTemperature()
{
    vector<double> data = Airdata.M_temp;
    size_t size = data.size();

    if (size == 0)
    {
        // Handle the case of an empty vector
        cout << "Empty data vector. Median not available." << endl;
        return 0.0;
    }

    // Calculate the middle index
    size_t middleIndex = size / 2;

    if (size % 2 == 0)
    {
        // If the vector has an even number of elements, average the two middle values
        double middleValue1 = data[middleIndex];
        double middleValue2 = data[middleIndex - 1];
        return (middleValue1 + middleValue2) / 2.0;
    }
    else
    {
        // If the vector has an odd number of elements, return the middle value
        return data[middleIndex];
    }
}
void selectmonth() {

string preMonth;
int flag= 0;
int num_of_rows=0;
string selectedMonth;
cout<<"-----------Available Months---------"<<endl;
    for (string month : byYear.Month) {
            if(preMonth!=month){
               cout<<month<<endl;
               preMonth=month;
            }

    }
    cout<<"Select Month:";
    cin>>selectedMonth;
    for(int i=0;i<byYear.num_of_rows;i++){
        if(byYear.Month[i]==selectedMonth){
                byMonth.code.push_back(byYear.code[i]);
         byMonth.s_number.push_back(byYear.s_number[i]);
            byMonth.Year.push_back(byYear.Year[i]);
            byMonth.Month.push_back(byYear.Month[i]);
            byMonth.Date.push_back(byYear.Date[i]);
            byMonth.M_temp.push_back(byYear.M_temp[i]);
            byMonth.Days_M_temp.push_back(byYear.Days_M_temp[i]);
            byMonth.quality.push_back(byYear.quality[i]);
            flag=1;
            num_of_rows++;
        }
        else{
            if(flag==1){

                break;
            }
        }
    }
byMonth.num_of_rows=num_of_rows;

cout<<byMonth.num_of_rows<<endl;
}


void selectyear() {

string preyear;
int flag= 0;
int num_of_rows=0;
string selectedYear;
cout<<"-----------Available Years---------"<<endl;
    for (string year : Airdata.Year) {
            if(preyear!=year){
               cout<<year<<endl;
               preyear=year;
            }

    }
    cout<<"Select Year:";
    cin>>selectedYear;
    for(int i=0;i<Airdata.num_of_rows;i++){
        if(Airdata.Year[i]==selectedYear){
                byYear.code.push_back(Airdata.code[i]);
         byYear.s_number.push_back(Airdata.s_number[i]);
            byYear.Year.push_back(Airdata.Year[i]);
            byYear.Month.push_back(Airdata.Month[i]);
            byYear.Date.push_back(Airdata.Date[i]);
            byYear.M_temp.push_back(Airdata.M_temp[i]);
            byYear.Days_M_temp.push_back(Airdata.Days_M_temp[i]);
            byYear.quality.push_back(Airdata.quality[i]);
            flag=1;
            num_of_rows++;
        }
        else{
            if(flag==1){

                break;
            }
        }
    }
byYear.num_of_rows=num_of_rows;


}

void showByMonth(){
    cout<<endl<<"-------------For Selected Month----------"<<endl;
                               cout << "Total number of rows: " << byMonth.num_of_rows << endl;
        cout << "Total number of columns: " << 8 << endl;
                cout << "Hottest Date :" << byMonth.hottest_date << "  Temperature:" << byMonth.hottest_temp << "%C" << endl;
                 cout << "Coldest Date :" << byMonth.coldest_date << "  Temperature:" << byMonth.coldest_temp << "%C" << endl;


        cout << "Mean temperature : " << byMonth.mean << "%C" << endl;

        cout << "Median temperature : " << byMonth.median << "%C" << endl;

}

void showByYear(){
    cout<<endl<<"-------------For All Years----------"<<endl;
                               cout << "Total number of rows: " << byYear.num_of_rows << endl;
        cout << "Total number of columns: " << 8 << endl;
                cout << "Hottest Date :" << byYear.hottest_date << "  Temperature:" << byYear.hottest_temp << "%C" << endl;
                 cout << "Coldest Date :" << byYear.coldest_date << "  Temperature:" << byYear.coldest_temp << "%C" << endl;


        cout << "Mean temperature : " << byYear.mean << "%C" << endl;

        cout << "Median temperature : " << byYear.median << "%C" << endl;

}
void showAirdata(){
 cout<<endl<<"-------------For  Years----------"<<endl;
        cout << "Total number of rows: " << Airdata.num_of_rows << endl;
        cout << "Total number of columns: " << 8 << endl;
                 cout << "Hottest Date :" << Airdata.hottest_date << "  Temperature: " << Airdata.hottest_temp << "%C" << endl;
                 cout << "Coldest Date :" << Airdata.coldest_date << "  Temperature: " << Airdata.coldest_temp << "%C" << endl;

        cout << "Mean temperature for All: " << Airdata.mean << "%C" << endl;

        cout << "Median temperature for All: " << Airdata.median << "%C" << endl;
}


int main()
{
    cout << "Turing Moore Engineering Temperature Data Analyser 1.0" << endl;

    vector<vector<string>> selectedData;

    // Ask the user which dataset they want to analyze
    char choice;
    int choice2;
    do
    {
        cout << "Select a dataset to analyze:" << endl;

        cout << "1. Bendigo Airport Data" << endl;
        cout << "2. Avalon Airport Data" << endl;
        cout << "3. Both" << endl;
        cout << "4. Own Data sheet" << endl;
        cout << "e.exit" << endl;
        cin >> choice;

        if (choice == '1')
        {
            savelog("selected data set :Bendigo Airport Temperature Data-2022.csv");
            choice2 = selectfiletype();
            if (choice2 == 1)
            {
                readCSV("Bendigo Airport Temperature Data-2022.csv", choice2);
                calcDtails("Airdata");
                savelog("selected data type : 2022");
             showAirdata();
            }
            else if (choice2 == 2)
            {
                savelog("selected data type : ALL");

                readCSV("Bendigo Airport Temperature Data-all.csv", choice2);
                calcDtails("Airdata");
                 showAirdata();
                 selectyear();
                 calcDtails("Year");

                 showByYear();
                    selectmonth();
                 calcDtails("Month");
                 showByMonth();


            }
        }

        if (choice == '2')
        {
            savelog("selected data set :Avalon Airport Temperature Data-2022.csv");

            choice2 = selectfiletype();
            if (choice2 == 1)
            {
                readCSV("Avalon Airport Temperature Data-2022.csv", choice2);
                savelog("selected data type : 2022");
                calcDtails("Airdata");
            showAirdata();
            }
            else if (choice2 == 2)
            {
                readCSV("Avalon Airport Temperature Data-all.csv", choice2);
                calcDtails("Airdata");
                 showAirdata();
                 selectyear();
                savelog("selected data type : ALL");
                calcDtails("Year");

                 showByYear();
                 selectmonth();
                 calcDtails("Month");
                 showByMonth();

            }


        }

        if (choice == '3')
        {
            choice2 = selectfiletype();
            savelog("selected data set :Avalon Airport Temperature Data-2022.csv and Bendigo Airport Temperature Data-all.csv ");

            if (choice2 == 1)
            {
                readCSV("both", choice2);
                savelog("selected data type : 2022");
               showAirdata();

            }
            else if (choice2 == 2)
            {
                readCSV("both", choice2);
               showAirdata();
                selectyear();
                savelog("selected data type : ALL");


                 showByYear();
            }
        }
        if (choice == '4')
        {
            string csvname;
            cout << "input csv name :";
            getline(cin, csvname);
            getline(cin, csvname);
            savelog("selected data set :" + csvname + "(custom input)");
           selectyear();
   cout << "Total number of rows: " << byYear.num_of_rows << endl;
        cout << "Total number of columns: " << 8 << endl;
        cout << "Hottest Date :" << byYear.hottest_date << "  Temperature:" << byYear.hottest_temp << "%C" << endl;
        cout << "Coldest Date :" << byYear.coldest_date << "  Temperature:" << byYear.coldest_temp << "%C" << endl;
            readCSV(csvname, choice2);
        }
        if (choice == 'e')
        {
            break;
        }





        cout << endl
             << endl
             << "select e to exit c to continue: ";
        cin >> choice;
        while (choice != 'e' && choice != 'c')
        {
            cout << endl
                 << endl
                 << "select e to exit c to continue: ";
            cin >> choice;
        }

        if (choice == 'c')
        {
            savelog("choice : Continue");
        }

    } while (choice != 'e');
    savelog("choice : Exit");
    return 0;
}
