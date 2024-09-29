#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class Movie {
private:
    std::string title;
    int yearReleased;
    std::string screenWriter;

public:
    // Setters
    void setTitle(const std::string& t) { title = t; }
    void setYearReleased(int year) { yearReleased = year; }
    void setScreenWriter(const std::string& writer) { screenWriter = writer; }

    // Getters
    std::string getTitle() const { return title; }
    int getYearReleased() const { return yearReleased; }
    std::string getScreenWriter() const { return screenWriter; }

    // Print method
    void print() const {
        std::cout << "Movie: " << title << "\n";
        std::cout << "    Year released: " << yearReleased << "\n";
        std::cout << "    Screenwriter: " << screenWriter << "\n\n";
    }
};

int main() {
    std::vector<Movie> movies; // Container to store Movie objects
    std::ifstream inputFile("input.txt");

    // Check if the file opened successfully
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string title, screenWriter;
    int year;

    // Read data from the input file
    while (std::getline(inputFile, title)) {
        inputFile >> year;
        inputFile.ignore(); // Ignore the newline character after the year
        std::getline(inputFile, screenWriter);

        Movie movie; // Create a temporary Movie object
        movie.setTitle(title);
        movie.setYearReleased(year);
        movie.setScreenWriter(screenWriter);

        movies.push_back(movie); // Append the movie object to the container
    }

    inputFile.close(); // Close the input file

    // Output the contents of the vector
    for (const auto& movie : movies) {
        movie.print();
    }

    return 0;
}
