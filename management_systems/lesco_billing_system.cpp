#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
const double meterRent = 250.0;
const double tvFee = 35.0;
const double electricityDutyTax = 0.015; 
const double gstTax = 0.18;              
const double householdTax = 0.10;        
const double commercialTax = 0.15;       
const double baseConnection = 250000;

string customerName;
string customerID;
string customerType;

int menuChoice;

double units;
int tvChoice;

void customerRegistration()
{
    cout << "Enter Customer Name: ";
    getline(cin >> ws, customerName);
    cout << "Enter Customer ID: ";
    cin >> customerID;
    cout << "Enter Connection Type (Household/Commercial): ";
    cin >> customerType;
    cout << "Enter Units Consumed: ";
    cin >> units;
}
void Menu()
{
    cout << "\n										\n";
    cout << "\tLESCO MENU\n";
    cout << "										\n";
    cout << "1. Calculate Bill\n";
    cout << "2. Apply for New Electricity Connection\n";
    cout << "3. View Customer Details\n";
    cout << "4. Exit\n";
    cout << "Enter Choice: ";
}
void displayCustomerDetails()
{
    cout << "\n			 CUSTOMER DETAILS			\n";
    cout << left << setw(25) << "Customer Name:" << customerName << endl;
    cout << left << setw(25) << "Customer ID:" << customerID << endl;
    cout << left << setw(25) << "Connection Type:" << customerType << endl;
    cout << left << setw(25) << "Units Consumed:" << units << endl;
}
double charges()
{
    double unitRates[8] = {12.21,14.53,31.51,38.41,41.62,43.04,44.18,49.10};
    double unitCharge;
    if (units <= 100)
        unitCharge = unitRates[0] * units;
    else if (units <= 200)
        unitCharge = unitRates[1] * units;
    else if (units <= 300)
        unitCharge = unitRates[2] * units;
    else if (units <= 400)
        unitCharge = unitRates[3] * units;
    else if (units <= 500)
        unitCharge = unitRates[4] * units;
    else if (units <= 600)
        unitCharge = unitRates[5] * units;
    else if (units <= 700)
        unitCharge = unitRates[6] * units;
    else
        unitCharge = unitRates[7] * units;
    return unitCharge;
}
double gstTaxCal(double amount)
{
    	return amount * gstTax;
}
double incomeTaxCal(double amount)
{
    	if (customerType == "Household" || customerType == "household" || customerType == "1")
    	{
        	return amount * householdTax;
    	}

    	return amount * commercialTax;
}
double electricalDuty()
{
    	return charges() * electricityDutyTax;
}
double tvCharges()
{
    	if (tvChoice == 1)
        	return tvFee;
    	return 0;
}

double fixedCharges()
{
    	if (units <= 300)
        	return 0;
    	else if (units <= 400)
        	return 200;
    	else if (units <= 500)
        	return 400;
    	else if (units <= 600)
        	return 600;
    	else if (units <= 700)
        	return 800;
    	else
        	return 1000;
}
double finalBill()
{
    	double preTotal = charges() + electricalDuty() + fixedCharges() + meterRent + tvCharges();
    	double gst = gstTaxCal(preTotal);
    	double incomeTax = incomeTaxCal(preTotal);

    	return preTotal + gst + incomeTax;
}
double newConnectionCharges(){
double meterCost;
double cableCost;
double securityCost;
double additionalCharges;
double connectionCost = 0;

string newCustomerTypeChoice;
int meterNo;
int properConnection;

double typeValue = 0;

    cout << "\nEnter Meter Cost: ";
    cin >> meterCost;
    cout << "Enter Meter Cable Cost: ";
    cin >> cableCost;
    cout << "Enter Security Cost: ";
    cin >> securityCost;

    cout << "\nConnection Type\n";
    cout << "1. Domestic\n";
    cout << "2. Commercial\n";
    cin >> newCustomerTypeChoice;

    cout << "You Entered: " << newCustomerTypeChoice << endl;

	if(newCustomerTypeChoice == "1" || newCustomerTypeChoice == "Domestic" || newCustomerTypeChoice == "domestic")
	{
    	typeValue = 2500;
    	cout << "Domestic Selected" << endl;
	}
	else if(newCustomerTypeChoice == "2" || newCustomerTypeChoice == "Commercial" || newCustomerTypeChoice == "commercial")
	{
    	typeValue = 35000;
    	cout << "Commercial Selected" << endl;
	}
	else
	{
    	cout << "Invalid Input!" << endl;
    	return 0;
	}
	
    cout << "Enter Number of Meters (1 or 2): ";
    cin >> meterNo;

    additionalCharges = meterNo * typeValue;

    cout << "Proper Connection?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    cin >> properConnection;

    if (properConnection == 1){
        connectionCost += baseConnection;
    }
    connectionCost = connectionCost + meterCost + cableCost + securityCost + additionalCharges;

    cout << "\nTotal New Connection Cost = " << connectionCost << endl;
    return connectionCost;
}
int main()
{
    cout << "\n\t\tLESCO ELECTRICITY BILL \n\n";
    customerRegistration();
    do
    {
        Menu();
        cin >> menuChoice;
        switch (menuChoice)
        {
            case 1:
            {
                cout << "\nDo you have a TV?\n";
                cout << "1. Yes\n";
                cout << "2. No\n";
                cin >> tvChoice;

                double preTotal = charges() + electricalDuty() + fixedCharges() + meterRent + tvCharges();

				cout << "\n------------------------------------------\n";
				cout << "        LESCO ELECTRICITY BILL\n";
				cout << "--------------------------------------------\n\n";

				cout << "Customer Name: " << customerName << endl;
				cout << "Customer ID: " << customerID << endl;
				cout << "Customer Type: " << customerType << endl;
				cout << "Units Consumed: " << units << endl;
				cout << "\n";
				cout << left << setw(40) << "Electricity Consumption Charges: Rs. " << charges() << endl;
				cout << left << setw(40) << "Electricity Duty: Rs. " << electricalDuty() << endl;
				cout << left << setw(40) << "Fixed Charges: Rs. " << fixedCharges() << endl;
				cout << left << setw(40) << "Meter Rent: Rs. " << meterRent << endl;
				cout << left << setw(40) << "TV Fee: Rs. " << tvCharges() << endl;
				cout << left << setw(40) << "GST: Rs. " << gstTaxCal(preTotal) << endl;
				cout << left << setw(40) << "Income Tax: Rs. " << incomeTaxCal(preTotal) << endl;
				cout << "\n";
				cout << left << setw(40) << "Total Payable Bill: Rs. " << finalBill() << endl;

				cout << "---------------------------------------------\n";
				break;
			}
            case 2:
                newConnectionCharges();
                break;
            case 3:
                displayCustomerDetails();
                break;
            case 4:
                cout << "\nThank You For Using LESCO System\n";
                break;

            default:
                cout << "\nInvalid Choice\n";
        }
    } while (menuChoice != 4);

    return 0;
    
}
