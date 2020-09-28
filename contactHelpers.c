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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include<string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include"contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int Value;

	scanf(" %d%c", &Value, &NL);

	while (NL != '\n') {
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &Value, &NL);
	}

	return Value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int Num = getInt();

	while ((Num < min) || (Num > max)) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Num = getInt();
	}

	return Num;
}

// yes:
int yes(void)
{
	char YN = 'x';
	char NL = 'x';
	int answer;

	scanf(" %c%c", &YN, &NL);

	while ((NL != '\n') && (YN != 'y' || YN != 'Y' || YN != 'n' || YN != 'N')) {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &YN, &NL);
	}

	if (YN == 'y' || YN == 'Y') {
		answer = 1;
	}
	else {
		answer = 0;
	}

	return answer;
}

// menu:
int menu(void)
{
	printf("Contact Management System\n-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");

	return getIntInRange(0, 6);
	printf("\n");
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	int selection;
	struct Contact contacts[MAXCONTACTS] = { {{ "Rick", {'\0'}, "Grimes"},
												{ 11, "Trailer Park", 0, "A7A 2J2", "King City"},
												{ "4161112222", "4162223333", "4163334444" }},
											{
												{ "Maggie", "R.", "Greene" },
												{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												{ "9051112222", "9052223333", "9053334444" }},
											{
												{ "Morgan", "A.", "Jones" },
												{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
												{ "7051112222", "7052223333", "7053334444" }},
											{
												{ "Sasha", {'\0'}, "Williams" },
												{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
												{ "9052223333", "9052223333", "9054445555" }},
	};

	do {
		selection = menu();
		printf("\n");
		switch (selection) {
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			int choice = yes();
			if (choice == 1) {
				printf("\nContact Management System: terminated\n");
				return;
			}
			else {
				printf("\n");
			}
			break;
		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
			break;
		}
	} while ((selection >= 0) && (selection <= 6));
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i;
	while (needInput == 1) {
		scanf(" %10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
			for (i = 0; i < 10;i++) {
				if (phoneNum[i] < '0' || phoneNum[i] > '9') {
					printf("Enter a 10-digit phone number: ");
					needInput = 1;
					break;
				}
				else {
					needInput = 0;
				}
			}
		else {
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, index = -1;

	for (i = 0;i < size;i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			index = i;
			break;
		}
	}
	return index;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
	return;
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
	return;
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	printf("%s", contact->name.firstName);
	if (*contact->name.middleInitial != '\0') {
		printf(" %s ", contact->name.middleInitial);
	}
	else {
		printf(" ");
	}

	printf("%s\n", contact->name.lastName);

	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);

	return;
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, total = 0;

	displayContactHeader();
	for (i = 0;i < size;i++) {
		if (strlen(contacts[i].numbers.cell) != 0) {
			displayContact(&contacts[i]);
			total++;
		}
	}
	displayContactFooter(total);

	return;
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	int location;
	char number[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	location = findContactIndex(contacts, size, number);
	if (location != -1) {
		printf("\n");
		displayContact(&contacts[location]);
		printf("\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	return;
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i;
	for (i = 0;i < size;i++) {
		if (strlen(contacts[i].numbers.cell) == 0) {
			getContact(&contacts[i]);
			printf("--- New contact added! ---\n\n");
			i = size;
		}
		if (i == (size - 1)) {
			printf("*** ERROR: The contact list is full! ***\n\n");
		}
	}
	return;
}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	int choice;
	int location;
	char number[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);
	location = findContactIndex(contacts, size, number);

	if (location != -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[location]);

		printf("\nDo you want to update the name? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getName(&contacts[location].name);
		}

		printf("Do you want to update the address? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getAddress(&contacts[location].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		choice = yes();
		if (choice == 1) {
			getNumbers(&contacts[location].numbers);
		}

		printf("--- Contact Updated! ---\n\n");
	}
	else {
		printf("*** Contact NOT FOUND ***\n\n");
	}

}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	struct Contact empty = { { {'\0'}, {'\0'}, {'\0'} }, { 0, {'\0'}, 0, {'\0'}, {'\0'} }, { {'\0'}, {'\0'}, {'\0'} } };
	int location;
	char number[11];
	char choice;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	location = findContactIndex(contacts, size, number);
	if (location != -1) {
		printf("\nContact found:\n");
		displayContact(&contacts[location]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		choice = yes();
		if (choice == 1) {
			contacts[location] = empty;
			printf("--- Contact deleted! ---\n\n");
		}
		else {
			printf("\n");
		}
	}
	else {
		printf("*** Contact NOT FOUND ***\n");
	}

	return;
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	struct Contact temp;
	int i, j;
	for (i = size - 1;i > 0;i--) {
		for (j = 0;j < i;j++) {
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}
	printf("--- Contacts sorted! ---\n\n");
	return;
}