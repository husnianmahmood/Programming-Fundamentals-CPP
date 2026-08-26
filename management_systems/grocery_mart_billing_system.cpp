#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


string stockItems[8] = {"Rice 1 KG", "Sugar 1 KG", "Cooking Oil 1 Litre", "Milk Pack", "Tea Pack", "Flour 5 KG", "Eggs Dozen", "Detergent"};
int stockPrices[8] = {350, 180, 580, 220, 450, 950, 320, 600};


double totalGross = 0;
double totalTax = 0;
double memberDiscVal = 0;
double promoDiscVal = 0;
double cardFeeVal = 0;

double netAmount = 0;

double oldLoyaltyPoints;
double totalPointsAccumulated = 0;
double pointsToUse;
double postLoyaltyBill;
double remainingPoints;

int userMenuSelection;
int wantToRedeemPoints;
string userCart[100];
int userCartPrices[100];
int itemsInCartCount = 0;


string shopperName;
string shopperID;
int shopperCategory;
int selectedPayMethod;

void signUpCustomer(){
    cout << "Please Enter Your Name: ";
    cin.ignore(); 
    getline(cin, shopperName);
    cout << "Please Enter Your ID: ";
    cin >> shopperID;
    cout << "Choose Shopper Category: " << endl;
    cout << "1. Regular Type" << endl;
    cout << "2. Premium Member" << endl;
    cin >> shopperCategory;
    cout << "Select Mode of Payment: " << endl;
    cout << "1. Cash Payment" << endl;
    cout << "2. Card Payment" << endl;
    cin >> selectedPayMethod;
}

void showNavMenu(){
    cout << endl << endl << "\t--- STORE NAVIGATION ---" << endl << endl;
    cout << "1. Profile Info"  << endl;
    cout << "2. Browse Products" << endl; 
    cout << "3. Purchase Products" << endl;
    cout << "4. Review Basket" << endl;
    cout << "5. Process Invoice" << endl;
    cout << "6. Terminal Shutdown" << endl;
}

void printStockCatalogue(){
    cout << endl << "\t\tPRODUCT CATALOGUE" << endl << endl;
    cout << left << setw(27) << "Code No. " << left << setw(50) << "Product Details" << left << setw(100) << "Retail Price" << endl;
    cout << endl;
    for(int i = 0; i < 8; i++){
        cout << left << setw(27) << i+1 << left << setw(50) << stockItems[i] << left << setw(100) << stockPrices[i] << endl;
    }
}

void addToBasket(){
    int loopFlag = 1;
    int productSelection;
    while(loopFlag == 1){
        cout << endl;
        cout << "Enter the specific item index to drop into basket: ";
        cin >> productSelection; 
        cout << endl << "Selected Product: " << stockItems[productSelection - 1] << " | Value: Rs. " << stockPrices[productSelection - 1] << endl;
        userCart[itemsInCartCount] = stockItems[productSelection - 1];
        userCartPrices[itemsInCartCount] = stockPrices[productSelection - 1];
        itemsInCartCount++;
        cout << endl << "Add more goods? Type 1 for Yes, or any other digit for No: ";
        cin >> loopFlag;
    }
}

void viewCurrentBasket(){
    cout << endl;
    cout << left << setw(27) << "" << left << setw(50) << "  MY BASKET" << left << setw(100) << "" << endl;
    cout << endl;
    for(int i = 0; i <= itemsInCartCount - 1; i++){
        cout << left << setw(27) << i+1 << left << setw(42) << userCart[i] << left << setw(50) << userCartPrices[i] << endl;
    }
}

double fetchGrossBill(){
    for(int i = 0; i <= itemsInCartCount - 1; i++){
        totalGross += userCartPrices[i];
    }
    cout << "Initial Gross Total:\t\t";
    return totalGross;
}

double fetchSalesTax(){
    for(int i = 0; i <= itemsInCartCount - 1; i++){
        if(userCartPrices[i] == 600){
            totalTax += 0.1 * userCartPrices[i];
        }
        else{
            totalTax += 0.05 * userCartPrices[i];
        }
    }
    cout << "Government Sales Tax:\t\t";
    return totalTax;
}

