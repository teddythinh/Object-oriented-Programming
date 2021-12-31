## **FULLNAME:**  

Phạm Huy Cường Thịnh

## **STUDENT'S ID:**

 20127335

## **ANY NOTICE ON HOW TO COMPILE AND RUN MY PROJECT ?**

- [x] Compiler: g++ 11.2.0 version

- [x] Text editor: Visual Studio Code

- [x] Operating system: Windows 11 version 21H2

- [x] C++ version: C++20 (You have to run with C++17 version or higher version or else you cannot compile my project)

I also compiled and run my project on Visual Studio 2022 version and work perfectly.

## **WHAT I HAVE DONE:**

`READING TIME: 2 MIN READ`

I created 7 classes for this project. I used singleton design pattern in the factory design pattern. I also used prototype design pattern to create a prototype of objects. This project also use polymorphism to create a list of objects so I used smart pointer to create a list of objects to prevent memory leak.

<img src="https://lh3.googleusercontent.com/proxy/xA8svpDeO-KtpsNWLA_cvlqn5Ytj3o8zj6ZjuSFLwWhE6_LFanVIL9dkINQYxCrXcRVWsVpmg5-jDQzjCgsVyZfDOV2-0NDbnzN84oHMaYbQOfyy6c2gT5TEjpIMDCJ9RDtE6DW29Gc4L-U" width="400" height="300" /> <img src="https://i1.wp.com/blogs.perficient.com/files/2020/01/Singleton-Pattern-Image.png?resize=640%2C419&ssl=1" width="400" height="300" />
<img src="https://topdev.vn/blog/wp-content/uploads/2021/04/prototype-design-pattern-image-3.png" width="400" height="300" /> 
<img src="https://csharpcorner-mindcrackerinc.netdna-ssl.com/UploadFile/db2972/builder-design-pattern-from-intent-to-implementation/Images/image2.png" width="400" height="300" /> 

- I created the class **Employee** which is the base class of all other classes: **DailyEmployee**, **HourlyEmployee**, **ProductEmployee** and **Manager**.

- The class **EmployeeFactory** is the factory design pattern which is used to create objects of classes. I also use the singleton design pattern to create a single object of this class. This class also have prototype design pattern to create a prototype of objects.

- The class **EmployeeFileIO** used to read the file, use the factory design pattern to create objects of classes and use the vector to store the employees.

In the main function, I called the factory to create objects of classes and use the vector to store the employees. After that, I called the class **EmployeeFileIO** to read the file and print all the information of employees and calculated the total salary of all employees.

## **WHAT I HAVE NOT DONE:**

None.

## **WHAT SHOULD BE TAKEN INTO ACCOUNT FOR A BONUS ?**

- [x]  Singleton
  
- [x]  Factory

- [x]  Prototype
  
- [x]  Builder

## **EXPECTED GRADES:**

10.0

## **VIDEO DEMO LINK:**

[Youtube](https://youtu.be/4x8ddQUSVLE)

Link if you can not press the above button: [https://youtu.be/4x8ddQUSVLE](https://youtu.be/4x8ddQUSVLE)

## **CLASS DIAGRAM:**

![EmployeeSalaryClassDiagram](https://user-images.githubusercontent.com/85171754/147831832-6645ea79-79aa-4236-b6d1-3dda2a15e574.png)
