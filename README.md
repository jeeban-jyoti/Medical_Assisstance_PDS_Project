# Medical Assistance PDS Project

## Introduction
This is a Medical Assistance Project designed to assist users in finding nearby hospitals and accessing their contact details and addresses in case of emergencies. The project is primarily aimed at students and other citizens who may be unfamiliar with the area or unaware of local medical facilities.

## Contributors
- [**Jeeban Jyoti Patra** (23CS01026)](https://github.com/jeeban-jyoti)
- [**Shatadeep De** (23CE01052)](https://github.com/jeeban-jyoti)
- [**Adityaa Saha** (23CS01002)](https://github.com/jeeban-jyoti)
- [**Nilabja Mondal** (23MM02008)](https://github.com/jeeban-jyoti)

## Features
- **Search for Hospitals:** Users can search for hospitals by entering the name of a place. The program then utilizes a Python script to find the latitude and longitude coordinates of the location and uses them to locate nearby hospitals.
- **Recent Searches History:** Users can view their recent searches along with the hospital data obtained during those searches.

## Deployment

To compile the C program get inside the project folder and type

```bash
  gcc INTERFACE.c -o INTERFACE -lcurl
```
To run the project type
```bash
  ./INTERFACE
```

## How to Use
1. Run the program.
2. Choose from the following options:
   - Enter '1' to search for hospitals.
   - Enter '2' to view recent search history.
   - Enter '0' to exit the program.
3. If you choose to search for hospitals:
   - Enter the name of the place when prompted.
   - The program will display the nearest hospitals along with their contact details and addresses.
4. If you choose to view recent search history:
   - Select the number corresponding to the search you wish to view.
   - The program will display the hospital data obtained during that search.
5. Repeat steps 2-4 as needed.
6. Enter '0' to exit the program.

## Screenshots

<img width="793" alt="Screenshot 2024-04-04 at 11 44 29 PM" src="https://github.com/jeeban-jyoti/Medical_Assisstance_PDS_Project/assets/72793803/c8d40585-81ba-49c0-b856-338b7a0680a5">
<img width="658" alt="Screenshot 2024-04-04 at 11 39 20 PM" src="https://github.com/jeeban-jyoti/Medical_Assisstance_PDS_Project/assets/72793803/7a8ff186-c67c-4d6a-8ad7-6e917cf84b90">
<img width="659" alt="Screenshot 2024-04-04 at 11 41 51 PM" src="https://github.com/jeeban-jyoti/Medical_Assisstance_PDS_Project/assets/72793803/3f7207d9-6b06-4712-8270-d4ee8780b0e8">
<img width="658" alt="Screenshot 2024-04-04 at 11 43 00 PM" src="https://github.com/jeeban-jyoti/Medical_Assisstance_PDS_Project/assets/72793803/ab569dc7-3c4e-4e51-baf7-01cc90a6b14a">


## Files
- **FileOperations.c:** Contains functions for file operations such as reading from and writing to files.
- **location_finder.py:** Python script for finding the latitude and longitude coordinates of a location based on its name.
- **hospital_data_fetcher.c:** Contains function for fetching data of hospital from api and printing it to the console.
- **INTERFACE.c**: Contains the main program logic and user interface implementation.

## Note
- Ensure that all necessary files, including "FileOperations.c", "location_finder.py", "hospital_data_fetcher.c" and "INTERFACE.c" are present in the same directory as the main program file.
- The program relies on the correct functioning of the Python script "location_finder.py" to obtain latitude and longitude coordinates. Ensure that the script is correctly implemented and accessible.

This project was developed as part of a Programming and Data Structures course and is intended for educational purposes only.