double fetchMemberDiscount(){
    if(shopperCategory == 1){
        cout << "Tier Reward Rebate:\t\t";
        memberDiscVal = 0;
        return 0;
    }
    else{
        cout << "Tier Reward Rebate:\t\t";
        memberDiscVal = -1 * (totalGross * 0.07);
        return memberDiscVal;
    }
}

double fetchVolumeDiscount(){
    if(totalGross < 5000){
        cout << "Volume Based Rebate:\t\t";
        promoDiscVal = 0;
        return promoDiscVal;
    }
    else if(totalGross >= 5000 && totalGross <= 10000){
        cout << "Volume Based Rebate:\t\t";
        promoDiscVal = -1 * (totalGross * 0.05);
        return promoDiscVal;
    }
    else{
        cout << "Volume Based Rebate:\t\t";
        promoDiscVal = -1 * (totalGross * 0.1);
        return promoDiscVal;
    }
}

double fetchCardSurcharge(){
    if(selectedPayMethod == 1){
        cout << "Merchant Gateway Charge:\t";
        cardFeeVal = 0;
        return cardFeeVal;
    }
    else{
        cout << "Merchant Gateway Charge:\t";
        cardFeeVal = totalGross * 0.02;
        return cardFeeVal;
    }
}

double fetchNetTotal(){
    cout << endl << "Calculated Net Amount:\t\t";
    netAmount = cardFeeVal + promoDiscVal + memberDiscVal + totalTax + totalGross;
    return netAmount;
}

double updateLoyaltyTokens(){
    totalPointsAccumulated = oldLoyaltyPoints + (netAmount / 100);
    cout << "Consolidated Loyalty Points:\t";
    return totalPointsAccumulated;
}

double executeTokenRedemption(){
    if(wantToRedeemPoints == 1){
        cout << "Specify quantity of points to checkout with: ";
        cin >> pointsToUse;
        cout << endl;
        postLoyaltyBill = netAmount - pointsToUse;
        remainingPoints = totalPointsAccumulated - pointsToUse;
        cout << "Retained Club Points Balance:\t\t" << remainingPoints;
        cout << endl;
        cout << "Adjusted Net Payable after using " << pointsToUse << " tokens:\t";
        return postLoyaltyBill;
    }
    return 0;
}

void printShopperProfile(){
    cout << "\t ACCOUNT HOLDER SUMMARY" << endl << endl;
    cout << left << setw(27) << "Account Holder Name: " << shopperName << endl;
    cout << left << setw(27) << "Account Unique ID: " << shopperID << endl;
    
    if(shopperCategory == 1){
        cout << left << setw(27) << "Account Standing: " << "Regular Tier" << endl;
    }
    else{
        cout << left << setw(27) << "Account Standing: " << "Premium Member" << endl;
    }
    
    if(selectedPayMethod == 1){
        cout << left << setw(27) << "Active Payment Mode: " << "Cash Settlement" << endl;
    }
    else{
        cout << left << setw(27) << "Active Payment Mode: " << "Card Settlement" << endl;
    }
}

int main (){
    cout << "\t\tMARKETPLACE CHECKOUT TERMINAL" << endl << endl;
    signUpCustomer();
    do{
        showNavMenu();
        cin >> userMenuSelection;
        
        switch(userMenuSelection){
            case 2:
                printStockCatalogue();
                break;
                
            case 3:
                addToBasket();
                break;
                
            case 5:
                cout << "\t\tCOMPILING RUNTIME INVOICE" << endl << endl;
                cout << "Key in Previous Loyalty Points Balance:\t";
                cin >> oldLoyaltyPoints;
                cout << endl;
                cout << fetchGrossBill() << endl;
                cout << fetchSalesTax() << endl;
                cout << fetchMemberDiscount() << endl;
                cout << fetchVolumeDiscount() << endl;
                cout << fetchCardSurcharge() << endl;
                cout << fetchNetTotal() << endl;
                cout << updateLoyaltyTokens();
                cout << endl;
                cout << endl;
                cout << "Trigger Token Cash-In? Insert 1 for YES, or any other integer for NO: ";
                cin >> wantToRedeemPoints;
                cout << executeTokenRedemption();
                break;
                
            case 1:
                printShopperProfile();
                break;
                
            case 4:
                viewCurrentBasket();
                break;
                
            case 6:
                return 0;
                
            default:
                cout << "Error: Unrecognized Input Command!";
                break;
        }
    }
    while(userMenuSelection != 6);
}
