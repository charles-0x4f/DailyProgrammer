// Written by Charles O.
// charles.0x4f@gmail.com
// Github: https://github.com/charles-0x4f

// Challenge 118-intermediate
// Canon Timing
// See challenge.txt
// Note: This one may be broken?

public class c118i {
	public static void main(String[] args) {
		// total time to simulate firing
		int N;
		// amount of time it takes to load a shell
		int A;
		// amount of time to takes to load the propellent
		int B;
		// amount of time it takes to fire the canon
		int C;

		// Hold the amount of time to increase all others
		final int stepTime = 1;

		// Hold number of times fired
		int timesFired;

		// Variable to hold current timings
		int totalTime, shellTime, propTime, fireTime;

		// Variables to hold whether the shell/propellents are loaded
		boolean shellLoaded, propLoaded;

		N = (int)(99.99 * 100);
		A = (int)(1.23 * 100);
		B = (int)(3.21 * 100);
		C = (int)(5.01 * 100);

		timesFired = 0;

		totalTime = 0;
		shellTime = 0;
		propTime = 0;
		fireTime = 0;

		shellLoaded = false;
		propLoaded = false;

		while(totalTime <= N) {
			// If fireTime is equal to 1.0, then we're done firing
			// and can go back to loading
			if(fireTime >= 100) {
				fireTime = 0;
			}

			// If we're not firing, then we can load
			if(fireTime == 0) {
				if(!shellLoaded) {
					shellTime += stepTime;
				}

				if(!propLoaded) {
					propTime += stepTime;
				}

				if(shellTime == A) {
					shellLoaded = true;
				}
				if(propTime == B) {
					propLoaded = true;
				}
			}

			// If both shell and propellent are loaded, fire
			if((shellLoaded && propLoaded) && fireTime == 0) {
				timesFired++;
				// Mark that the canon is firing
				fireTime = stepTime;
				// Reset load times and booleans on shell/prop
				shellLoaded = false;
				shellTime = 0;
				propLoaded = false;
				propTime = 0;
			}

			// If fireTime is greater than zero, then we're firing;
			// Increase fireTime
			if(fireTime > 0) {
				fireTime += stepTime;
			}

			// Increase the total simulation time
			totalTime += stepTime;

			System.out.println("DBG: " + totalTime + " " + fireTime + " " + shellTime + " " + propTime);
		}

		System.out.println("Times fired: " + timesFired);
	}
}
