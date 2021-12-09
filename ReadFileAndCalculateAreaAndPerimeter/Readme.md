### **Fullname:**  

Phạm Huy Cường Thịnh

### **Student's ID:**

 20127335

### **Any notice on how to compile and run my project?**

- Compiler: g++ 8.1.0 version

- Text editor: Visual Studio Code

- Operating system: Windows 11 version 21H2

I also compiled and run my project on Visual Studio Community 2019 version and work perfectly.


### **What I have done:**

I have created 5 classes for this homework.

- Class **Shape** is the base class for all other classes. It has a virtual function **printAllInformation()** which is used to print all information of the shape.

- Class **Rectangle** is derived from class **Shape**. The class has 2 private variables: **_width** and **_height**, a constructor with parameters **length** and **width**. Getter and Setter methods are also declared. It has 2 functions **getArea()** and **getPerimeter()** which are used to calculate the area and the perimeter of the rectangle. It also has a function **printAllInformation()** which is used to print all information of the rectangle.

- Class **Circle** is derived from class **Shape**. The class has 1 private variable: **_radius**, a constructor with parameter **radius**. Getter and Setter methods are also declared. It has 2 functions **getArea()** and **getPerimeter()** which are used to calculate the area and the perimeter of the circle. It also has a function **printAllInformation()** which is used to print all information of the circle.

- Class **Triangle** is derived from class **Shape**. The class has 3 private variables: **_side1**, **_side2** and **_side3**, a constructor with parameters **side1**, **side2** and **side3**. Getter and Setter methods are also declared. It has 2 functions **getArea()** and **getPerimeter()** which are used to calculate the area and the perimeter of the triangle. It also has a function **printAllInformation()** which is used to print all information of the triangle.

- Class **ShapeFileIO** is used to read the file and store the information of the shapes into the vector of shapes. It has a function **readFile()** which is used to read the file and store the information of the shapes into the vector of shapes.

In the main function, I created a vector of shapes and read the file. Then I used a for loop to print all information of the shapes. Finally
I used a for loop to delete all the shapes in the vector in order to prevent memory leak.

### **What I have not done:**

None.

### **What should be taken into account for a bonus?**

None.

### **Expected grade:**

10.0🥰
