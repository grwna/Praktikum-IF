class Main {
    public static void main(String[] args) {
        Student s1 = new Student("1", "s1");
        Student s2 = new Student("2", "s2");
        Course c1 = new Course("1", "c1");
        Course c2 = new Course("2", "c2");

        EnrollmentSystem es = new EnrollmentSystem();
        es.displayCoursesForStudent("1");
        es.displayStudentsInCourse("1");

        es.addStudent("1", "s1");
        es.addStudent("2", "s2");
        es.addCourse("1", "c1");
        es.addCourse("2", "c2");

        es.displayCoursesForStudent("1");
        es.displayStudentsInCourse("1");
        es.enrollStudentInCourse("1", "1");
        es.enrollStudentInCourse("1", "2");
        es.displayCoursesForStudent("1");
        es.displayStudentsInCourse("1");
        es.displayStudentsInCourse("2");
    }
}