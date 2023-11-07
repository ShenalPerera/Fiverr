class Course
        private string courseNumber
        private string courseName
        private Vector<string> prerequisites

        public Course(string _courseNumber,string _courseName, Vector<string> _prerequisites)
            set private attribute courseNumber to _courseNumber
            set private attribute courseName to _courseName
            for all _prerequisite
                add each prerequisite to prerequisites vector

        public getCourseNumber()
            return the value of courseNumber

        public getCourseName()
            return the value of courseName

        public getPrerequisites()
            return prerequisites vector

        public setCourseNumber(string _courseNumber)
            set _courseNumber attribute to _courseNumber

        public setCourseName(string _courseName)
            set attribute courseName to _courseName

        public displayInfo()
            print the courseNumber
            print the courseName
            for all prerequisites
                print each prerequisite
end class




Vector<Course> readFile(string filename)
    Vector<course> courses

    open filename
    if filename is open
        for each line p in the file
            Vector<string> data = parse the line p and split the line by separator
            if length of the data is greater or equal to 2
                get vector<string> temp by slicing data from index 1 to end of data vector
                boolean isIgnore = false
                for each prerequisite in temp and not isIgnore
                    for all courses
                        if not prerequisite is same as courseNumber of current course
                            isIgnore = true
                            break

                if not isIgnore
                    Course temp_course = Course(data[0],data[1],temp)
                    add temp_course to courses

        return courses vector
    else
        throw an exception to indicate that there is an error when openning the file

















