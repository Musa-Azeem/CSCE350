#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv){
    int ndoors;     // number of doors
    int r;          // number of passes

    // Get user input
    std::cout << "Enter the number of locker doors:" << std::endl;
    std::cin >> ndoors;

    std::cout << "Enter the number of passes:" << std::endl;
    std::cin >> r;


    // Initialize vector of doors, all set to false for closed
    std::vector<int> doors(ndoors, 0);

    // Loop through doors for each pass
    for(int i=1; i<r+1; i++){
        // Each pass, toggle every ith door
        for(int j=0; j<ndoors; j+=i){
            doors[j] = !doors[j];
        }
    }

    int nopen = 0;      // Count of open doors

    // Print results
    std::string word_map[] = {"Closed", "Open"};
    for(int i=0; i<ndoors; i++){
        std::cout << "Door " << i+1 << ": " << word_map[doors[i]] << std::endl;
        if(doors[i])
            nopen++;
    }
    std::cout << "Number of open locker doors: " << nopen << std::endl;

    return 0;
}