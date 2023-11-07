package labs.lab10.tests;

import org.junit.Before;
import static org.junit.Assert.*;

import java.util.List;
import java.util.Map;
import java.util.Optional;

import org.junit.Test;

import labs.lab10.*;


public class Lab10Test {
	
	private final double EPSILON = 1e-3;

	List<Instagrammer> igList1;
	List<Instagrammer> igList2;
	List<Instagrammer> igList3;
	List<Instagrammer> igList4;
	List<Instagrammer> igListBLANK;
	
	//This method will be executed before all the other methods.
	@Before
	public void before() {
		String path = "res/"; //<- Assign the path of the .csv files to this variable. Do not include the file name, 
								// it will be added below.
		igList1 = InstagrammersReader.readFile(path + "top_instagrammers.csv");
		igList2 = InstagrammersReader.readFile(path + "top_instagrammers2.csv");
		igList3 = InstagrammersReader.readFile(path + "top_instagrammers3.csv");
		igList4 = InstagrammersReader.readFile(path + "top_instagrammers4.csv");
		igListBLANK = InstagrammersReader.readFile(path + "top_instagrammersBLANK.csv");
	}
	
	
	@Test
	public void problem1() {
		// igList1:
		Optional<Instagrammer> ig = InstagrammersStats.problem1_getTopIGerInCountry(igList1.stream(), "India");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("cristiano", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList1.stream(), "Argentina");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("leomessi", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList1.stream(), "United States");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("kendalljenner", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList1.stream(), "Mexico");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("karolg", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList1.stream(), "Antarctica");
		assertFalse(ig.isPresent());
		
		
		// igList2:
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList2.stream(), "India");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("beingsalmankhan", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList2.stream(), "Argentina");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("evaluna", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList2.stream(), "United States");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("emrata", ig.get().getName());
		}
		
		ig = InstagrammersStats.problem1_getTopIGerInCountry(igList2.stream(), "Mexico");
		assertTrue(ig.isPresent());
		if (ig.isPresent()) {
			assertEquals("luisitocomunica", ig.get().getName());
		}
	}
	
	
	@Test
	public void problem2() {
		assertTrue(InstagrammersStats.problem2_getMostFollowedIGerInCategory(igList1.stream(), "Java").isEmpty());
		
		List<Instagrammer> result = InstagrammersStats.problem2_getMostFollowedIGerInCategory(igList1.stream(), 
				"Cinema & Actors/actresses");
		assertTrue(result.size() == 1 && result.get(0).getName().equals("kevinhart4real"));
		
		result = InstagrammersStats.problem2_getMostFollowedIGerInCategory(igList1.stream(), 
				"Lifestyle");
		assertTrue(result.size() == 1 && result.get(0).getName().equals("kourtneykardash"));

		result = InstagrammersStats.problem2_getMostFollowedIGerInCategory(igList3.stream(), 
				"Music");
		assertTrue(result.size() == 2 &&
				result.get(0).getName().equals("britneyspears") &&
				result.get(1).getName().equals("maluma"));
		
		result = InstagrammersStats.problem2_getMostFollowedIGerInCategory(igList3.stream(), 
				"Family");
		assertTrue(result.size() == 2 &&
				result.get(0).getName().equals("kto_takaya") &&
				result.get(1).getName().equals("kto_takaya2"));
		
		result = InstagrammersStats.problem2_getMostFollowedIGerInCategory(igList3.stream(), 
				"LifestyleModelingCinema & Actors/actresses");
		assertTrue(result.size() == 2 &&
				result.get(0).getName().equals("nidhhiagerwal2") &&
				result.get(1).getName().equals("nidhhiagerwal"));
	}
	
	
	@Test
	public void problem3() {
		assertEquals("Albania, Algeria, Argentina, Brazil, Chile, China, Colombia, Egypt, France, Germany, India, Indonesia, Iran, Iraq, Italy, Japan, Kazakhstan, Mexico, Morocco, Nigeria, Pakistan, Philippines, Poland, Russia, Senegal, South Korea, Spain, Syria, Thailand, Turkey, United Arab Emirates, United Kingdom, United States",
				InstagrammersStats.problem3_getAllCountries(igList1.stream()));
		assertEquals("Argentina, Brazil, Chile, Colombia, Egypt, France, India, Indonesia, Iran, Italy, Japan, Kazakhstan, Mexico, Morocco, Philippines, Russia, Senegal, South Korea, Spain, Thailand, Turkey, United Arab Emirates, United Kingdom, United States",
				InstagrammersStats.problem3_getAllCountries(igList2.stream()));
		assertEquals("Brazil, India, Indonesia, Iran, Italy, Kazakhstan, Mexico, Russia, Spain, United States",
				InstagrammersStats.problem3_getAllCountries(igList3.stream()));
		assertEquals("Brazil, India, Kazakhstan, United States",
				InstagrammersStats.problem3_getAllCountries(igList4.stream()));
		assertEquals("", InstagrammersStats.problem3_getAllCountries(igListBLANK.stream()));
	}
	
	
	@Test
	public void problem4() {
		assertEquals(0, InstagrammersStats.problem4_countIGersInCategory(igListBLANK.stream(), "Lifestyle"));
		assertEquals(2, InstagrammersStats.problem4_countIGersInCategory(igList4.stream(), "Lifestyle"));
		assertEquals(2, InstagrammersStats.problem4_countIGersInCategory(igList4.stream(), "lifestyle"));
		assertEquals(2, InstagrammersStats.problem4_countIGersInCategory(igList4.stream(), "LIFEStYLE")); 
		assertEquals(1, InstagrammersStats.problem4_countIGersInCategory(igList4.stream(), "fitness"));
		assertEquals(3, InstagrammersStats.problem4_countIGersInCategory(igList4.stream(), "&"));
		assertEquals(10, InstagrammersStats.problem4_countIGersInCategory(igList3.stream(), " ")); 
		assertEquals(10, InstagrammersStats.problem4_countIGersInCategory(igList3.stream(), "Music")); 
		assertEquals(5, InstagrammersStats.problem4_countIGersInCategory(igList3.stream(), "Cinema & Actors/actresses"));
	}
	
	
	@Test
	public void problem5() {
		Map<String, Double> result = InstagrammersStats.problem5_getAvgRankPerCountry(igList2.stream());
		assertTrue(result.size() == 25);
		assertEquals(753.25, result.get(""), EPSILON);
		assertEquals(629.6, result.get("Argentina"), EPSILON);
		assertEquals(618.388, result.get("Brazil"), EPSILON);
		assertEquals(836.0, result.get("Chile"), EPSILON);
		assertEquals(567.0625, result.get("India"), EPSILON);
		assertEquals(635.888, result.get("Indonesia"), EPSILON);
		assertEquals(797.0, result.get("Morocco"), EPSILON);
		assertEquals(810.429, result.get("Russia"), EPSILON);
		assertEquals(761.5, result.get("South Korea"), EPSILON);
		assertEquals(786.0, result.get("United Arab Emirates"), EPSILON);
		assertEquals(618.857, result.get("United States"), EPSILON);
		
		result = InstagrammersStats.problem5_getAvgRankPerCountry(igList3.stream());
		assertTrue(result.size() == 11);
		assertEquals(844.0, result.get(""), EPSILON);
		assertEquals(737.5, result.get("Brazil"), EPSILON);
		assertEquals(856.5, result.get("India"), EPSILON);
		assertEquals(852.6, result.get("Indonesia"), EPSILON);
		assertEquals(855.667, result.get("Russia"), EPSILON);
		assertEquals(499.167, result.get("United States"), EPSILON);
		
		result = InstagrammersStats.problem5_getAvgRankPerCountry(igList4.stream());
		assertTrue(result.size() == 4);
		assertEquals(870.0, result.get("Brazil"), EPSILON);
		assertEquals(866.0, result.get("India"), EPSILON);
		assertEquals(858.0, result.get("Kazakhstan"), EPSILON);
		assertEquals(865.0, result.get("United States"), EPSILON);
		
		assertEquals(0, InstagrammersStats.problem5_getAvgRankPerCountry(igListBLANK.stream()).size());
	}
	
	
	@Test
	public void problem6() {
		List<String> result = InstagrammersStats.problem6_getCategories(igList4.stream());
		assertEquals(4, result.size());
		assertEquals("Cinema & Actors/actresses", result.get(0));
		assertEquals("Cinema & Actors/actressesLifestyle", result.get(1));
		assertEquals("Fitness & Gym", result.get(2));
		assertEquals("Lifestyle", result.get(3));
		
		result = InstagrammersStats.problem6_getCategories(igList3.stream());
		assertEquals(15, result.size());
		assertEquals("Music", result.get(0));
		assertEquals("", result.get(1));
		assertEquals("Sports with a ball", result.get(2));
		assertEquals("Family", result.get(3));
		assertEquals("Lifestyle", result.get(4));
		assertEquals("LifestyleModelingCinema & Actors/actresses", result.get(5));
		assertEquals("LifestyleMusic", result.get(6));
		assertEquals("Shows", result.get(7));
		assertEquals("Cinema & Actors/actresses", result.get(8));
		assertEquals("Cinema & Actors/actressesLifestyle", result.get(9));
		assertEquals("Fitness & Gym", result.get(10));
		assertEquals("LifestyleCinema & Actors/actresses", result.get(11));
		assertEquals("LifestyleModeling", result.get(12));
		assertEquals("LifestyleSports with a ball", result.get(13));
		assertEquals("Modeling", result.get(14));
		
		assertEquals(0, InstagrammersStats.problem6_getCategories(igListBLANK.stream()).size());
	}
	
	
	@Test
	public void problem7() {
		List<String> result = InstagrammersStats.problem7_getTopNCountries(igList1.stream(), 1);
		assertEquals(1, result.size());
		assertEquals("United States", result.get(0));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList1.stream(), 2);
		assertEquals(2, result.size());
		assertEquals("United States", result.get(0));
		assertEquals("India", result.get(1));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList1.stream(), 3);
		assertEquals(3, result.size());
		assertEquals("United States", result.get(0));
		assertEquals("India", result.get(1));
		assertEquals("Brazil", result.get(2));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList2.stream(), 1);
		assertEquals(1, result.size());
		assertEquals("United States", result.get(0));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList2.stream(), 2);
		assertEquals(2, result.size());
		assertEquals("United States", result.get(0));
		assertEquals("Brazil", result.get(1));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList2.stream(), 3);
		assertEquals(3, result.size());
		assertEquals("United States", result.get(0));
		assertEquals("Brazil", result.get(1));
		assertEquals("India", result.get(2));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList3.stream(), 1);
		assertEquals(1, result.size());
		assertEquals("Brazil", result.get(0));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList3.stream(), 2);
		assertEquals(2, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList3.stream(), 9);
		assertEquals(9, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		assertEquals("United States", result.get(2));
		assertEquals("Indonesia", result.get(3));
		assertEquals("Russia", result.get(4));
		assertEquals("Iran", result.get(5));
		assertEquals("Italy", result.get(6));
		assertEquals("Kazakhstan", result.get(7));
		assertEquals("Mexico", result.get(8));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList3.stream(), 10);
		assertEquals(10, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		assertEquals("United States", result.get(2));
		assertEquals("Indonesia", result.get(3));
		assertEquals("Russia", result.get(4));
		assertEquals("Iran", result.get(5));
		assertEquals("Italy", result.get(6));
		assertEquals("Kazakhstan", result.get(7));
		assertEquals("Mexico", result.get(8));
		assertEquals("Spain", result.get(9));

		result = InstagrammersStats.problem7_getTopNCountries(igList4.stream(), 1);
		assertEquals(1, result.size());
		assertEquals("Brazil", result.get(0));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList4.stream(), 2);
		assertEquals(2, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList4.stream(), 3);
		assertEquals(3, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		assertEquals("Kazakhstan", result.get(2));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList4.stream(), 4);
		assertEquals(4, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		assertEquals("Kazakhstan", result.get(2));
		assertEquals("United States", result.get(3));
		
		result = InstagrammersStats.problem7_getTopNCountries(igList4.stream(), 5);
		assertEquals(4, result.size());
		assertEquals("Brazil", result.get(0));
		assertEquals("India", result.get(1));
		assertEquals("Kazakhstan", result.get(2));
		assertEquals("United States", result.get(3));
		
		assertEquals(0, InstagrammersStats.problem7_getTopNCountries(igListBLANK.stream(), 4).size());
	}
	
	
	@Test
	public void problem8() {
		assertEquals("", InstagrammersStats.problem8_getAllIGersInEngagementRange(igListBLANK.stream(), 0, 10000000));
		assertEquals("kikakim massafera miketyson sonu_sood", 
				InstagrammersStats.problem8_getAllIGersInEngagementRange(igList4.stream(), 67000, 280000));
		assertEquals("kikakim massafera miketyson sonu_sood", 
				InstagrammersStats.problem8_getAllIGersInEngagementRange(igList4.stream(), 0, 280000));
		assertEquals("miketyson sonu_sood", 
				InstagrammersStats.problem8_getAllIGersInEngagementRange(igList4.stream(), 100000, 200000));
		assertEquals("", 
				InstagrammersStats.problem8_getAllIGersInEngagementRange(igList4.stream(), 67000000, 280000000));
		assertEquals("lanarhoades", 
				InstagrammersStats.problem8_getAllIGersInEngagementRange(igList3.stream(), 1000000, 2000000));
		assertEquals("chelseafc josephquinn luara ludmilla ludmilla massafera nidhhiagerwal nidhhiagerwal2", 
				InstagrammersStats.problem8_getAllIGersInEngagementRange(igList3.stream(), 0, 100000));
	}
	
	
	@Test
	public void problem9() {
		Optional<Instagrammer> result = 
				InstagrammersStats.problem9_getFirstIGerContainingString(igList2.stream(), "official");
		assertTrue(result.isPresent());
		if (result.isPresent()) {
			assertEquals("anirudhofficial", result.get().getName());
		}
		
		result = 
				InstagrammersStats.problem9_getFirstIGerContainingString(igList2.stream(), "mad");
		assertTrue(result.isPresent());
		if (result.isPresent()) {
			assertEquals("madisonbeer", result.get().getName());
		}

		result = 
				InstagrammersStats.problem9_getFirstIGerContainingString(igList2.stream(), "robert_thepuppy");
		assertTrue(result.isEmpty());
		
		result = 
				InstagrammersStats.problem9_getFirstIGerContainingString(igList2.stream(), "maddieziegler");
		assertTrue(result.isPresent());
		if (result.isPresent()) {
			assertEquals("maddieziegler", result.get().getName());
		}
		
		result = 
				InstagrammersStats.problem9_getFirstIGerContainingString(igList2.stream(), "Maddieziegler");
		assertTrue(result.isEmpty());
		
		result = 
				InstagrammersStats.problem9_getFirstIGerContainingString(igListBLANK.stream(), "a");
		assertTrue(result.isEmpty());
	}
	
	
	@Test
	public void problem10() {
		assertEquals(962, InstagrammersStats.problem10_countInstagrammers(igList1.stream(), true));
		assertEquals(1000, InstagrammersStats.problem10_countInstagrammers(igList1.stream(), false));
		assertEquals(235, InstagrammersStats.problem10_countInstagrammers(igList2.stream(), true)); 
		assertEquals(245, InstagrammersStats.problem10_countInstagrammers(igList2.stream(), false));
		assertEquals(30, InstagrammersStats.problem10_countInstagrammers(igList3.stream(), true));
		assertEquals(32, InstagrammersStats.problem10_countInstagrammers(igList3.stream(), false));
		assertEquals(4, InstagrammersStats.problem10_countInstagrammers(igList4.stream(), true));
		assertEquals(4, InstagrammersStats.problem10_countInstagrammers(igList4.stream(), false));
		assertEquals(0, InstagrammersStats.problem10_countInstagrammers(igListBLANK.stream(), true)); 
		assertEquals(0, InstagrammersStats.problem10_countInstagrammers(igListBLANK.stream(), false));
	}
}

