# Simple Voting System

A command-line voting system application written in C that allows users to conduct a simple election with multiple candidates.

## Features

- Add up to 10 candidates
- Collect votes from multiple voters
- Display detailed voting results with percentages
- Automatically determine and announce the winner
- Input validation to prevent common errors

## How to Compile

To compile the program, use the following command:

```
gcc -o voting_system voting_system.c
```

## How to Run

After compiling, run the program:

```
./voting_system
```

## Usage Instructions

1. **Enter the number of candidates** (between 1 and 10)
2. **Enter each candidate's name** when prompted
3. **Enter the number of voters** who will participate
4. For each voter:
   - The list of candidates will be displayed
   - Enter the number corresponding to your chosen candidate
5. **View results** showing each candidate's vote count and percentage
6. The winner will be announced automatically

## Sample Output

```
Prathider songkha likhun (Minimum 1, Max 10) : 3
Prathi 1 er naam likhun (Rizz Up!): Sheikh Hasina
Prathi 2 er naam likhun (Rizz Up!): Khaleda Jia
Prathi 3 er naam likhun (Rizz Up!): Dr.Eusuf 

Voter songkha likhun (Min 1) : 5

Prathider Talika (Vote Wisely):
1. Sheikh Hasina
2. Khaleda Jia
3. Dr. Eusuf
Voter 1, apnar poshondo likhun (1-3) : 1
Vote Casted , Skibidi Yes Yes Yes!

[... voting continues for each voter ...]

----- FOLAFOL -----
Sheikh Hasina: 2 vote (40.0%) 
Khaleda Jia: 2 vote (40.0%) 
Dr. Eusuf: 1 vote (20.0%) 

Bijoyi: Sheikh Hasina (2 vote, 40.0%)!!
Once again Sheikh Hasina
```

## Notes

- This program uses simple input methods and is designed for educational purposes
- The program includes input validation to prevent common errors
- The interface includes both Bengali/English (Banglish) text

## Requirements

- C compiler (gcc recommended)
- No external libraries required 
