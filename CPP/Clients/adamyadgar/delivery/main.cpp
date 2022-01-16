#include<iostream>
#include<string>
#include<fstream>

using namespace std;

// function to read the given file and return the stream
ifstream readFile(string fileName){
    cout << "Enter File Name" << endl;
    cin >> fileName;
    ifstream fin(fileName);
    return fin;
}

int main() {
	int sizeX = 0;                      // Horizontal size of the rectangular field
    int sizeY = 0;                      // Vertical size of the rectangular field
	int currentYear = 0;                // Hold the current year value
    int plantingCount;                  // Hold the planting count in the current year

    // To hold the coordinates
    int startXCoord;
    int endXCoord;
    int startYCoord;
    int endYCoord;

    string fileName;                  // variable to hold the file name

    // get the filestream returns from the function
	ifstream fileInput = readFile(fileName);

    // read horizontal size and vertical sizes of the rectangle filed
	fileInput >> sizeX;
	fileInput >> sizeY;

    // create the field and isPlanted array to check whether given box is planted
    int field[sizeY][sizeX] ;
    bool isPlanted[sizeY][sizeX];

    // Initialize the field and the isPlanted
    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            field[i][j] = 0;
            isPlanted[i][j] = false;
        }
    }

    // Loop until it meets the 2017 year
    while (true){
        fileInput >> currentYear;           // read the current year
        fileInput >> plantingCount;         // read the planting count

        // Reset the is planted position to false in every new year starts
        for (int i = 0; i < sizeY; ++i) {
            for (int j = 0; j < sizeX; ++j) {
                isPlanted[i][j] = false;
            }
        }


        for (int i = 0; i < plantingCount; i++) {
            fileInput >> startXCoord >> startYCoord >> endXCoord >> endYCoord;
            for (int row = startYCoord; row <= endYCoord; row++) {
                for (int col = startXCoord; col <= endXCoord; col++) {
					field[row][col] = field[row][col] + 1;
                    isPlanted[row][col] = true;
				}
			}

		}

        for (int i = 0; i < sizeY; ++i) {
            for (int j = 0; j < sizeX; ++j) {
                if (!isPlanted[i][j] && field[i][j] > 0){
                    field[i][j] = field[i][j] -1;
                }

            }
        }
        if (currentYear == 2017) break;
    }

	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
	fileInput.close();

	return 0;
}