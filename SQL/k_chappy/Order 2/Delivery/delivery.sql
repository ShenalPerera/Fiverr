/* ANSWER 1*/
DROP TABLE IF EXISTS people_copy;
DROP TABLE IF EXISTS enrollments_copy;

CREATE TABLE people_copy LIKE people;
CREATE TABLE enrollments_copy LIKE enrollments;

INSERT INTO people_copy
SELECT * 
FROM people;

INSERT INTO enrollments_copy
SELECT * 
FROM enrollments;


INSERT INTO people_copy (lname, fname, pronoun_id, email, college, department, start_date) VALUES 
("Smith", "Ricky", 2, "rsmith@umd.edu", "College of Information Studies","BSIS",NOW());

INSERT INTO enrollments_copy VALUES
(132466128,173),
(132466128,15),
(132466128,32);


/* ANSWER 2 */
UPDATE enrollments_copy
SET section_id = 172
WHERE section_id =173 AND person_id = 132466128;

SELECT concat(fname,' ',lname) as 'student_name',concat(course_code,'',course_number) as course, section_number,concat(semester,' ',year) as semester_year 
FROM ischool.enrollments_copy,course_sections,people_copy,courses
WHERE enrollments_copy.person_id =132466128 AND enrollments_copy.section_id = course_sections.section_id 
AND people_copy.person_id = enrollments_copy.person_id AND
courses.course_id = course_sections.course_id;

SELECT course_sections.section_id,section_number,concat(course_code,'',course_number) as course ,concat(fname,' ',lname) as student_name
FROM ischool.courses,course_sections,people_copy,enrollments_copy
WHERE courses.course_id = course_sections.course_id AND enrollments_copy.person_id = people_copy.person_id 
AND course_sections.section_id=enrollments_copy.section_id
AND course_code="INST" AND course_number = 327 AND year = 2022
ORDER BY section_id;

DELETE FROM enrollments_copy
WHERE enrollments_copy.person_id  IN
(SELECT person_id FROM
	(SELECT people_copy.person_id
	FROM ischool.courses,course_sections,people_copy,enrollments_copy
	WHERE courses.course_id = course_sections.course_id AND enrollments_copy.person_id = people_copy.person_id 
	AND course_sections.section_id=enrollments_copy.section_id
	AND course_code="INST" AND course_number = '327' AND year = 2022
	) as person
);

SELECT course_sections.section_id,section_number,concat(course_code,'',course_number) as course ,concat(fname,' ',lname) as student_name
FROM ischool.courses,course_sections,people_copy,enrollments_copy
WHERE courses.course_id = course_sections.course_id AND enrollments_copy.person_id = people_copy.person_id 
AND course_sections.section_id=enrollments_copy.section_id
AND course_code="INST" AND course_number = 327 AND year = 2022
ORDER BY section_id;