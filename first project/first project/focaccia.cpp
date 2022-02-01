/**
 * focaccia.cpp
 *
 * <# Daijour Williams #>
 * <# daijourw #>
 *
 * EECS 183: Project 1
 * Winter 2022
 * 
 * Project UID: fde244392017fe65ebcc34f01c226b11f113bb3dc6dae8af4cb6ea11bf76f7c8
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);

int main() {
    int people = 0;

    cout << "How many people do you need to serve? " << endl << endl;
    cin >> people;

    /* TODO: add your code below */
    /* Loaves */
    const double People_Per_loaf = 4.0;
    int loaves = ceil(people / People_Per_loaf);
    
    cout << "You need to make: " << loaves <<  " " << pluralize("loaf", "loaves", loaves) << " of focaccia" << endl << endl;
    
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    
    
    /* flour. define flour cups per loaf, flour cups per bag, */
    const double Flour_Cups_Per_Loaf = 5.0;
    const double Flour_Cups_Per_Bag = 20.0;
    const double CupsOfFlour = Flour_Cups_Per_Loaf * loaves;
    const double FlourBags = ceil(CupsOfFlour / Flour_Cups_Per_Bag);
    /*cout << endl << FlourBags << endl;*/
    
    /*const int FlourBags = ceil((loaves * Flour_Cups_Per_Loaf)/ Flour_Cups_Per_Bag);*/
    cout << FlourBags << " " << pluralize("bag", "bags", FlourBags) << " of flour" << endl;
    
    double PricePerBag = 2.69;
    double FlourCost = PricePerBag * FlourBags;
    
    
    /*yeast yeastteaspoons per pack == 2.25,*/
    double Yeast_Teaspoons_Per_Loaf = 1.75;
    double Yeast_Teapoons_Per_Pack = 2.25;
    
    int YeastPacks = ceil((loaves * Yeast_Teaspoons_Per_Loaf) / Yeast_Teapoons_Per_Pack);
    cout << YeastPacks << " " << pluralize("package", "packages", YeastPacks) << " of yeast" << endl;
    
    double PricePerPack = 0.40;
    double YeastCost = PricePerPack * YeastPacks;
    
    
    /* salt */
    double Salt_Teaspoons_Per_Loaf = 1.875;
    double Salt_Teaspoons_Per_Canister = 30/5;
    
    int SaltCanisters = ceil(loaves * Salt_Teaspoons_Per_Loaf / Salt_Teaspoons_Per_Canister);
    cout << SaltCanisters << " " << pluralize("canister", "canisters", SaltCanisters) << " of salt" << endl;
    
    double PricePerCanister = 0.49;
    double SaltCost = PricePerCanister * SaltCanisters;
    
    /* olive oil */
    double OliveOil_Per_Loaf = 14.8 * 2;
    double OliveOil_Per_Bottle = 500;
    
    int OliveOilBottles = ceil(loaves * OliveOil_Per_Loaf / OliveOil_Per_Bottle);
    cout << OliveOilBottles << " " << pluralize("bottle", "bottles", OliveOilBottles) << " of olive oil" << endl;
    
    double PricePerBottle = 6.39;
    double OliveOilCost = PricePerBottle * OliveOilBottles;
    
    
    /* price */
    double TotalCost = FlourCost + YeastCost + SaltCost + OliveOilCost;
    cout << "Total expected cost of ingredients: $" << TotalCost << endl;
    cout << "Have a great party!" << endl;
    


    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
