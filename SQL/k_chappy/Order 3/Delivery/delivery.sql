/*Answer 1*/
SELECT concat(lname,',',fname) as "student_name",count(enrollments.section_id) as "enrollments",SUM(credits) as "credit_count",time_format(max(end_time),"%h:%i:%s:%p") as "last_end"
FROM people,enrollments,courses,course_sections
WHERE  enrollments.person_id = people.person_id and courses.course_id = course_sections.course_id and 
course_sections.section_id = enrollments.section_id 
GROUP BY student_name WITH ROLLUP 
having enrollments >2
;


/*Answer 2*/
WITH
  cteReports (ids,course, descriptions, section_count)
  AS
  (
    SELECT courses.course_id,concat(course_code,'',course_number) as 'course' , course_description,count(section_id)
    FROM courses, course_sections
    WHERE courses.course_id = course_sections.course_id
    group by course
  )
  select course, descriptions, section_count , count(enrollments.person_id) as "enrollment_count"
  FROM cteReports,enrollments,course_sections
  WHERE ids = course_sections.course_id and enrollments.section_id = course_sections.section_id
  GROUP BY course
  HAVING enrollment_count >=5
  order by section_count desc, enrollment_count desc;

/* CTE is easier in this scnario. In the statment in th WITH we can think it is as a another table called cteRecords. The second select 
querey doesnot care about the implementation of the cteRecords. It is work with a table. Therefore this is easy to implement. In here we can seperatly
count the values easily