// Write a program that uses a structure to hold information about movies, such as title, genre, director, release year, and rating. Write a program that allows users to add new movies, search for movies by genre, and display all movie details.
#include <stdio.h>
#include <string.h>
typedef struct {
    char title[50], genre[20], director[30];
    int releaseYear;
    float rating;
} Movie;
void addMovie(Movie *movies, int *count, char *title, char *genre, char *director, int year, float rating) {
    strcpy(movies[*count].title, title);
    strcpy(movies[*count].genre, genre);
    strcpy(movies[*count].director, director);
    movies[*count].releaseYear = year;
    movies[*count].rating = rating;
    (*count)++;
}
void displayMovies(Movie movies[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%d) - Genre: %s, Director: %s, Rating: %.1f\n", movies[i].title, movies[i].releaseYear, movies[i].genre, movies[i].director, movies[i].rating);
    }
}
void searchByGenre(Movie movies[], int count, char *genre) {
    printf("Movies in Genre: %s\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("%s (%d) - Director: %s, Rating: %.1f\n", movies[i].title, movies[i].releaseYear, movies[i].director, movies[i].rating);
        }
    }
}
int main() {
    Movie movies[10];
    int count = 0;
    addMovie(movies, &count, "Inception", "Sci-Fi", "Christopher Nolan", 2010, 8.8);
    addMovie(movies, &count, "Titanic", "Romance", "James Cameron", 1997, 7.8);
    displayMovies(movies, count);
    searchByGenre(movies, count, "Sci-Fi");
    return 0;
}
