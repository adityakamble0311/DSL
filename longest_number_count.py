def display_word_with_longest_length():
    string_input = input("Enter the main string: ")
    words = string_input.split()
    longest_word = max(words, key=len, default="")

    print("Word with the longest length is {} having length {}\n\n".format(longest_word, len(longest_word)))

display_word_with_longest_length()
