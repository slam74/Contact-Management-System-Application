#ifndef CONTACTS_H_
#define CONTACTS_H_

//==============================================
// Name:           Simon Lam
// Student Number: 150595197
// Email:          slam74@myseneca.ca
// Section:        NOO
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================


//--------------------------------
// Structure Types
//--------------------------------

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration
struct Contact {
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes below...             |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name);

// getAddress:
void getAddress(struct Address* address);

// getNumbers:
void getNumbers(struct Numbers* numbers);

// getContact:
void getContact(struct Contact* contact);


#endif // !CONTACTS_H_
