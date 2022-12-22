# SPACE-key-not-working-Backtracking

## PB statement: 

SPACE key on the keyboard not working. He is sending messages to his friends but they do not have spaces like "Iwillmeetyoutomrrow" or "letusplayfootballtonight". His friends have difficulty understanding the message. To help them understand the messages, we need to write a recursive backtracking C++ program that divides the given message string to individual meaningful words. A meaningful word is one that exists in the English dictionary. The program should try to form words starting from the first letter. If it finds the word in the dictionary, it calls itself on the remaining text. The program stops as soon as it can divide the message to a useful sentence with all its words in the dictionary. If no solution is found the program will do exhaustive recursion of all possible solutions and then fail.

For example, if the message is "toforget" 

the output will be: "to forget", "to for get"

