# Medical Assistance Project README

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

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)
![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)
![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


## Files
- **FileOperations.c:** Contains functions for file operations such as reading from and writing to files.
- **location_finder.py:** Python script for finding the latitude and longitude coordinates of a location based on its name.
- **hospital_data_fetcher.c:** Contains function for fetching data of hospital from api and printing it to the console.

## Note
- Ensure that all necessary files, including "FileOperations.c", "hospital_data_fetcher.c" and "location_finder.py," are present in the same directory as the main program file.
- The program relies on the correct functioning of the Python script "location_finder.py" to obtain latitude and longitude coordinates. Ensure that the script is correctly implemented and accessible.

This project was developed as part of a Programming and Data Structures course and is intended for educational purposes only.
