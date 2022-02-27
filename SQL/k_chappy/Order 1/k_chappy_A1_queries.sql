/*Answer 1*/ 
SELECT  concat(course_code,' ',course_number) as 'course_name',section_number,concat(fname,' ',lname) as 'instructor' ,course_description ,course_prereq,credits from courses,course_sections,people
WHERE course_number < 300 AND courses.course_id = course_sections.course_id AND people.person_id = instructor_id AND course_prereq IS NOT NULL
UNION
SELECT  concat(course_code,' ',course_number) as 'course_name',section_number,concat(fname,' ',lname) as 'instructor' ,course_description ,'No Prereqs' as course_prereq,credits from courses,course_sections,people
WHERE course_number < 300 AND courses.course_id = course_sections.course_id AND people.person_id = instructor_id AND course_prereq IS NULL
ORDER BY course_name;


/*Answer 2*/ 
SELECT concat(course_code,'',course_number) as 'course',concat(semester,' - ',course_sections.year) as 'semester' ,section_number,concat(people.fname,' ' ,people.lname) as 'enrolled_student' , meeting_days
from courses, enrollments
RIGHT JOIN course_sections
ON course_sections.section_id = enrollments.section_id
LEFT JOIN people
on people.person_id = enrollments.person_id
WHERE courses.course_id = course_sections.course_id AND concat(course_code,'',course_number) = 'INST327' 
ORDER BY section_number
;