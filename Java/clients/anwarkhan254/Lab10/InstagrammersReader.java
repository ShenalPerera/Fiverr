package labs.lab10;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * 
 * A utility class for reading a CSV-formatted file of top Instagrammers
 *
 */
public class InstagrammersReader {
	
	/**
	 * Reads a CSV-formatted file of top Instagrammers data, and returns a list of 
	 * Instagrammers
	 * 
	 * @param filename	the CSV file with the Instagrammers data to read
	 * @return	a list of Instagrammers from the file
	 */
	public static List<Instagrammer> readFile(String filename) {
		List<Instagrammer> igers = new ArrayList<>();
		try (Scanner in = new Scanner(new File(filename))) {
			while (in.hasNextLine()) {
				String line = in.nextLine();
				/*
				 * The format of each line is name,rank,category,numFollowers,country,engagement,engagementAvg
				 */

				Scanner scanner = new Scanner(line);
				scanner.useDelimiter(",");
				
				String name = scanner.next();
				int rank = scanner.nextInt();
				String category = scanner.next();
				long numFollowers = parseNumber(scanner.next());
				String country = scanner.next();
				long engagement = parseNumber(scanner.next());
				
				scanner.close();
				
				igers.add(new Instagrammer(name, rank, category, numFollowers, country, engagement));
			}
		} catch (FileNotFoundException e) {
			System.out.println("File: " + filename + " not found");
		} 
		return igers;
	}
	
	
	private static long parseNumber(String str) {
		int multiplier = 1;
		if (str.endsWith("K")) {
			multiplier = 1000;
			str = str.substring(0, str.length()-1);
		}
		else if (str.endsWith("M")) {
			multiplier = 1000000;
			str = str.substring(0, str.length()-1);
		}
		return Math.round(Double.parseDouble(str) * multiplier);
	}
}
