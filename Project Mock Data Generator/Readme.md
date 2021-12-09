### **Fullname:**  

Phạm Huy Cường Thịnh

### **Student's ID:**

 20127335

### **Any notice on how to compile and run my project?**

- Compiler: g++ 8.1.0 version

- Text editor: Visual Studio Code

- Operating system: Windows 11 version 21H2

I also compiled and run my project on Visual Studio Community 2019 version and work successfully so I demonstrated my project on Visual Studio Code for easy viewing.


### **What I have done:**

In the Project 1: Mock data generator, I used the 3 layer architecture to apply for this project.  

<img src="http://techdora.com/wp-content/uploads/2019/04/3LayeredArch.png" width="550" height="300" />

The first layer is data access:

- The data access layer is responsible for reading the data from the database.
  - I used the class **StudentFileIO** to access the data, specifically here is all the students information in the hard-coded file.  

- After reading the data, the data is stored in the **Student** class and stored in vector.

The business layer is responsible for processing the data.

- I created 4 classes to process the data:

  - class **RandomIntegerGenerator** to generate random integer.
  - class **RandomFloatGenerator** to generate random float.
  - class **RandomAddressGenerator** to generate random address.

    - I hard-coded the street names and district names and use the class **RandomIntegerGenerator** to generate street number and ward.
  - class **RandomVietnameseFullnameGenerator** to generate random fullname.

    - I hard-coded the first name, middle name, last name and use the class **RandomIntegerGenerator** to generate the first, middle and last name.

The presentation layer is responsible for displaying the data.

- I represented the data in the main function.

  - First I created a vector of **Student** class,  used the class **StudentFileIO** to write the data to the hard-coded file and store the data that I accessed from the data access layer.

  - Then I called the class **RandomIntegerGenerator**, **RandomFloatGenerator**, **RandomAddressGenerator** and **RandomVietnameseFullnameGenerator** to generate random data, specifically here is all the students information.

  - After that I calculated the average of the GPA and print out all the students that have the GPA greater than the average GPA.

  - Finally, I wrote all the students information that I have generated to the file (appending all information not overwriting).


### **What I have not done:**

None.

### **What should be taken into account for a bonus?**

None.

### **Expected grade:**

10.0

### **Video demo link:**

[Youtube](https://youtu.be/mWDuXfzODu0)

Link if you can not press the above button: [https://youtu.be/mWDuXfzODu0](https://youtu.be/mWDuXfzODu0)

### **Class Diagram:**

![MockStudentDataGeneratorClassDiagram](https://user-images.githubusercontent.com/85171754/145435265-5c4c6ba9-5978-4b10-bce5-be3a7e7d7d81.png)
