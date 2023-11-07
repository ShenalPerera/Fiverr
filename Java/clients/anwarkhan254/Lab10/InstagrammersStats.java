package labs.lab10;

import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Stream;

/**
 * A class for performing various analyses on a set of Instagrammers data
 *
 */
public class InstagrammersStats {
	
	/**
	 * Given a Stream of Instagrammers and a country, return the top Instagrammer
	 * (by rank) in the given country. If there are no Instagrammers in that country,
	 * return an empty Optional<Instagrammer>
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * @param	country			country to search for
	 * 
	 * @return	top Instagrammer in country, or empty Optional, if none in country
	 */
	public static Optional<Instagrammer> problem1_getTopIGerInCountry(Stream<Instagrammer> instagrammers,
			String country) {
		return null; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers and a category, return a List containing the 
	 * Instagrammer(s) in that category with the most followers. The list should only 
	 * contain multiple Instagrammers if there are multiple Instagrammers who have the 
	 * most followers. The order of the list should follow the order in which those 
	 * Instagrammers appear in the stream.
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * @param	category		category to search for
	 * 
	 * @return	List containing top Instagrammer(s) in category
	 */
	public static List<Instagrammer> problem2_getMostFollowedIGerInCategory(Stream<Instagrammer> instagrammers,
			String category) {
		return null; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers, return a String that contains the names of all countries
	 * represented by the Instagrammers, ordered lexicographically, each name separated by ", ".
	 * Do not include blank country names.
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * 
	 * @return	a String containing the names of all countries represented in the stream, each name
	 * separated by ", "
	 */
	public static String problem3_getAllCountries(Stream<Instagrammer> instagrammers) {
		return ""; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers and a category String, return the number of Instagrammers in
	 * a category that contains the given category String (case-insensitive).
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * @param	category		category search string
	 * 
	 * @return	number of Instagrammers in a category that contains the given category String (case-insensitive)
	 */
	public static long problem4_countIGersInCategory(Stream<Instagrammer> instagrammers, String category) {
		return -1; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instragrammers, return a Map<String, Double> that maps each country to
	 * the average Instagrammer rank in that country
	 * 
	 * This map should be sorted lexicographically by country name.
	 * 
	 * If the stream is empty, return an empty map.
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * 
	 * @return	a mapping of country to average Instagrammer rank in that country
	 */
	public static Map<String, Double> problem5_getAvgRankPerCountry(Stream<Instagrammer> instagrammers) {
		return null; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers, return a list of all categories, ordered from most
	 * frequent to least frequent. If two categories have the same number of Instagrammers,
	 * order them lexicographically by their category names.
	 * 
	 * @param instagrammers		stream of Instagrammers
	 * 
	 * @return	a list of all categories, ordered from most frequent to least frequent
	 */
	public static List<String> problem6_getCategories(Stream<Instagrammer> instagrammers) {
		return null; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers and an integer n, return a list of the top n countries, 
	 * sorted in descending order by number of Instagrammers. If two countries have the same number
	 * of Instagrammers, order them lexicographically by country name. Ignore blank country
	 * names.
	 * 
	 * If there are < n countries represented in the stream, return them all, sorted in the order
	 * previously stated.
	 * 
	 * @param instagrammers		stream of Instagrammers
	 * @param n					number of results desired
	 * 
	 * @return	a list of the top n countries
	 */
	public static List<String> problem7_getTopNCountries(Stream<Instagrammer> instagrammers, int n) {
		return null; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers and two integers (min and max), return a String that 
	 * contains the names of all Instagrammers with an engagement number within that range,
	 * ordered lexicographically, each name separated by a single space
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * @param	min				min engagement
	 * @param	max				max engagement
	 */
	public static String problem8_getAllIGersInEngagementRange(Stream<Instagrammer> instagrammers, 
			int min, int max) {
		return ""; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers and a string, return the first Instagrammer found 
	 * in the stream whose name contains that string (case-sensitive). 
	 * 
	 * If no Instagrammer name contains the string, or the stream is empty, return an 
	 * empty Optional<Instagrammer>
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * @param	str				search string
	 * 
	 * @return	first Instagrammer found whose name contains the string (case-sensitive)
	 */
	public static Optional<Instagrammer> problem9_getFirstIGerContainingString(Stream<Instagrammer> instagrammers, 
			String str) {
		return null; // FIX ME
	}
	
	
	/**
	 * Given a Stream of Instagrammers and a boolean value distinct, return the number
	 * of Instagrammers in the stream, excluding duplicates if distinct is true.
	 * 
	 * A duplicate Instagrammer is one with the same name as another Instagrammer.
	 * 
	 * @param	instagrammers	stream of Instagrammers
	 * @param	distinct		whether or not to exclude duplicates
	 * 
	 * @return	the number of Instagrammers in the stream
	 */
	public static long problem10_countInstagrammers(Stream<Instagrammer> instagrammers, 
			boolean distinct) {
		return -1; // FIX ME
	}
}