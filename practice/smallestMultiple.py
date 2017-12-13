# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 10?

def main():
    for i in range(1, 1000000):
        one = i % 1 == 0
        two = i % 2 == 0
        three = i % 3 == 0
        four = i % 4 == 0
        five = i % 5 == 0
        six = i % 6 == 0
        seven = i % 7 == 0
        eight = i % 8 == 0
        nine = i % 9 == 0
        ten = i % 10 == 0

        if one and two and three and four and five and six and seven and eight and nine and ten:
            print i
            break

main()
