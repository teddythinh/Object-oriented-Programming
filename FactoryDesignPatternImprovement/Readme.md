## **FULLNAME:**  

Phạm Huy Cường Thịnh

## **STUDENT'S ID:**

 20127335

## **ANY NOTICE ON HOW TO COMPILE AND RUN MY PROJECT ?**

- [x] Compiler: g++ 8.1.0 version

- [x] Text editor: Visual Studio Code

- [x] Operating system: Windows 11 version 21H2

- [x] C++ version: C++20

I also compiled and run my project on Visual Studio Community 2019 version and work perfectly.

## **WHAT I HAVE DONE:**

`READING TIME: 3 MIN READ`

I have created 6 classes for this homework. I used singleton design pattern in the factory design pattern. I also used pool design pattern to create a pool of objects and prototype design pattern to create a prototype of objects. This homework also use polymorphism to create a list of objects so I used smart pointer to create a list of objects to prevent memory leak.

- Class **Shape** is the abstract class for all other classes. It has a virtual function **toString()** which is used to print all information of the shape. A function **setShape()** which is used to set all information of the shape. And 2 functions **magicWord()** to print the name of the shape, **clone()** to clone the shape.

- Class **Rectangle** is derived from class **Shape**. The class has 2 private variables: **_width** and **_height**, a constructor with parameters **length** and **width**. Getter and Setter methods are also declared. It has 2 functions **getArea()** and **getPerimeter()** which are used to calculate the area and the perimeter of the rectangle. It also has a function **toString()** which is used to print all information of the rectangle. It has a function **magicWord()** which is used to print the name of the rectangle. It has a function **clone()** which is used to clone the rectangle.

- Class **Circle** is derived from class **Shape**. The class has 1 private variable: **_radius**, a constructor with parameter **radius**. Getter and Setter methods are also declared. It has 2 functions **getArea()** and **getPerimeter()** which are used to calculate the area and the perimeter of the circle. It also has a function **toString()** which is used to print all information of the circle. It has a function **magicWord()** which is used to print the name of the circle. It has a function **clone()** which is used to clone the circle.

- Class **Triangle** is derived from class **Shape**. The class has 3 private variables: **_side1**, **_side2** and **_side3**, a constructor with parameters **side1**, **side2** and **side3**. Getter and Setter methods are also declared. It has 2 functions **getArea()** and **getPerimeter()** which are used to calculate the area and the perimeter of the triangle. It also has a function **toString()** which is used to print all information of the triangle. It has a function **magicWord()** which is used to print the name of the triangle. It has a function **clone()** which is used to clone the triangle.

- Class **ShapeFactory** is the factory design pattern. I used singleton design pattern to create a single object of the class. It has a function **getShape()** which is used to create a new object of the class. Function **getInstance()** is created to create a single object of the class. I also used pool design pattern to create a pool of objects and prototype design pattern to create a prototype of objects. Finally a function **printAll()** is used to print all information of all shapes.

- Class **ShapeFileIO** is used to read the file and store the information of the shapes into the vector of shapes. It has a function **readFile()** which is used to read the file and store the information of the shapes into the vector of shapes.

In the main function, I called the factory design pattern to create a single object of the class. I created a vector of shapes and called the function **readFile()** to read the file and store the information of the shapes into the vector of shapes. I then called the function **printAll()** to print all information of all shapes.

## **WHAT I HAVE NOT DONE:**

None.

## **WHAT SHOULD BE TAKEN INTO ACCOUNT FOR A BONUS ?**

None.

## **EXPECTED GRADES:**

10.0
