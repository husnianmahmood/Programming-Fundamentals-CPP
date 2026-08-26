#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string clientUser;
string clientEmail;
string clientCity;
int clientStatus;
int payOption;


string catalogItems[8] = {"T-Shirt", "Jeans", "Shoes", "Watch", "Hand Bag", "Headphones", "Mobile Cover", "Perfume"};
int catalogPrices[8] = {1200, 3500, 5000, 2500, 4200, 3000, 700, 2800};

int menuSelection;

string shoppingBasket[100];
int basketPrices[100];
int itemCounter = 0;

double shippingFeeVar = 0;
double taxValueVar = 0;
double aggregateTotalVar = 0;
double statusDiscountVar = 0;
double valueDiscountVar = 0;
double bankFeeVar = 0;
double grandTotalVar = 0;

void enrollCustomer(){
	cout << "Enter Account Username: ";
	getline(cin, clientUser);
	cout << "Enter Account Email Address: ";
	cin >> clientEmail;
	cout << "Enter Resident City: ";
	cin >> clientCity;
	cout << "Select Client Status: " << endl;
	cout << "1. First-Time Buyer" << endl;
	cout << "2. Frequent Buyer" << endl;
	cin >> clientStatus;
	cout << "Select Settlement Method: " << endl;
	cout << "1. Hand-to-Hand Cash" << endl;
	cout << "2. Electronic Card" << endl;
	cin >> payOption;
}

void printClientProfile(){
	cout << "\t CLIENT DATA SUMMARY" << endl << endl;
	cout << left << setw(27) << "User Name: " << clientUser << endl;
	cout << left << setw(27) << "Email ID: " << clientEmail << endl;
	cout << left << setw(27) << "Location: " << clientCity << endl;
	
	if(clientStatus == 1){
		cout << left << setw(27) << "Client Category: " << "First-Time" << endl;
	}
	else{
		cout << left << setw(27) << "Client Category: " << "Frequent" << endl;
	}
	
	if(payOption == 1){
		cout << left << setw(27) << "Settlement Mode: " << "Hand-to-Hand Cash" << endl;
	}
	else{
		cout << left << setw(27) << "Settlement Mode: " << "Electronic Card" << endl;
	}
}

void printCatalogMenu(){
	cout << endl << "\t\tSTOCK INVENTORY" << endl << endl;
	cout << left << setw(27) << "Code No. " << left << setw(50) << "Stock Description" << left << setw(100) << "Retail Rate" << endl;
	cout << endl;
	for(int i = 0; i < 8; i++){
		cout << left << setw(27) << i+1 << left << setw(50) << catalogItems[i] << left << setw(100) << catalogPrices[i] << endl;
	}
}

void showNavigationMenu(){
	cout << endl << endl << "\t--- SYSTEM NAVIGATION ---" << endl << endl;
	cout << "1. Review Account Profile" << endl;
	cout << "2. Browse Stock Inventory" << endl; 
	cout << "3. Push Goods to Basket" << endl;
	cout << "4. Inspect Basket Contents" << endl;
	cout << "5. Generate Store Receipt" << endl;
	cout << "6. EXIT" << endl;
}

void selectProducts(){
	int carryOn = 1;
	int itemIndex;
	while(carryOn == 1){
		cout << endl;
		cout << "Key in the product number you wish to purchase: ";
		cin >> itemIndex;
		cout << endl << "You Selected " << catalogItems[itemIndex - 1] << " valued at Rs. " << catalogPrices[itemIndex - 1] << endl;
		shoppingBasket[itemCounter] = catalogItems[itemIndex - 1];
		basketPrices[itemCounter] = catalogPrices[itemIndex - 1];
		itemCounter++;
		cout << endl << "Add another product? Enter 1 for YES, or any other number for NO: ";
		cin >> carryOn;
	}
}

