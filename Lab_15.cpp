#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

    // Print method
    void print() const {
        std::cout << "Movie: " << title << "\n";
        std::cout << "    Year released: " << yearReleased << "\n";
        std::cout << "    Screenwriter: " << screenWriter << "\n";
    }
};

int main() {
    std::ifstream inputFile("input.txt");
    std::vector<Movie> movies;
    std::string title;
    int year;
    std::string writer;

    while (std::getline(inputFile, title) && inputFile >> year && std::getline(inputFile >> std::ws, writer)) {
        Movie tempMovie;
        tempMovie.setTitle(title);
        tempMovie.setYearReleased(year);
        tempMovie.setScreenWriter(writer);
        movies.push_back(tempMovie);

        // To consume the newline after reading the writer
        inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Output the contents
    for (const auto& movie : movies) {
        movie.print();
    }

    return 0;
}
