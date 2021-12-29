#include <iostream>
using namespace std;

// Class to store contact details
class node {
	string name;
	string email;
	long int tel;
	int id;

public:
	node()
	{
		tel = 0;
		id = 0;
	}
	friend class hashing;
};

class hashing {

	// Maximum size of directory is 100
	node data[100];
	string n;
	string e;
	long int t;
	int i, index;

public:
	hashing()
	{
		i = 0;
		t = 0;
	}

	// This method takes detail from the user like ID, Name and Telephone number
	// then creates new record in the hashtable.
	void create_contact(int size)
	{
		// Enter ID
		int i = rand();

		// Enter Name
		n = "Joshua Monyei";
		
		// Enter mail
		e = "monyeijoshua@outlook.com";

		// Enter telephone number
		t = 2348153468883;
		cout << "\nEnter name: "
		    << n;
		cout << "\nEnter email: "
		    << e;
		cout << "\nEnter telephone number: "
			<< t;
		index = i % size;

		// Inserting record using linear
		// probing in case of collision
		for (int j = 0; j < size; j++) {
			if (data[index].id == 0) {
				data[index].id = i;
				data[index].name = n;
				data[index].email = e;
				data[index].tel = t;
				break;
			}
			else
				index
					= (index + 1) % size;
		}
	}
    
    // This function is created to display all the record of the phonebook.
	void display_contact(int size)
	{
		cout << "\n\tID \tNAME \t\tEMAIL \t\t\tTELEPHONE ";
		// Displaying the details of all records of the directory.
		for (int a = 0; a < size; a++) {
			if (data[a].id != 0) {
				cout << "\n\t"
					<< data[a].id
					<< " \t"
					<< data[a].name
					<< " \t"
					<< data[a].email
					<< " \t"
					<< data[a].tel;
			}
		}
	}
	
	// This method takes the key of the record to be searched.
	// Then, it traverses the hash table, if a contact id matches
	// with the key it displays the contact detail.
	void search_contact(int size)
	{
		long int index1, key, flag = 0;
		key = 2348153468883;
		cout << "\nEnter telephone number to search : "
			<< key;
		index1 = key % size;

		// Traversing the directory linearly inorder to search contact detail
		for (int a = 0; a < size; a++) {
			if (data[index1].tel == key) {
				flag = 1;
				cout << "\nContact found:";
				cout << "\n\tID ";
				cout << "\tNAME ";
				cout << "\t\t\tEMAIL";
				cout << " \t\t\tTELEPHONE ";
				cout << "\n\t"
					<< data[index1].id
					<< " "
					<< data[index1].name
					<< " \t"
					<< data[index1].email
					<< "\t"
					<< data[index1].tel;
				break;
			}
			else
				index1
					= (index1 + 1) % size;
		}
		if (flag == 0)
			cout << "\nRecord not found";
	}

	// This method takes the id of the contact and updates it
	void update_contact(int size)
	{
		int index1, flag = 0;
		long int key = 2348153468883;
		cout << "\nEnter phone number to update : "
			<< key;
		index1 = key % size;
		// Traversing the directory
		// linearly inorder to search contact detail
		for (int a = 0; a < size; a++) {
			if (data[index1].tel
				== key) {
				flag = 1;
				break;
			}
			else
				index1
					= (index1 + 1) % size;
		}
		// If the record is found
		// the details are updated
		if (flag == 1) {
			n = "XYZ";
			t = 2349014642748;
			data[index1].name = n;
			data[index1].tel = t;
			cout << "\nEnter name: "
				<< n;
			cout << "\nEnter telephone number: "
				<< t;
			cout << "\nDetails updated: ";
			cout << "\n\tID \t\tNAME \t\tEMAIL \t\t\tTELEPHONE ";
			cout << "\n\t"
				<< data[index].id
				<< " \t"
				<< data[index1].name
				<< " \t"
				<< data[index].email
				<< " \t"
				<< data[index1].tel;
		}
		if (flag == 0)
			cout << "\nRecord not found";
	}

	
	// This method takes the key of the record to be deleted.
	// Then, it searches in hash table if record id matches
	// with the key. Then, that record is deleted.
	void delete_contact(int size)
	{
		int index1, flag = 0;
		long int key = 2349014642748;
		cout << "\nEnter telephone number to delete : "
			<< key;
		index1 = key % size;
		// Traversing the directory
		// linearly inorder to delete the record detail
		for (int a = 0; a < size; a++) {
			if (data[index1].tel
				== key) {
				flag = 1;
				data[index1].id = 0;
				data[index1].name = " ";
				data[index1].tel = 0;
				cout << "\nContact deleted successfully";
				break;
			}
			else
				index1
					= (index1 + 1) % size;
		}
		if (flag == 0)
			cout << "\nRecord not found";
	}
};

// Driver code
int main()
{
	// size of directory
	int size;

	// creating object of hashing
	// class
	hashing s;
	size = 20;

	// Creating a record in directory
	cout << "\n1.CREATE contact ";
	s.create_contact(size);

	// Display available record details
	cout << "\n\n\n2.DISPLAY contact ";
	s.display_contact(size);

	// Searching a record detail in the directory
	cout << "\n\n\n3.SEARCH contact";
	s.search_contact(size);

	// Updating the existing details of a record
	cout << "\n\n\n4.UPDATE contact ";
	s.update_contact(size);

	// Removing specified existing record from dictionary
	cout << "\n\n\n5.DELETE contact ";
	s.delete_contact(size);

	return 0;
}

// Expected output
// /tmp/KI2klu2ish.o
// 1.CREATE contact 
// Enter name: Joshua Monyei
// Enter email: monyeijoshua@outlook.com
// Enter telephone number: 2348153468883


// 2.DISPLAY contact 
// 	ID 	NAME 		EMAIL 			TELEPHONE 
// 	1804289383 	Joshua Monyei 	monyeijoshua@outlook.com 	2348153468883


// 3.SEARCH contact
// Enter telephone number to search : 2348153468883
// Contact found:
// 	ID 	NAME 			EMAIL 			TELEPHONE 
// 	1804289383 Joshua Monyei 	monyeijoshua@outlook.com	2348153468883


// 4.UPDATE contact 
// Enter phone number to update : 2348153468883
// Enter name: XYZ
// Enter telephone number: 2349014642748
// Details updated: 
// 	ID 		NAME 		EMAIL 			TELEPHONE 
// 	1804289383 	XYZ 	monyeijoshua@outlook.com 	2349014642748


// 5.DELETE contact 
// Enter telephone number to delete : 2349014642748
// Contact deleted successfully
