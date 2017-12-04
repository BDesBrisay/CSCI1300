# Bryce DesBrisay
# Recitation 210 - Arcadia
# Assignment 9

def sort_array(array):
    # Bubble sort an array by running through each item and comparing it to the next
    # and swapping them if the first is bigger than the next

    for index1 in range(len(array)):
        for index2 in range(len(array)-1):
            if array[index2] > array[index2+1]:
                temp = array[index2]
                array[index2] = array[index2+1]
                array[index2+1] = temp

def compute_census(rates, current_population):
    # Returns the predicted population in a year with the provided population rates

    seconds = 60 * 60 * 24 * 365;
    current_population += seconds / rates[0];
    current_population -= seconds / rates[1];
    current_population += seconds / rates[2];

    return current_population

def convert_seconds():
    # Converts a seconds value into days, hours, minutes, and seconds and prints it

    initSeconds = int(raw_input())
    seconds = initSeconds

    if seconds < 0:
        seconds = 0

    dayCount = seconds / (60 * 60 * 24)
    seconds = seconds % (60 * 60 *24)
    hourCount = seconds / (60 * 60)
    seconds = seconds % (60 * 60)
    minuteCount = seconds / 60
    seconds = seconds % 60

    print(str(initSeconds)+" corresponds to: "+str(dayCount)+" days, "+str(hourCount)+" hours, "+str(minuteCount)+" minutes, "+str(seconds)+" seconds.")

def generate_story(list_to_story):
    # Takes in inputs for certain blanks in the story. Fills in and returns story
    # with the provider variables in place

    story = ""
    index = 0

    for item in list_to_story:
        if index % 2:
            story += raw_input(list_to_story[index])
        else:
            story += list_to_story[index] + ' '
        index += 1

    return story

def similarity_score(seq1, seq2):
    # Runs through each item in the sequences and counts how many times they dont matches
    # returns a standardized percent for the similarity score of two sequences

    seq1Len = len(seq1)
    seq2Len = len(seq2)
    mismatches = 0.0;

    if seq1Len != seq2Len:
        return 0

    i = 0
    while i < seq1Len:
        if seq1[i] != seq2[i]:
          mismatches += 1
        i += 1

    return (seq1Len - mismatches) / seq1Len

def best_match(genome, seq):
    # Calculates which substring of the genome best matches the given sequence
    # and returns the index of where the best match is. It checks for best matches
    # by running through each substring of the genome and comparing it's similarity
    # score to the current highest one.

    bestMatch = 0.0;
    pos = 0;
    index = 0;

    while pos < len(genome):
        simScore = similarity_score(genome[pos:pos+len(seq)], seq)

        if simScore > bestMatch:
            bestMatch = simScore
            index = pos
        pos += 1

    return index;

def calc_stats(list_of_nums):
    # Takes in list of numbers and calculates the average and median by running
    # through each item and adding it to a total value and dividing by size

    total = 0.0
    length = len(list_of_nums)
    avg = 0.0
    median = 0.0
    tempArray = []

    for item in list_of_nums:
        total += float(item)
        tempArray.append(float(item))

    sort_array(tempArray)
    avg = total / length

    if length % 2:
        median = tempArray[(length / 2)]
    else:
        median = (tempArray[length / 2] + tempArray[(length / 2) - 1]) / 2.0

    stats = [avg, median]

    return stats

def parse_ratings(file_name):
    # Reads lines from file and converts it to a nested list format with .split

    file = open(file_name)
    entries = []

    for line in file:
        item = line.rstrip().split(', ')
        name = item[0]
        ratings = item[1].rstrip().split(' ')

        for index in range(len(ratings)):
            ratings[index] = int(ratings[index])

        entry = [name, ratings]
        entries.append(entry)

    return entries

def main():
    rates = [8,12,33]
    pop = 1000000
    print("Complete Census: " + str(compute_census(rates, pop)))

    convert_seconds()

    str1 = 'I went skiing to'
    prompt1 = 'Enter a location: '
    str2 = 'it was really crowded and I statyed in line for'
    prompt2 = 'Enter number of hours: '
    str3 = 'hours.'
    list_to_story = [str1, prompt1, str2, prompt2, str3]
    print(generate_story(list_to_story))

    seq1 = 'CCGCCGCCGA'
    seq2 = 'CCTCCTCCTA'
    print(similarity_score(seq1, seq2))

    genome = 'GGCACGCATAATTGGAACCTT'
    sequence = 'GCAT'
    print(best_match(genome, sequence))

    sample_list_of_nums = [1, 5, 6, 3, 2, 5]
    print(calc_stats(sample_list_of_nums))

    fileName = 'sampleRatings.txt'
    print(parse_ratings(fileName))

if __name__ == '__main__':
    main()
