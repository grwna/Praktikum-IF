import java.util.HashMap;

public class EnrollmentSystem {
    private HashMap<String, Student> students; // <studentID, Student>
    private HashMap<String, Course> courses; // <courseID, Course>

    // Ctor untuk membuat objek EnrollmentSystem
    // Inisialisasi students dan courses
    public EnrollmentSystem() {
        students = new HashMap<String, Student>();
        courses = new HashMap<String, Course>();
    }

    // Method untuk menambahkan student ke dalam sistem
    public void addStudent(String studentID, String name) {
        Student student = new Student(studentID, name);
        students.put(studentID, student);
    }

    // Method untuk menambahkan course ke dalam sistem
    public void addCourse(String courseID, String courseName) {
        Course course = new Course(courseID, courseName);
        courses.put(courseID, course);
    }

    // Method untuk mendaftar student ke dalam course
    // Jika student atau course tidak ditemukan, tampilkan pesan error
    // "Student atau course tidak ditemukan!" (tanpa tanda kutip)
    public void enrollStudentInCourse(String studentID, String courseID) {
        Student student = this.students.get(studentID);
        Course course = this.courses.get(courseID);
        if (student == null || course == null) {
            System.out.println("Student atau course tidak ditemukan!");
        }
        else {
            course.addStudent(studentID);
            courses.replace(courseID, course);
            student.enrollCourse(courseID);
            students.replace(studentID, student);
        }
    }

    // Method untuk menampilkan daftar course yang diambil oleh student
    // 
    // Student <studentName> terdaftar di <jumlah course> course:
    // <courseID1> <courseName1>
    // <courseID2> <courseName2>
    // ...
    //
    // Jika student tidak ditemukan, tampilkan pesan error
    // "Student tidak ditemukan!" (tanpa tanda kutip)
    public void displayCoursesForStudent(String studentID) { 
        Student student = this.students.get(studentID);
        
        if (student == null) {
            System.out.println("Student tidak ditemukan!");
            return;
        }

        System.out.println("Student " + student.getName() + " terdaftar di " + student.getEnrolledCourses().size() + " course:" );
        for (String course : student.getEnrolledCourses()) {
            System.out.println(course + " " + courses.get(course).getCourseName());
        }
    }

    // Method untuk menampilkan daftar student yang terdaftar di course
    // 
    // Course <courseName> memiliki <jumlah student> student:
    // <studentID1> <studentName1>
    // <studentID2> <studentName2>
    // ...
    //
    // Jika course tidak ditemukan, tampilkan pesan error
    // "Course tidak ditemukan!" (tanpa tanda kutip)
    public void displayStudentsInCourse(String courseID) {
        Course course = this.courses.get(courseID);

        if (course == null) {
            System.out.println("Course tidak ditemukan!");
            return;
        }

        System.out.println("Course " + course.getCourseName() + " memiliki " + course.getEnrolledStudents().size() + " student:" );
        for (String student : course.getEnrolledStudents()) {
            System.out.println(student + " " + students.get(student).getName());
        }
    }
}