void viewShoppingBasket(){
	cout << endl;
	cout << left << setw(27) << "" << left << setw(50) << "  MY BASKET" << left << setw(100) << "" << endl;
	cout << endl;
	for(int i = 0; i <= itemCounter - 1; i++){
		cout << left << setw(27) << i+1 << left << setw(42) << shoppingBasket[i] << left << setw(50) << basketPrices[i] << endl;
	}
}

double getAggregateTotal(){
	for(int i = 0; i <= itemCounter - 1; i++){
		aggregateTotalVar += basketPrices[i];
	}
	cout << "Items Aggregated Value:\t\t";
	return aggregateTotalVar;
}

double getShippingFee(){
	if(clientCity == "Lahore" || clientCity == "lahore" || clientCity == "Islamabad" || clientCity == "islamabad" || clientCity == "Karachi" || clientCity == "karachi"){
		cout << "Parcel Shipping Fee:\t\t";
		shippingFeeVar = 250;
		return shippingFeeVar;
	}
	else{
		cout << "Parcel Shipping Fee:\t\t";
		shippingFeeVar = 500;
		return shippingFeeVar;
	}
}

double getTaxValue(){
	cout << "Applied Government Tax:\t\t";
	taxValueVar = 0.17 * aggregateTotalVar;
	return aggregateTotalVar;
}

double getStatusDiscount(){
	if(clientStatus == 1){
		cout << "Client Profile Discount:\t";
		statusDiscountVar = -1 * (0.05 * aggregateTotalVar);
		return statusDiscountVar;
	}
	else{
		cout << "Client Profile Discount:\t";
		statusDiscountVar = -1 * (0.1 * aggregateTotalVar);
		return statusDiscountVar;
	}
}

double getValueDiscount(){
	if(aggregateTotalVar < 5000){
		cout << "Cart Value Rebate:\t\t\t";
		valueDiscountVar = 0;
		return valueDiscountVar;
	}
	else if(aggregateTotalVar >= 5000 && aggregateTotalVar <= 10000){
		cout << "Cart Value Rebate:\t\t";
		valueDiscountVar = -1 * (aggregateTotalVar * 0.05);
		return valueDiscountVar;
	}
	else{
		cout << "Cart Value Rebate:\t\t";
		valueDiscountVar = -1 * (aggregateTotalVar * 0.12);
		return valueDiscountVar;
	}
}

double getBankFee(){
	if(payOption == 1){
		cout << "Gateway Processing Fee:\t\t";
		bankFeeVar = 0;
		return bankFeeVar;
	}
	else{
		cout << "Gateway Processing Fee:\t\t";
		bankFeeVar = aggregateTotalVar * 0.025;
		return bankFeeVar;
	}
}

double getGrandTotal(){
	grandTotalVar = bankFeeVar + valueDiscountVar + statusDiscountVar + taxValueVar + shippingFeeVar + aggregateTotalVar;
	cout << endl << "Net Payable Bill:\t\t";
	return grandTotalVar;
}

int main (){
	cout << "\t\tONLINE SHOPPING INVOICE SYSTEM" << endl << endl;
	enrollCustomer();
	do{
		showNavigationMenu();
		cin >> menuSelection;
		
		switch(menuSelection){
			case 2:
				printCatalogMenu();
				break;
				
			case 3:
				selectProducts();
				break;
				
			case 5:
				cout << "\t\tRUN-TIME INVOICE ESTIMATION" << endl << endl;
				cout << getAggregateTotal() << endl;
				cout << getTaxValue() << endl;
				cout << getShippingFee() << endl;
				cout << getStatusDiscount() << endl;
				cout << getValueDiscount() << endl;
				cout << getBankFee() << endl;
				cout << getGrandTotal() << endl;
				cout << endl;
				cout << endl;
				break;
				
			case 1:
				printClientProfile();
				break;
				
			case 4:
				viewShoppingBasket();
				break;
				
			case 6:
				return 0;
				
			default:
				cout << "Notice: Unrecognized Menu Code Selection! :(";
				break;
		}
	}
	while(menuSelection != 6);
}
