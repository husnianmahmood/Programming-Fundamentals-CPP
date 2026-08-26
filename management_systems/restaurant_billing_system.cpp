#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string userName;
string phoneNumber;
int dineTake;
int noOfPeople;

int choice;

double foodBill = 0;
double gst = 0;
double serviceChargeAmount = 0;
double bill = 0;

string item[8] = {"Chicken Burger", "Zinger Burger","Pizza Small","Pizza Large","Chicken Biryani","BBQ Platter","Fries","Cold Drink"};

int price[8] = {450,550,900,1800,350,1200,250,120};

void registerCustomer()
{
    cout << "Enter Your Name: ";
    getline(cin >> ws, userName);
    cout << "Enter Your Phone Number: ";
    cin >> phoneNumber;
    do
    {
        cout << "Press 1 for Dine In, 2 for Take Away: ";
        cin >> dineTake;
        if (dineTake == 1 || dineTake == 2)
            break;

        cout << "Invalid Choice!\n";
    } while (true);
    do
    {
        cout << "Enter Number of People: ";
        cin >> noOfPeople;
        if (noOfPeople > 0)
            break;
        cout << "Number of People Must Be Greater Than 0.\n";
    } while (true);
}

void displayMainMenu()
{
    cout << endl << "\t\tMain Menu" << endl << endl;
    cout << "1. View Food Menu" << endl;
    cout << "2. Place Order" << endl;
    cout << "3. Calculate Bill" << endl;
    cout << "4. View Customer Details" << endl;
    cout << "5. Exit" << endl;
}

void displayFoodMenu()
{
    cout << endl << "\t\tFood Menu" << endl << endl;
    cout << left << setw(10) << "Item No." << setw(25) << "Item" << "Price" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << left << setw(10) << i + 1 << setw(25) << item[i] << price[i] << endl;
    }
}

void placeOrder()
{
    int repChoice = 1;
    int itemChoice;
    while (repChoice == 1)
    {
        do
        {
            cout << "Enter Item Number (1-8): ";

            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= 8)
                break;

            cout << "Invalid Item Number!\n";

        } while (true);

        cout << endl << "You Chose " << item[itemChoice - 1] << " That Costs " << price[itemChoice - 1] << endl;
        foodBill += price[itemChoice - 1];
        cout << endl << "Would You Like To Order Something Else?" << endl;
        cout << "Press 1 For Yes, Anything Else For No: ";
        cin >> repChoice;
    }
    cout << "\nFood Bill: " << foodBill << endl;
}

double serviceChargeCal()
{
    if (dineTake == 1){
        return foodBill * 0.10;
    }

    return foodBill * 0.05;
}

double gstCal()
{
    return foodBill * 0.16;
}

double deliveryCharge()
{
    if (dineTake == 1){
        return 0;
    }

    if (bill > 5000){
        return 0;
    }

    return 200;
}

void withoutDiscBill()
{
    bill = foodBill + gst + serviceChargeAmount;
}

double disc(double &bill)
{
    double discount = 0;

    if (bill >= 3000 && bill < 5000){
        discount = bill * 0.05;
    }
    else if (bill >= 5000 && bill < 10000){
        discount = bill * 0.10;
    }
    else if (bill >= 10000){
        discount = bill * 0.15;
    }
    bill -= discount;
    cout << left << setw(30) << "\tDiscount:" << discount << endl;
    return bill;
}

void displayCustomerDetails()
{
    cout << "\n\t\tCustomer Details\n\n";
    cout << left << setw(25) << "Customer Name:" << userName << endl;
    cout << left << setw(25) << "Phone Number:" << phoneNumber << endl;
    if (dineTake == 1){
        cout << left << setw(25) << "Order Type:" << "Dine In" << endl;
    }
    else{
        cout << left << setw(25)
             << "Order Type:"
             << "Take Away" << endl;
    }
    cout << left << setw(25) << "Number Of People:" << noOfPeople << endl;
}

int main()
{
    cout << "\t\tRestaurant Bill System\n\n";
    registerCustomer();
    do
    {
        displayMainMenu();
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                displayFoodMenu();
                break;
            }
            case 2:
            {
                placeOrder();
                break;
            }
            case 3:
            {
                if (foodBill <= 0)
                {
                    cout << "\nNo Order Placed Yet.\n";
                    break;
                }

                gst = gstCal();
                serviceChargeAmount = serviceChargeCal();
                withoutDiscBill();
                cout << "\n\t\tBill Calculation\n\n";
                cout << left << setw(30) << "\tFood Bill:" << foodBill << endl;
                cout << left << setw(30) << "\tService Charge:" << serviceChargeAmount << endl;
                cout << left << setw(30) << "\tGST:" << gst << endl;
                cout << left << setw(30) << "\tBill Before Discount:" << bill << endl;
                disc(bill);
                double delivery = deliveryCharge();
                cout << left << setw(30) << "\tDelivery Charge:" << delivery << endl;
                bill += delivery;
                cout << left << setw(30) << "\tFinal Bill:" << bill << endl;
				break;
            }
            case 4:
            {
                displayCustomerDetails();
                break;
            }
            case 5:
            {
                cout << "\nThank You For Using Restaurant Billing System\n";
                break;
            }
            default:
            {
                cout << "\nInvalid Input :(\n";
                break;
            }
    }
    } while (choice != 5);

    return 0;
}
