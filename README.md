# Password Strength Checker

A command-line Password Strength Checker written in C that evaluates the strength of a password using multiple security parameters.

## Features

* Checks password length
* Counts uppercase letters
* Counts lowercase letters
* Counts numeric digits
* Counts special characters
* Detects consecutive character repetitions
* Identifies common weak passwords
* Calculates a security score
* Classifies passwords as:

  * Very Weak
  * Weak
  * Moderate
  * Strong
  * Very Strong

## Technologies Used

* C Programming Language
* Standard C Libraries (`stdio.h`, `string.h`)

## How It Works

The program analyzes the entered password and assigns a score based on:

* Length of the password
* Character diversity
* Number of special characters
* Repetition patterns
* Presence of commonly used passwords

Based on the final score, it provides a strength rating.

## Compilation

Using GCC:

```bash
gcc password_checker.c -o password_checker
```

## Run

```bash
./password_checker
```

## Example

```text
==== LET'S CHECK THE STRENGTH OF YOUR PASSWORD ====

Enter your password : MyPass@123

Score = 34

==== PASSWORD STRENGTH : MODERATE ====
```

## Author

Tanmoy Chatterjee

## License

This project is created for learning and educational purposes.
