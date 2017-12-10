# CS1300 Fall 2017
# Author: Bryce DesBrisay
# Recitation: 210 Arcadia
# Assignment 10


#PART_1 functions here

def read_books(fileName):
    # Reads lines from file and separated them into lists and appends it to a book list
    books = []

    try:
        file = open(fileName, 'r')
        for line in file:
            bookInfo = line.rstrip().split(',')
            books.append([bookInfo[1], bookInfo[0]])

        return books
    except:
        return None


def read_users(user_file):
    # Reads lines from file and creates a dict with the name as a key and ratings as values
    users = {}

    try:
        file = open(user_file, 'r')
        for line in file:
            values = line.rstrip().split(' ')
            ratings = []
            for rating in values[1:]:
                ratings.append(float(rating))
            users[values[0]] = ratings

        return users
    except:
        return None


def calculate_average_rating(ratings_dict):
    # Calculates the average rating for every book and returns a list of them
    avgs = []

    totalList = [0] * 55
    countList = [0] * 55

    for person in ratings_dict:
        total = 0.0
        index = 0

        for rating in ratings_dict[person]:
            totalList[index] += rating
            if float(rating) != 0:
                countList[index] += 1
            index += 1


    for index in range(len(totalList)):
        avgs.append(totalList[index] / countList[index])

    return avgs


def lookup_average_rating(index, book_dict, avg_ratings_dict):
    # Returns string with the average rating, book name, and book author
    return '(' + str(round(avg_ratings_dict[index], 2)) + ')' + ' ' + book_dict[index][0] + ' by ' + book_dict[index][1]

#PART_2 follow here

class Recommender:
    #Constructor here
    def __init__(self, book_filename, ratings_filename):
        self.book_list = []
        self.user_dictionary = {}
        self.average_ratings_list = []
        self.read_books(book_filename)
        self.read_users(ratings_filename)
        self.calculate_average_rating()

    def read_books(self, fileName):
        # Reads lines from file and separated them into lists and appends it to a book list

        try:
            file = open(fileName, 'r')
            for line in file:
                bookInfo = line.rstrip().split(',')
                self.book_list.append([bookInfo[1], bookInfo[0]])

        except:
            return None


    def read_users(self, fileName):
        # Reads lines from file and creates a dict with the name as a key and ratings as values

        try:
            file = open(fileName, 'r')
            for line in file:
                values = line.rstrip().split(' ')
                ratings = []
                for rating in values[1:]:
                    ratings.append(float(rating))
                self.user_dictionary[values[0]] = ratings

        except:
            return None


    def calculate_average_rating(self):
        # Calculates the average rating for every book and returns a list of them

        totalList = [0] * 55
        countList = [0] * 55

        for person in self.user_dictionary:
            total = 0.0
            index = 0

            for rating in self.user_dictionary[person]:
                totalList[index] += rating
                if rating != 0:
                    countList[index] += 1
                index += 1


        for index in range(len(totalList)):
            self.average_ratings_list.append(totalList[index] / countList[index])


    def lookup_average_rating(self, index):
        # Returns string with the average rating, book name, and book author
        return '(' + str('{:.2f}'.format(round(self.average_ratings_list[index], 2))) + ')' + ' ' + self.book_list[index][0] + ' by ' + self.book_list[index][1]


    def calc_similarity(self, user1, user2):
        score = 0.0

        arrayOne = self.user_dictionary[user1]
        arrayTwo = self.user_dictionary[user2]

        for i in range(len(arrayOne)):
            score += arrayOne[i] * arrayTwo[i]

        return int(score)


    def get_most_similar_user(self, current_user_id):
        mostSim = 0.0
        mostSimId = ''

        for person in self.user_dictionary:
            if person != current_user_id:
                sim = self.calc_similarity(current_user_id, person)
                if sim > mostSim:
                    mostSim = sim
                    mostSimId = person

        return mostSimId


    def recommend_books(self, current_user_id):
        simId = self.get_most_similar_user(current_user_id)
        recommendations_list = []

        for i in range(0, len(self.user_dictionary[simId])):
            rating = self.user_dictionary[simId][i]
            if rating >= 3 and self.user_dictionary[current_user_id][i] == 0:
                recommendations_list.append(self.lookup_average_rating(i))

        return recommendations_list


def main():
    #test your functions and classes here

    '''
    books = read_books("book.txt")
    print(books[0])

    users = read_users("ratings.txt")
    print(users["Tony"])

    print(calc_avg_rating(users))

    print(lookup_avg_rating(0, books, calc_avg_rating(users)))
    '''

    rec = Recommender("book.txt", "ratings.txt")
    print(rec.calc_similarity("Cust8", "Shannon"))
    print(rec.calc_similarity("Megan", "Strongbad"))
    print(rec.calc_similarity("Apollo", "James"))
    print(rec.recommend_books("Moose"))



if __name__ == "__main__":
    main()
