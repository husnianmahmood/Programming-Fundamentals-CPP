#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string clientName;
string businessName;
int businessType;
int campaignDays;

int choice;
int platformChoice = 0;

string platform[3] = {"Instagram","Facebook","LinkedIn"};
int managementCharge[3] = {15000,12000,20000};

int staticPosts = 0;
int videoPosts = 0;
int carouselPosts = 0;

double adBudget = 0;

double postDesignCost = 0;
double handlingFee = 0;
double extraCharges = 0;
double gst = 0;
double bill = 0;

void registerClient()
{
    cout << "\n\t\tClient Registration\n\n";
    cout << "Enter Client Name: ";
    getline(cin >> ws, clientName);
    cout << "Enter Business Name: ";
    getline(cin, businessName);
    do
    {
        cout << "\nSelect Business Type\n";
        cout << "1. Small Business\n";
        cout << "2. Medium Business\n";
        cout << "3. Corporate Business\n";
        cout << "Enter Choice: ";

        cin>>businessType;

        if (businessType >= 1 && businessType <= 3)
            break;
        // jab function break ho jy ga to baki kuch b run nahi hoga
		cout << "Invalid Choice!\n";
    } while (true);
    do
    {
        cout << "Enter Campaign Duration (Days): ";
        cin >> campaignDays;
        if (campaignDays > 0)
            break;
        cout << "Days Must Be Greater Than 0.\n";
    } while (true);
}
void displayPlatforms()
{
    cout << "\n\t\tSocial Media Platforms\n\n";
    cout << left << setw(15) << "Platform No." << setw(20) << "Platform" << "Charges" << endl;
    
    for (int i = 0; i < 3; i++){
        cout << left << setw(15) << i + 1 << setw(20) << platform[i] << managementCharge[i] << endl;
    }
}
void selectPlatform()
{
    do
    {
        cout << "\nSelect Platform (1-3): ";
    	cin >> platformChoice;
        if (platformChoice >= 1 && platformChoice <= 3)
            break;
        cout << "Invalid Platform Choice!\n";
    } while (true);
    cout << "\nSelected Platform: " << platform[platformChoice - 1] << endl;
}
double postDesignCal()
{
    cout << "\nEnter Number Of Static Posts: ";
    cin >> staticPosts;
    cout << "Enter Number Of Reel/Video Posts: ";
    cin >> videoPosts;
    cout << "Enter Number Of Carousel Posts: ";
    cin >> carouselPosts;
    return (staticPosts * 1000) + (videoPosts * 2500) + (carouselPosts * 1800);
}
double handlingFeeCal()
{
    cout << "Enter Advertisement Budget: ";
    cin >> adBudget;
    if (adBudget < 50000){
        return adBudget * 0.05;
    } else if (adBudget <= 100000) {
        return adBudget * 0.08;
    }
    return adBudget * 0.10;
}
double extraDurationCal()
{
    if (campaignDays > 30){
        return (campaignDays - 30) * 500;
    }
    return 0;
}
double gstCal(double amount){
    return amount * 0.16;
}
double discountCal(double &amount)
{
    double discount = 0;

    if (businessType == 1){
        discount = amount * 0.05;
    }
    else if (businessType == 2){
        discount = amount * 0.08;
    }
	else if (businessType == 3){
        discount = amount * 0.10;
    }
    amount -= discount;

    cout << left << setw(35) << "Discount:" << discount << endl;

    return discount;
}

// Display Client Details
void displayClientDetails()
{
    cout << "\n\t\tClient Details\n\n";

    cout << left << setw(25) << "Client Name:" << clientName << endl;
    cout << left << setw(25) << "Business Name:" << businessName << endl;
    if (businessType == 1) {
        cout << left << setw(25) << "Business Type:" << "Small Business" << endl;
    }
    else if (businessType == 2) {
        cout << left << setw(25) << "Business Type:" << "Medium Business" << endl;
    }
    else {
        cout << left << setw(25) << "Business Type:" << "Corporate Business" << endl;
    }

    cout << left << setw(25) << "Campaign Duration:" << campaignDays << " Days" << endl;
    
    if (platformChoice > 0) {
		cout << left << setw(25) << "Selected Platform:" << platform[platformChoice - 1] << endl;
    }
}
void displayBill()
{
    if (platformChoice == 0) {
        cout << "\nPlease Select A Platform First.\n";
        return;
    }
    postDesignCost = postDesignCal();
    handlingFee = handlingFeeCal();
    extraCharges = extraDurationCal();

    double serviceCost = managementCharge[platformChoice - 1] + postDesignCost + handlingFee + extraCharges;
    
    gst = gstCal(serviceCost);

    bill = serviceCost + gst;

    cout << "\n				SOCIAL MEDIA CAMPAIGN BILL 			\n\n";

    cout << "Client Name: " << clientName << endl;
    cout << "Business Name: " << businessName << endl;
    if (businessType == 1){
        cout << "Business Type: Small Business" << endl;
    }
    else if (businessType == 2) {
        cout << "Business Type: Medium Business" << endl;
    }
    else {
        cout << "Business Type: Corporate Business" << endl;
    }
    cout << "Selected Platform: " << platform[platformChoice - 1] << endl;
    cout << "Campaign Duration: " << campaignDays << " Days" << endl;
    cout << endl;
    cout << left << setw(35) << "Platform Management Charges:" << managementCharge[platformChoice - 1]<< endl;
    cout << left << setw(35) << "Post Design Cost:" << postDesignCost << endl;
    cout << left << setw(35) << "Ad Budget:" << adBudget<< endl;
    cout << left << setw(35) << "Ad Handling Fee:" << handlingFee << endl;
    cout << left << setw(35) << "Extra Duration Charges:" << extraCharges << endl;
    cout << left << setw(35) << "GST:" << gst << endl;
    discountCal(bill);
    cout << "\n------------------------------------------------\n";
    cout << left << setw(35) << "Final Campaign Cost:" << bill << endl;
    cout << "================================================\n";
}
void displayMainMenu()
{
    cout << "\n\t\tMain Menu\n\n";
    cout << "1. View Platforms" << endl;
    cout << "2. Select Campaign Platform" << endl;
    cout << "3. Calculate Campaign Cost" << endl;
    cout << "4. View Client Details" << endl;
    cout << "5. Exit" << endl;
    cout << "\nEnter Choice: ";
}
int main()
{
    cout << "\t\tSocial Media Campaign Management System\n";
    registerClient();
    do
    {
        displayMainMenu();
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                displayPlatforms();
                break;
            }
            case 2:
            {
                selectPlatform();
                break;
            }
            case 3:
            {
                displayBill();
                break;
            }
            case 4:
            {
                displayClientDetails();
                break;
            }
            case 5:
            {
                cout << "\nThank You For Using Social Media Campaign Management System\n";
                break;
            }
            default:
            {
                cout << "\nInvalid Choice!\n";
                break;
            }
        }
    } while (choice != 5);
    return 0;
}
