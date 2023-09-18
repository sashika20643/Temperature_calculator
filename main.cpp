#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

struct Data
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
} Airdata,byYear,byMonth;



void bubbleSort(std::vector<double>& values) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < values.size(); ++i) {
            if (values[i - 1] > values[i]) {
                // Swap values[i-1] and values[i]
                double temp = values[i - 1];
                values[i - 1] = values[i];
                values[i] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}


double calculateMedian(const std::vector<double>& values) {
    std::vector<double> sortedValues = values;
    bubbleSort(sortedValues);

    size_t size = sortedValues.size();
    if (size % 2 == 0) {
        // If even number of elements, average the middle two values
        return (sortedValues[size / 2 - 1] + sortedValues[size / 2]) / 2.0;
    } else {
        // If odd number of elements, return the middle value
        return sortedValues[size / 2];
    }
}

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

void createResultsCSV() {
     Data data= Airdata;
    // Create a directory named "Results" if it doesn't exist
   string directory = "Results/";
 string monthsName[]={"01","02","03","04","05","06","07","08","09","10","11","12"};
int monindex=0;
string preyear=data.Year[0];
 string filename = directory + data.Year[0]+".csv";

    // Open the CSV file for writing
   ofstream outfile(filename);

    if (!outfile) {
        std::cerr << "Error opening " << filename << " for writing." << std::endl;
        return;
    }

    // Write column headings to the CSV file
    outfile << "Year,Month,Hottest Temperature,Coldest Temperature,Average Temperature,Median Temperature" << std::endl;


    // Iterate through months and write data to the CSV file
    for (size_t i = 0; i < data.Month.size(); ++i) {
        std::string year = data.Year[i];
        std::string month = data.Month[i];
        double hottestTemp = data.M_temp[i];
        double coldestTemp = data.M_temp[i];
        double sumTemp = data.M_temp[i];
        std::vector<double> tempsForMonth = {data.M_temp[i]};
        if(year!=preyear){
outfile.close();
           filename = directory + year+".csv";

    // Open the CSV file for writing
   outfile.open(filename);

    if (!outfile) {
        std::cerr << "Error opening " << filename << " for writing." << std::endl;
        return;
    }

    // Write column headings to the CSV file
    outfile << "Year,Month,Hottest Temperature,Coldest Temperature,Average Temperature,Median Temperature" << std::endl;
    preyear=year;


        }

        // Find the hottest, coldest, and calculate the sum for the current month
        for (size_t j = i + 1; j < data.Month.size(); ++j) {
            if (data.Month[j] == month && data.Year[j]==year) {
                double temp = data.M_temp[j];
                hottestTemp = std::max(hottestTemp, temp);
                coldestTemp = std::min(coldestTemp, temp);
                sumTemp += temp;
                tempsForMonth.push_back(temp);
            }
        }

        // Calculate average and median temperatures for the current month
        double averageTemp = sumTemp / tempsForMonth.size();
        double medianTemp = calculateMedian(tempsForMonth);

        // Write data to the CSV file
        if(monthsName[monindex]!=month){
            for(monindex;monindex<12;monindex++){
                if(monthsName[monindex]!=month){
                       outfile << year << "," << monthsName[monindex] << "," << "" << "," << "" << ","
                <<""<< "," << "" << endl;
                }
                else{

                monindex++;
                    break;
                }
            }
        }
        outfile << year << "," << month << "," << hottestTemp << "," << coldestTemp << ","
                << averageTemp << "," << medianTemp << endl;

        // Skip processing duplicate months
        while (i + 1 < data.Month.size() && data.Month[i + 1] == month) {
            i++;
        }
    }

    // Close the CSV file
    outfile.close();
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
        cout<<"done"<<endl;
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
            vector<string> row;
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


createResultsCSV();
    return 1;
    // Replace with actual logic
}








// Function to calculate the average of a vector of doubles
double calculateAverage(const vector<double>& values) {
    double sum = 0.0;

    for (double value : values) {
        sum += value;
    }

    return sum / values.size();
}

// Function to calculate the variance of a vector of doubles
double calculateVariance(const vector<double>& values) {
    if (values.size() <= 1) {
        return 0.0; // Variance is zero for one or fewer values
    }

    double mean = calculateAverage(values);
    double variance = 0.0;

    for (double value : values) {
        variance += pow(value - mean, 2);
    }

    return variance / (values.size() );
}


void findMostConsistentMonth() {
     Data data= Airdata;
  //vector<string> months =  data.Month;
    vector<double> averageTemps;
    vector<double> variances;
 string months[]={"01","02","03","04","05","06","07","08","09","10","11","12"};


    for (string month : months) {
        vector<double> tempsOfMonth;

        // Collect all temperature values for the current month
        for (size_t i = 0; i < data.Month.size(); ++i) {
            if (data.Month[i] == month) {
                tempsOfMonth.push_back(data.M_temp[i]);
            }
        }

        // Calculate average temperature and variance for the current month
        double avgTemp = calculateAverage(tempsOfMonth);
        double variance = calculateVariance(tempsOfMonth);

        averageTemps.push_back(avgTemp);
        variances.push_back(variance);
    }

    // Find the index of the month with the smallest variance
    size_t mostConsistentIndex = 0;
    double smallestVariance = variances[0];
        double hottestMonthVal = averageTemps[0];
        int hottestmonthindex=0;
          double coldestMonthVal = averageTemps[0];
        int coldestmonthindex=0;
    for (size_t i = 0; i < variances.size(); ++i) {

        if (variances[i] < smallestVariance) {
            smallestVariance = variances[i];
            mostConsistentIndex = i;

        }

        if(averageTemps[i]>hottestMonthVal){
            hottestMonthVal=averageTemps[i];
            hottestmonthindex=i;
        }
          if(averageTemps[i]<coldestMonthVal){
            coldestMonthVal=averageTemps[i];
            coldestmonthindex=i;
        }


    }
//print hottest month
cout << "Hottest Month: " << months[hottestmonthindex] <<" Temperature :"<<hottestMonthVal<<endl;
//print coldest month
cout << "coldtest Month: " << months[coldestmonthindex] <<" Temperature :"<<coldestMonthVal<<endl;
    // Print the most consistent month, its average temperature, and variance
    cout << "Most Consistent Month: " << months[mostConsistentIndex] <<endl;
    cout << "Average Temperature: " << averageTemps[mostConsistentIndex] << "°C" <<endl;
    cout << "Variance: " << smallestVariance << endl;
}

void selectmonth() {

string preMonth;
int flag= 0;
int num_of_rows=0;
string selectedMonth;
string months[]={"01.January", "02.February", "03.March", "04.April", "05.May", "06.June", "07.July", "08.August", "09.September", "10.October", "11.November", "12.December"};
cout<<"-----------Available Months---------"<<endl;
    for (int i=1; i<13; i++)  {

               cout<<i<<"."+months[i-1]<<endl;


    }
    cout<<"Select Month:";
    cin>>selectedMonth;
    for(int i=0;i<Airdata.num_of_rows;i++){
        if(Airdata.Month[i]==selectedMonth){
                byMonth.code.push_back(Airdata.code[i]);
         byMonth.s_number.push_back(Airdata.s_number[i]);
            byMonth.Year.push_back(Airdata.Year[i]);
            byMonth.Month.push_back(Airdata.Month[i]);
            byMonth.Date.push_back(Airdata.Date[i]);
            byMonth.M_temp.push_back(Airdata.M_temp[i]);
            byMonth.Days_M_temp.push_back(Airdata.Days_M_temp[i]);
            byMonth.quality.push_back(Airdata.quality[i]);
            flag=1;
            num_of_rows++;
        }
        else{

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
                    if(preyear=="2023"){
                        break;
                    }
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

void choice3(){

int choice3;
 cout<<"1.Select by Year"<<endl;
cout<<"2.Select by Moth"<<endl;
cin>>choice3;
     if(choice3==1){
           selectyear();
            calcDtails("Year");

         showByYear();
        }
else{
       selectmonth();
       calcDtails("Month");
      showByMonth();

                 }



}


int main()
{


        //display a Welcome message
   cout << "Turing Moore Engineering Temperature Data Analyser 1.0" << endl;
       cout << "Your name: [Your Name]" << endl; // Replace [Your Name] with your actual name
    cout << "Your Student ID: [Your Student ID]" << endl; // Replace [Your Student ID] with your actual student ID




    cout << "Date the assignment is due: "<<"[date]"<<endl;

    cout << "Desired Level: HD" << endl;
      cout << endl<<"------Instructions-------"<<endl<<endl;
      cout<<"You can use this program to calculate various stats about temperature." << endl<<"Select 1 for analyse Bendigo Airport Data "<<endl<<"Select 2 for analyse Avalon Airport Data"<<endl<<"Select 3 for analyse both Data"<<endl<<"Select 4 for analyse custom input Data sheet";
    cout<<"Select e to exit and c to continue"<<endl<<"--------------------------------"<<endl;

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
                       findMostConsistentMonth();

                choice3();

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
                  findMostConsistentMonth();
                   choice3();

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
                calcDtails("Airdata");
                 showAirdata();
                  findMostConsistentMonth();
                choice3();


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
            readCSV(csvname, choice2);
             calcDtails("Airdata");
                 showAirdata();
                  findMostConsistentMonth();
                choice3();

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
