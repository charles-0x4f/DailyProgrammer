// Written by Charles O.
// charles.0x4f@gmail.com
// Github: https://github.com/charles-0x4f

// r/DailyProgrammer: Challenge 115 (easy)
// Guess the number game
// Java entry
// See challenge.txt

import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException;

public class c115
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		Random rand = new Random();

		int number = rand.nextInt(100) + 1;
		int guess = -1;

		System.out.print("I have selected a number from 1 to 100...");
		System.out.print("\nCan you guess it?\n");

		do {
			System.out.print("\nWhat's your guess? ");

			try {
				guess = scan.nextInt();
			} catch(InputMismatchException ex) {
				// Clear buffer to avoid loop
				scan.nextLine();
				System.out.print("\nWHOLE NUMBERS ONLY!\n");
				continue;
			}

			if(guess != number)
				System.out.print("\nIncorrect, number is ");

			if(guess < number)
				System.out.println("higher");
			else if(guess > number)
				System.out.println("lower");
			
		} while(guess != number);

		System.out.println("You guessed it! You win $1,000,000!");
	}
}
